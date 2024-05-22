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
#include "./Csv.hpp"

class BitcoinExchange : public Csv {
 private:
	 // std::string						fileName_;
	 // std::tm*						beginTime_;
	 // std::map<time_t, std::string> >	records_;

 public:
	// CONSTRUCTOR & DESTRUCTOR
	explicit BitcoinExchange(const std::string& fileName = "data.csv");
	~BitcoinExchange();
	// GETTER & SETTER
	// const std::string&		getFileName() const;
	// const std::ifstream&	getFd() const;
	// EXCEPTION
	// class FatalErr : public std::logic_error {
	// public:
	// 	explicit FatalErr(const std::string& msg = "Fatal error.");
	// };
	// class ValidErr : public std::logic_error {
	// public:
	// 	explicit ValidErr(const std::string& msg = "Validation error.");
	// };
#ifdef DEBUG
	// const std::map<size_t, std::string>	getCsvHeader() const;
	// void	validationDate(const std::string& date) const;
	// void	parseLine(std::string line, const std::string& delimiter) const;
	// void	setHeader(std::string line, const std::string& delimiter);
	// void	setCsvData(const std::string& fileName);
#endif  // DEBUG
};

void	fatalError(const std::string& msg);

#endif
