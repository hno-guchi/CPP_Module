#include <stdexcept>
#include <sstream>
#include "./Csv.hpp"

// CONSTRUCTOR
Csv::Csv(const std::string& fileName, const bool isHeader) : fileName_(fileName), isHeader_(isHeader), delimiter_(",") {
	try {
		std::ifstream	fd(this->fileName_);

		if (fd.fail() || fd.eof()) {
			throw std::runtime_error("Failed std::ifstream()");
		}
		if (this->isHeader_) {
			std::string		line("");

			std::getline(fd, line, '\n');
			if (fd.fail()) {
				throw std::runtime_error("Failed std::getline().");
			}
		}
		this->setRecords(&fd, this->delimiter_);
		fd.close();
		if (!fd.eof() && fd.fail()) {
			throw std::runtime_error("Failed std::ifstream::close().");
		}
	}
	catch (const std::exception& e) {
		throw;
	}
}

Csv::~Csv() {}

// GETTER
const std::string&	Csv::getFileName() const {
	return (this->fileName_);
}

bool	Csv::getIsHeader() const {
	return (this->isHeader_);
}

const std::string&	Csv::getDelimiter() const {
	return (this->delimiter_);
}

time_t Csv::getUnixTimeStampFromStr(const std::string& str) {
	try {
		struct tm	tm;

		std::memset(&tm, 0, sizeof(struct tm));
		if (strptime(str.c_str(), "%Y-%m-%d", &tm) == NULL) {
			throw std::runtime_error("Failed strptime().");
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

float Csv::getFloatFromStr(const std::string& str) {
	try {
		std::stringstream	ss(str);
		float				value;

		ss >> value;
		if (!ss.eof() && ss.fail()) {
			throw std::runtime_error("Failed std::stringstream::operator>>().");
		}
		return (value);
	} catch (const std::exception& e) {
		throw;
	}
}

void	Csv::setRecords(std::ifstream* fd, const std::string& delimiter) {
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

// DEBUG

std::string	Csv::getDateStrFromUnixTimeStamp(const time_t date) const {
	try {
		struct tm	*tm = localtime(&date);
		char		buffer[11] = {0};

		if (strftime(buffer, sizeof(buffer)/sizeof(buffer[0]), "%Y-%m-%d", tm) == 0) {
			throw std::runtime_error("Failed strftime().");
		}
		return (std::string(buffer));
	} catch (const std::exception& e) {
		throw;
	}
}
void	Csv::debugPrint() const {
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

#ifdef CSV_DEBUG
int main() {
	try {
		Csv	csv("data.csv", true);

		csv.debugPrint();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
#endif  // CSV_DEBUG
