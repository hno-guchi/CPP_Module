/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguch@42tokyo.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:51:17 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/17 14:02:24 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include "color.hpp"

class BitcoinExchange {
private:
	// std::ifstream					fd_;
	std::string							fileName_;
	std::tm*							beginTime_;
	// std::map<size_t, std::string>	delimiterList_;
	std::map<size_t, std::string>	csvHeader_;
	// std::map<std::string, double>	csvRecord_;

public:
	// CONSTRUCTOR
	BitcoinExchange(const std::string& fileName = "data.csv");
	// BitcoinExchange(const BitcoinExchange& src);
	// DESTRUCTOR
	~BitcoinExchange();
	// OPERATOR
	// BitcoinExchange&	operator=(const BitcoinExchange& rhs);
	// GETTER
	// const std::string&		getFileName() const;
	// const std::ifstream&	getFd() const;
	// SETTER
#ifdef TEST
	// GETTER
	const std::map<size_t, std::string>	getCsvHeader() const;
	void	validationDate(const std::string& date) const;
	void	parseLine(std::string line, const std::string& delimiter) const;
	void	setHeader(std::string line, const std::string& delimiter);
#endif // TEST

	// EXCEPTION
	class FatalErr : public std::logic_error {
	public:
		FatalErr(const std::string& msg = "Fatal error.");
	};
	class ValidErr : public std::logic_error {
	public:
		ValidErr(const std::string& msg = "Validation error.");
	};
};

#endif
