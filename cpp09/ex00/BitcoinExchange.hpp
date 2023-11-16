/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguch@42tokyo.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:51:17 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/16 18:38:35 by hnoguchi         ###   ########.fr       */
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
	std::string							fileName_;
	std::tm*							beginTime_;
	// std::ifstream						fd_;
	// std::map<std::string, std::string>	csvDate_;

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
	void	parseLine(std::string line, const std::string& delimiter);
	void	validationDate(const std::string& date);
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
