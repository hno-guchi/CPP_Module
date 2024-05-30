#include <stdexcept>
#include <sstream>
#include "./BitcoinExchange.hpp"

// CONSTRUCTOR & DESTRUCTOR
BitcoinExchange::BitcoinExchange(const std::string& fileName)
	: fileName_(fileName), delimiter_(" | "), dateFormat_("%Y-%m-%d") {
	try {
		time_t	now = std::time(NULL);
		if (now < 0) {
			throw std::runtime_error("Failed std::time().");
		}
		time_t	date = this->getUnixTimeStampFromStructTm(std::localtime(&now));
		if (date < 0) {
			throw std::runtime_error("Failed std::localtime().");
		}
		this->beginTime_ = date;

		std::ifstream	fd(this->fileName_);

		if (fd.fail() || fd.eof()) {
			throw std::runtime_error("Failed std::ifstream()");
		}
		std::string	line("");

		std::getline(fd, line);
		if (fd.fail()) {
			throw std::runtime_error("Failed std::getline().");
		}
		this->setRecords(&fd, ",");
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

time_t	BitcoinExchange::getUnixTimeStampFromStructTm(struct tm* tm) {
	try {
		if (tm == NULL) {
			throw std::invalid_argument("Invalid arg getUnixTimeStampFromStructTm().");
		}
		tm->tm_hour = 0;
		tm->tm_min = 0;
		tm->tm_sec = 0;
		tm->tm_isdst = -1;

		time_t	date = std::mktime(tm);

		if (date < 0) {
			throw std::runtime_error("Failed std::mktime().");
		}
		return (date);
	} catch (const std::exception& e) {
		throw;
	}
}

time_t	BitcoinExchange::getUnixTimeStampFromStr(const std::string& str) {
	try {
		struct tm	tm;

		std::memset(&tm, 0, sizeof(struct tm));
		if (strptime(str.c_str(), this->dateFormat_.c_str(), &tm) == NULL) {
			throw std::runtime_error("Failed strptime(). => [" + str + "]");
		}
		time_t	date = this->getUnixTimeStampFromStructTm(&tm);

		if (date > this->beginTime_) {
			throw std::runtime_error("Failed getUnixTimeStampFromStructTm(). => [" + str + "]");
		}
		return (date);
	} catch (const std::exception& e) {
		throw;
	}
}

double	BitcoinExchange::getFloatFromStr(const std::string& str) {
	try {
		std::stringstream	ss(str);
		double				value;

		ss >> value;
		if (!ss.eof() && ss.fail()) {
			throw std::runtime_error("Failed std::stringstream::operator>>(). => [" + str + "]");
		}
		return (value);
	} catch (const std::exception& e) {
		throw;
	}
}

void	BitcoinExchange::setRecords(std::ifstream* fd, const std::string& delimiter) {
	try {
		std::string	line("");

		while (std::getline(*fd, line)) {
			std::string	dateStr = line.substr(0, line.find(delimiter));
			std::string	valueStr = line.substr(line.find(delimiter) + delimiter.size());

			time_t	date = this->getUnixTimeStampFromStr(dateStr);
			double	value = this->getFloatFromStr(valueStr);
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

const std::map<time_t, double>&	BitcoinExchange::getRecords() const {
	return (this->records_);
}

std::string	BitcoinExchange::getDateFromLine(const std::string& line) {
	try {
		if (line.find(this->delimiter_) == std::string::npos) {
			throw std::invalid_argument("Failed to find delimiter. => [" + line + "]");
		}
		if (line.find(this->delimiter_) + this->delimiter_.size() >= line.size()) {
			throw std::invalid_argument("Failed to find value. => [" + line + "]");
		}
		std::string	dateStr = line.substr(0, line.find(this->delimiter_));
		if (dateStr.empty()) {
			throw std::invalid_argument("Empty date.");
		}
		return (dateStr);
	} catch (const std::exception& e) {
		throw;
	}
}

double	BitcoinExchange::getValueFromLine(const std::string& line) {
	try {
		std::string	valueStr = line.substr(line.find(this->delimiter_) + this->delimiter_.size());
		if (!isValue(valueStr)) {
			throw std::invalid_argument("Exist Not digit char. => [" + valueStr + "]");
		}
		double	value = this->getFloatFromStr(valueStr);
		if (value < 0.0) {
			throw std::invalid_argument("Not a positive number. => [" + valueStr + "]");
		} else if (value > 1000.0) {
			throw std::invalid_argument("Too large a number. => [" + valueStr + "]");
		}
		return (value);
	} catch (const std::exception& e) {
		throw;
	}
}

double	BitcoinExchange::getRateFromDate(const std::string& dateStr) {
	try {
		time_t	date = this->getUnixTimeStampFromStr(dateStr);
		std::map<time_t, double>::const_iterator	it = this->getRecords().lower_bound(date);
		if (it == this->getRecords().end()) {
			throw std::out_of_range("Date out of range. => [" + dateStr + "]");
		}
		if (it == this->getRecords().begin()) {
			if (date < it->first) {
				throw std::out_of_range("Date out of range. => [" + dateStr + "]");
			}
		}
		if (it->first != date) {
			it--;
		}
		return (it->second);
	} catch (const std::exception& e) {
		throw;
	}
}

void	BitcoinExchange::printResult(const std::string& date, const double value, const double rate) {
	try {
		double	result = value * rate;
		std::cout << date << " => " << value << " = " << std::flush;
		std::cout << std::fixed << std::setprecision(3);
		std::cout << result << std::endl;
		std::cout << std::defaultfloat << std::setprecision(1);
	} catch (const std::exception& e) {
		std::cout << RED << "Fatal error: Csv::printResult();" << END << std::endl;
	}
}

// MEMBER FUNCTION
void	BitcoinExchange::printResults(const std::string& fileName) {
	try {
		std::ifstream	fd(fileName.c_str());
		if (!fd.eof() && fd.fail()) {
			throw std::runtime_error("Failed std::ifstream()");
		}
		if (fd.eof()) {
			throw std::runtime_error("Empty file.");
		}
		std::string	line("");
		std::getline(fd, line);
		if (!fd.eof() && fd.fail()) {
			throw std::runtime_error("Failed std::getline().");
		}
		while (std::getline(fd, line)) {
			try {
				if (line.empty()) {
					throw std::invalid_argument("Empty line.");
				}
#ifdef DEBUG
				std::cout << "[" << YELLOW << line << END << "]   " << std::flush;
#endif  // DEBUG
				std::string	date = this->getDateFromLine(line);
				double		value = this->getValueFromLine(line);
				double		rate = this->getRateFromDate(date);
				this->printResult(date, value, rate);
			} catch (const std::exception& e) {
				std::cout << RED << "Error: " << END << e.what() << std::endl;
				continue;
			}
		}
		if (!fd.eof() && fd.fail()) {
			throw std::runtime_error("Failed std::getline().");
		}
	} catch (const std::exception& e) {
		throw;
	}
}

// DEBUG
std::string	BitcoinExchange::getDateStrFromUnixTimeStamp(const time_t date) const {
	try {
		if (date < 0) {
			throw std::invalid_argument("Invalid arg getDateStrFromUnixTimeStamp().");
		}
		struct tm	*tm = localtime(&date);
		char		buf[11] = {0};

		if (strftime(buf, sizeof(buf)/sizeof(buf[0]), this->dateFormat_.c_str(), tm) == 0) {
			throw std::runtime_error("Failed strftime().");
		}
		return (std::string(buf));
	} catch (const std::exception& e) {
		throw;
	}
}

void	BitcoinExchange::debugPrint() const {
	try {
		std::cout << "date,exchange_rate" << std::endl;
		for (std::map<time_t, double>::const_iterator it = this->records_.begin(); it != this->records_.end(); it++) {
			std::cout << std::fixed << std::setprecision(2);
			std::cout << this->getDateStrFromUnixTimeStamp(it->first) << "," << it->second << std::endl;
		}
	} catch (const std::exception& e) {
		throw;
	}
}
