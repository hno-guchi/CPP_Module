/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguch@42tokyo.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:51:17 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/12/15 14:28:38 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <stdexcept>
#include "./color.hpp"

class BitcoinExchange {
 private:
	std::string						fileName_;
	std::tm*						beginTime_;
	std::list<std::string>			header_;
	std::list<std::map<size_t, std::string> >	records_;

 public:
	// CONSTRUCTOR
	explicit BitcoinExchange(const std::string& fileName = "data.csv");
	// BitcoinExchange(const BitcoinExchange& src);
	// DESTRUCTOR
	~BitcoinExchange();
	// OPERATOR
	// BitcoinExchange&	operator=(const BitcoinExchange& rhs);
	// GETTER
	// const std::string&		getFileName() const;
	// const std::ifstream&	getFd() const;
	// SETTER
	// EXCEPTION
	class FatalErr : public std::logic_error {
	public:
		explicit FatalErr(const std::string& msg = "Fatal error.");
	};
	class ValidErr : public std::logic_error {
	public:
		explicit ValidErr(const std::string& msg = "Validation error.");
	};
#ifdef TEST
	// GETTER
	const std::map<size_t, std::string>	getCsvHeader() const;
	void	validationDate(const std::string& date) const;
	void	parseLine(std::string line, const std::string& delimiter) const;
	void	setHeader(std::string line, const std::string& delimiter);
	void	setCsvData(const std::string& fileName);
#endif  // TEST
};

#endif
