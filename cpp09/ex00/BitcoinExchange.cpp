#include <stdexcept>
#include <sstream>
#include "./BitcoinExchange.hpp"

void	fatalError(const std::string& msg) {
	std::cerr << RED << "fatal error: " << END << msg << std::endl;
	exit(1);
}

// CONSTRUCTOR & DESTRUCTOR
BitcoinExchange::BitcoinExchange(const std::string& fileName)
	: fileName_(fileName), delimiter_(" | "), dateFormat_("%Y-%m-%d") {
	try {
		std::ifstream	fd(this->fileName_);

		if (fd.fail() || fd.eof()) {
			throw std::runtime_error("Failed std::ifstream()");
		}
		std::string	line("");

		std::getline(fd, line, '\n');
		if (fd.fail()) {
			throw std::runtime_error("Failed std::getline().");
		}
		this->setRecords(&fd, ",");
		fd.close();
		if (!fd.eof() && fd.fail()) {
			throw std::runtime_error("Failed std::ifstream::close().");
		}
	}
	catch (const std::exception& e) {
		throw;
	}
}

BitcoinExchange::~BitcoinExchange() {}

bool	BitcoinExchange::isValue(const std::string &str) {
	if (str.empty()) {
		return (false);
	}
	std::locale					l = std::locale::classic();
	std::string::const_iterator	it = str.begin();
	if (!std::isdigit(*it, l)) {
		return (false);
	}
	it++;
	bool	dot = false;
	for (; it != str.end(); it++) {
		if (*it == '.' && dot) {
			return (false);
		} else if (*it == '.' && (it + 1) == str.end()) {
			return (false);
		} else if (*it == '.') {
			dot = true;
			continue;
		}
		if (!std::isdigit(*it, l)) {
			return (false);
		}
	}
	return (true);
}

time_t	BitcoinExchange::getUnixTimeStampFromStr(const std::string& str) {
	try {
		struct tm	tm;

		std::memset(&tm, 0, sizeof(struct tm));
		if (strptime(str.c_str(), this->dateFormat_.c_str(), &tm) == NULL) {
			throw std::runtime_error("Failed strptime(). => [" + str + "]");
		}
		tm.tm_hour = 0;
		tm.tm_min = 0;
		tm.tm_sec = 0;
		tm.tm_isdst = -1;
		return (std::mktime(&tm));
	} catch (const std::exception& e) {
		throw;
	}
}

float	BitcoinExchange::getFloatFromStr(const std::string& str) {
	try {
		std::stringstream	ss(str);
		float				value;

		ss >> value;
		if (!ss.eof() && ss.fail()) {
			throw std::runtime_error("Failed std::stringstream::operator>>(). => [" + str + "]");
		}
		return (value);
	} catch (const std::exception& e) {
		throw;
	}
}

std::string	BitcoinExchange::getDateStrFromUnixTimeStamp(const time_t date) const {
	try {
		struct tm	*tm = localtime(&date);
		char		buffer[11] = {0};

		if (strftime(buffer, sizeof(buffer)/sizeof(buffer[0]), this->dateFormat_.c_str(), tm) == 0) {
			throw std::runtime_error("Failed strftime().");
		}
		return (std::string(buffer));
	} catch (const std::exception& e) {
		throw;
	}
}

void	BitcoinExchange::setRecords(std::ifstream* fd, const std::string& delimiter) {
	try {
		std::string	line("");

		while (std::getline(*fd, line, '\n')) {
			std::string	dateStr = line.substr(0, line.find(delimiter));
			std::string	valueStr = line.substr(line.find(delimiter) + delimiter.size());

			time_t	date = this->getUnixTimeStampFromStr(dateStr);
			float	value = this->getFloatFromStr(valueStr);
			this->records_[date] = value;
		}
		if (!fd->eof() && fd->fail()) {
			throw std::runtime_error("Failed std::getline().");
		}
	}
	catch (const std::exception& e) {
		throw;
	}
}


// GETTER
const std::string&	BitcoinExchange::getFileName() const {
	return (this->fileName_);
}

const std::string&	BitcoinExchange::getDelimiter() const {
	return (this->delimiter_);
}

const std::map<time_t, float>&	BitcoinExchange::getRecords() const {
	return (this->records_);
}

std::string	BitcoinExchange::getDateFromLine(const std::string& line) {
	try {
		std::string	dateStr = line.substr(0, line.find(this->delimiter_));
		if (dateStr.empty()) {
			throw BitcoinExchange::ValidErr("Empty date.");
		}
		if (line.find(this->delimiter_) == std::string::npos) {
			throw BitcoinExchange::ValidErr("Failed to find delimiter. => [" + dateStr + "]");
		}
		if (line.find(this->delimiter_) + this->delimiter_.size() >= line.size()) {
			throw BitcoinExchange::ValidErr("Failed to find value. => [" + dateStr + "]");
		}
		return (dateStr);
	} catch (const std::exception& e) {
		throw;
	}
}

float	BitcoinExchange::getValueFromLine(const std::string& line) {
	try {
		std::string	valueStr = line.substr(line.find(this->delimiter_) + this->delimiter_.size());
		if (!isValue(valueStr)) {
			throw BitcoinExchange::ValidErr("Exist Not digit char. => [" + valueStr + "]");
		}
		float	value = this->getFloatFromStr(valueStr);
		if (value < 0.0) {
			throw BitcoinExchange::ValidErr("Not a positive number. => [" + valueStr + "]");
		} else if (value > 1000.0) {
			throw BitcoinExchange::ValidErr("Too large a number. => [" + valueStr + "]");
		}
		return (value);
	} catch (const std::exception& e) {
		throw;
	}
}

float	BitcoinExchange::getRateFromDate(const std::string& dateStr) {
	try {
		time_t	date = this->getUnixTimeStampFromStr(dateStr);
		std::map<time_t, float>::const_iterator	it = this->getRecords().lower_bound(date);
		if (it == this->getRecords().end()) {
			throw BitcoinExchange::ValidErr("Date out of range. => [" + dateStr + "]");
		}
		if (it == this->getRecords().begin()) {
			if (date < it->first) {
				throw BitcoinExchange::ValidErr("Date out of range. => [" + dateStr + "]");
			}
		} else if (it->first != date) {
			std::map<time_t, float>::const_iterator	prevIt = it;
			prevIt--;
			if ((it->first - date) > (date - prevIt->first)) {
				it = prevIt;
			}
		}
		return (it->second);
	} catch (const std::exception& e) {
		throw;
	}
}

void	BitcoinExchange::printResult(const std::string& date, const float value, const float rate) {
	try {
		float	result = value * rate;
		std::cout << date << " => " << value << " = " << result << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << "Fatal error: Csv::printResult();" << END << std::endl;
	}
}

// MEMBER FUNCTION
void	BitcoinExchange::printResults(const std::string& fileName) {
	try {
		std::ifstream	fd(fileName.c_str());
		if (!fd.eof() && fd.fail()) {
			fd.close();
			throw std::runtime_error("Failed std::ifstream()");
		}
		if (fd.eof()) {
			fd.close();
			throw std::runtime_error("Empty file.");
		}
		std::string	line("");
		std::getline(fd, line, '\n');
		if (!fd.eof() && fd.fail()) {
			fd.close();
			throw std::runtime_error("Failed std::getline().");
		}
		while (std::getline(fd, line, '\n')) {
			try {
				if (line.empty()) {
					throw BitcoinExchange::ValidErr("Empty line.");
				}
#ifdef DEBUG
				std::cout << "[" << YELLOW << line << END << "]   " << std::flush;
#endif  // DEBUG
				std::string	date = this->getDateFromLine(line);
				float		value = this->getValueFromLine(line);
				float		rate = this->getRateFromDate(date);
				this->printResult(date, value, rate);
			} catch (const std::exception& e) {
				std::cout << RED << "Valid error: " << END << e.what() << std::endl;
				continue;
			}
		}
		if (!fd.eof() && fd.fail()) {
			fd.close();
			throw std::runtime_error("Failed std::getline().");
		}
		fd.close();
		// if (!fd.eof() && fd.fail()) {
		// 	throw std::runtime_error("Failed std::ifstream::close().");
		// }
	} catch (const std::exception& e) {
		throw;
	}
}

// EXCEPTION
BitcoinExchange::ValidErr::ValidErr(const std::string& msg) : std::logic_error(msg) {}

// DEBUG
void	BitcoinExchange::debugPrint() const {
	try {
		std::cout << "date,exchange_rate" << std::endl;
		for (std::map<time_t, float>::const_iterator it = this->records_.begin(); it != this->records_.end(); it++) {
			std::cout << std::fixed << std::setprecision(2);
			std::cout << this->getDateStrFromUnixTimeStamp(it->first) << "," << it->second << std::endl;
		}
	} catch (const std::exception& e) {
		throw;
	}
}
