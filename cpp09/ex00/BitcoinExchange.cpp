/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:48:41 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/16 11:05:19 by hnoguchi         ###   ########.fr       */
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

// static void	validationDate(const std::string& date)
void	BitcoinExchange::validationDate(const std::string& date)
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

// static void	parseLine(const std::string& line)
void	BitcoinExchange::parseLine(const std::string& line)
{
	std::istringstream				iss(line);
	std::string						date;

	if (!std::getline(iss, date, ',')) {
		throw BitcoinExchange::ValidErr("Failed std::getline().");
	}
	try {
		// validationValue(iss);
		double	value;
		if (!(iss >> value)) {
			throw BitcoinExchange::ValidErr("Bad value.  => " + line);
		}
		if (!iss.eof()) {
			throw BitcoinExchange::ValidErr("Bad format. => " + line);
		}
		if (value < 0) {
			throw BitcoinExchange::ValidErr("not a positive number.");
		}
		// if (1000 < value) {
		// 	throw BitcoinExchange::ValidErr("too large a number.");
		// }
		// validationDate(date);
		std::map<std::string, double>	dateValueMap;
		dateValueMap[date] = value;
		std::cout << date << ": [" << GREEN << dateValueMap[date] << END << "]" << std::endl;
		// std::map<std::string, std::tm>	dateTmMap;
	}
	catch (const std::exception& e) {
		throw ;
	}
}

// EXCEPTION
BitcoinExchange::ValidErr::ValidErr(const std::string& msg) : std::logic_error(msg) {}
BitcoinExchange::FatalErr::FatalErr(const std::string& msg) : std::logic_error(msg) {}
