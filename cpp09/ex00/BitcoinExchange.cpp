/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:48:41 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/17 15:05:03 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "debugMessage.hpp"

static std::tm*	getTime()
{
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

// CONSTRUCTOR
BitcoinExchange::BitcoinExchange(const std::string& fileName) :
	fileName_(fileName)
{
#ifdef DEBUG
	debugMessage("BitcoinExchange", HAS_ARG_CONSTRUCT);
#endif // DEBUG
	try {
		this->beginTime_ = getTime();
	}
	catch (const std::exception& e) {
		std::cout << RED << e.what() << END << std::endl;
	}
}

BitcoinExchange::~BitcoinExchange()
{
#ifdef DEBUG
	debugMessage("BitcoinExchange", DESTRUCT);
#endif // DEBUG
}

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
		throw BitcoinExchange::ValidErr("Bad date format. => " + date);
	}
	if (!(iss >> delimiter) || delimiter != '-') {
		throw BitcoinExchange::ValidErr("Bad date format. => " + date);
	}

	int	month(0);
	if (!(iss >> month)) {
		throw BitcoinExchange::ValidErr("Bad date format. => " + date);
	}
	if (!(iss >> delimiter) || delimiter != '-') {
		throw BitcoinExchange::ValidErr("Bad date format. => " + date);
	}

	int	day(0);
	if (!(iss >> day)) {
		throw BitcoinExchange::ValidErr("Bad date format. => " + date);
	}

	if (year < 2009 || month < 1 || day < 1) {
		throw BitcoinExchange::ValidErr("Bad date format. => " + date);
	}
	if (12 < month) {
		throw BitcoinExchange::ValidErr("Bad date format. => " + date);
	}
	// isOverBeginTime
	if ((1900 + this->beginTime_->tm_year) < year) {
		throw BitcoinExchange::ValidErr("Bad date format. => " + date);
	}
	if ((1900 + this->beginTime_->tm_year) == year && (1 + this->beginTime_->tm_mon) < month) {
		throw BitcoinExchange::ValidErr("Bad date format. => " + date);
	}
	if ((1900 + this->beginTime_->tm_year) == year && (1 + this->beginTime_->tm_mon) == month && this->beginTime_->tm_mday < day) {
		throw BitcoinExchange::ValidErr("Bad date format. => " + date);
	}

	// isOverLastDay
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (30 < day) {
			throw BitcoinExchange::ValidErr("Bad date format. => " + date);
		}
	}
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (31 < day) {
			throw BitcoinExchange::ValidErr("Bad date format. => " + date);
		}
	}
	if (month == 2) {
		if (year % 4 != 0) {
			if (28 < day) {
				throw BitcoinExchange::ValidErr("Bad date format. => " + date);
			}
		}
		else if (year % 100 != 0) {
			if (29 < day) {
				throw BitcoinExchange::ValidErr("Bad date format. => " + date);
			}
		}
		else if (year % 400 != 0) {
			if (28 < day) {
				throw BitcoinExchange::ValidErr("Bad date format. => " + date);
			}
		}
		else {
			if (29 < day) {
				throw BitcoinExchange::ValidErr("Bad date format. => " + date);
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

/*
 * getCsvData()
 * {
 * try {
 * std::ifstream	fd();
 * std::string		line("");
 *
 * std::getline(fd, line, '\n');
 * tokenize(this->csvHeader_, line, ",");
 * 	if (this->csvHeader_.empty()) {
 * 		throw BitcoinExchange::ValidErr("Empty header.");
 * }
 * if (this->csvHeader_.size() != 2) {
 * 		throw BitcoinExchange::ValidErr("Bad header format.");
 * }
 * while (std::getline(fd, line, '\n')) {
 * std::map<size_t, std::string> fields;
 * tokenize(fields, line, ",");
 * parseFields(fields);
 * addData(fields);
 * }
 * }
 * catch (const std::exception& e) {
 * throw ;
 * }
 */

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
