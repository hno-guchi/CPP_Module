#include "./BitcoinExchange.hpp"

static std::tm*	getTime() {
	std::time_t	current = std::time(NULL);
	if (current == -1) {
		throw BitcoinExchange::FatalErr("Failed std::time().");
	}

	std::tm*	ptr = std::localtime(&current);
	if (ptr == NULL) {
		throw BitcoinExchange::FatalErr("Failed std::localtime().");
	}
	return (ptr);
}

// CONSTRUCTOR & DESTRUCTOR
BitcoinExchange::BitcoinExchange(const std::string& fileName) : Csv(fileName) {}
BitcoinExchange::~BitcoinExchange() {}

#ifdef TEST
void	BitcoinExchange::validationDate(const std::string& date) const
#else
static void	validationDate(const std::string& date)
#endif // TEST
{
	std::istringstream	iss(date);
	int					year(0);
    char				delimiter;

	if (!(iss >> year)) {
		throw BitcoinExchange::ValidErr("Bad date format.");
	}
	if (!(iss >> delimiter) || delimiter != '-') {
		throw BitcoinExchange::ValidErr("Bad date format.");
	}

	int	month(0);
	if (!(iss >> month)) {
		throw BitcoinExchange::ValidErr("Bad date format.");
	}
	if (!(iss >> delimiter) || delimiter != '-') {
		throw BitcoinExchange::ValidErr("Bad date format.");
	}

	int	day(0);
	if (!(iss >> day)) {
		throw BitcoinExchange::ValidErr("Bad date format.");
	}

	if (year < 2009 || month < 1 || day < 1) {
		throw BitcoinExchange::ValidErr("Bad date format.");
	}
	if (12 < month) {
		throw BitcoinExchange::ValidErr("Bad date format.");
	}
	// isOverBeginTime
	if ((1900 + this->beginTime_->tm_year) < year) {
		throw BitcoinExchange::ValidErr("Bad date format.");
	}
	if ((1900 + this->beginTime_->tm_year) == year && (1 + this->beginTime_->tm_mon) < month) {
		throw BitcoinExchange::ValidErr("Bad date format.");
	}
	if ((1900 + this->beginTime_->tm_year) == year && (1 + this->beginTime_->tm_mon) == month && this->beginTime_->tm_mday < day) {
		throw BitcoinExchange::ValidErr("Bad date format.");
	}

	// isOverLastDay
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (30 < day) {
			throw BitcoinExchange::ValidErr("Bad date format.");
		}
	}
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (31 < day) {
			throw BitcoinExchange::ValidErr("Bad date format.");
		}
	}
	if (month == 2) {
		if (year % 4 != 0) {
			if (28 < day) {
				throw BitcoinExchange::ValidErr("Bad date format.");
			}
		}
		else if (year % 100 != 0) {
			if (29 < day) {
				throw BitcoinExchange::ValidErr("Bad date format.");
			}
		}
		else if (year % 400 != 0) {
			if (28 < day) {
				throw BitcoinExchange::ValidErr("Bad date format.");
			}
		}
		else {
			if (29 < day) {
				throw BitcoinExchange::ValidErr("Bad date format.");
			}
		}
	}
    std::cout << "Year: " << year << ", Month: " << month << ", Day: " << day << std::endl;
}

static void	getField(std::string& field, std::string& line, const std::string& delimiter)
{
	if (line.empty()) {
		throw BitcoinExchange::ValidErr("Empty field.");
		// return ;
	}
	try {
		// if (line == delimiter) {
		// 	throw BitcoinExchange::ValidErr("Bad line format.");
		// }
		size_t	pos = line.find(delimiter);
		if (pos == std::string::npos) {
			field = line.substr(0);
			line = "";
		}
		// else if (pos == 0) {
		// 	throw BitcoinExchange::ValidErr("Bad line format.");
		// }
		else if (pos == line.size() - delimiter.size()) {
			throw BitcoinExchange::ValidErr("Bad line format.");
		}
		else {
			field = line.substr(0, pos);
			line = line.substr(pos + delimiter.size());
		}
		// if (line == delimiter) {
		// 	throw BitcoinExchange::ValidErr("Bad line format.");
		// }

		if (field.empty()) {
			throw BitcoinExchange::ValidErr("Empty field.");
		}

		if (field.find(' ') != std::string::npos) {
			throw BitcoinExchange::ValidErr("Bad field format.");
		}
	}
	catch (const std::exception& e) {
		throw ;
	}
}

#ifdef TEST
void	BitcoinExchange::parseLine(std::string line, const std::string& delimiter) const
#else
static void	parseLine(std::string line, const std::string& delimiter)
#endif // TEST
{
	std::string	date("");
	std::string	strValue("");

	try {
		// TODO: refactoring
		getField(date, line, delimiter);
		getField(strValue, line, delimiter);
		if (!line.empty()) {
			throw BitcoinExchange::ValidErr("Bad line format.");
		}
		double	doubleValue(0.0);
		// getValue(doubleValue, strValue);
		std::istringstream	iss(strValue);
		if (!(iss >> doubleValue)) {
			throw BitcoinExchange::ValidErr("Bad value.");
		}
		if (!iss.eof()) {
			throw BitcoinExchange::ValidErr("Bad format.");
		}
		if (doubleValue < 0) {
			throw BitcoinExchange::ValidErr("not a positive number.");
		}
		// if (delimiter == " | ") {
		// 	if (1000 < valueDouble) {
		// 		throw BitcoinExchange::ValidErr("too large a number.");
		// 	}
		// }
		std::map<std::string, double>	dateValueMap;
		dateValueMap[date] = doubleValue;
		std::cout << date << ": [" << GREEN << dateValueMap[date] << END << "]" << std::endl;
		// std::map<std::string, std::tm>	dateTmMap;
	}
	catch (const std::exception& e) {
		throw ;
	}
}

#ifdef TEST
void	BitcoinExchange::setHeader(std::string line, const std::string& delimiter)
#else
static void	setHeader(std::string line, const std::string& delimiter)
#endif // TEST
{
	size_t		i(0);
	std::string	field("");
	try {
		while (!line.empty()) {
			getField(field, line, delimiter);
			this->csvHeader_[i] = field;
			i += 1;
			// std::cout << field << std::endl;
		}
	}
	catch (const std::exception& e) {
		throw ;
	}
}

#ifdef TEST
void	BitcoinExchange::setCsvData(const std::string& fileName)
#else
void	setCsvData(const std::string& fileName)
#endif // TEST
{
	try {
		std::ifstream	fd(fileName);

		if (fd.fail() || fd.eof()) {
			throw BitcoinExchange::FatalErr("Failed std::ifstream().");
		}
		std::string		line("");
		if (this->isHeader_) {
			std::getline(fd, line, '\n');
			if (fd.fail()) {
				throw BitcoinExchange::FatalErr("Failed std::getline().");
			}
			this->setHeader(line, ",");
		}
		if (this->csvHeader_.size() != this->countField_) {
			throw BitcoinExchange::ValidErr("Bad header format.");
		}
		// while (std::getline(fd, line, '\n')) {
		// 	std::map<size_t, std::string> fields;
		// 	tokenize(fields, line, ",");
		// 	parseFields(fields);
		// 	addData(fields);
		// }
	}
	catch (const std::exception& e) {
		throw ;
	}
}

// EXCEPTION
BitcoinExchange::ValidErr::ValidErr(const std::string& msg) : std::logic_error(msg) {}
BitcoinExchange::FatalErr::FatalErr(const std::string& msg) : std::logic_error(msg) {}

# ifdef TEST
// GETTER
const std::map<size_t, std::string>	BitcoinExchange::getCsvHeader() const
{
	return (this->csvHeader_);
}
#endif // TEST
