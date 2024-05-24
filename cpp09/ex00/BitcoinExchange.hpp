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
	 const std::string			fileName_;
	 const std::string			delimiter_;
	 const std::string			dateFormat_;
	 time_t						beginTime_;
	 std::map<time_t, float>	records_;

	 bool			isValue(const std::string &str);
	 time_t			getUnixTimeStampFromStructTm(struct tm* tm);
	 time_t			getUnixTimeStampFromStr(const std::string& str);
	 float			getFloatFromStr(const std::string& str);
	 void			setRecords(std::ifstream* fd, const std::string& delimiter);
	 std::string	getDateFromLine(const std::string& line);
	 float			getValueFromLine(const std::string& line);
	 float			getRateFromDate(const std::string& dateStr);
	 void			printResult(const std::string& date, const float value, const float rate);
	 // DEBUG
	 std::string	getDateStrFromUnixTimeStamp(const time_t date) const;

 public:
	 // CONSTRUCTOR & DESTRUCTOR
	 explicit BitcoinExchange(const std::string& fileName = "data.csv");
	 ~BitcoinExchange();

	 // GETTER & SETTER
	 const std::string&				getFileName() const;
	 const std::string&				getDelimiter() const;
	 const std::map<time_t, float>&	getRecords() const;

	 // MEMBER FUNCTION
	 void	printResults(const std::string& fileName);
	 // DEBUG
	 void	debugPrint() const;

// EXCEPTION
class ValidErr : public std::logic_error {
 public:
	 explicit ValidErr(const std::string& msg = "valid error.");
};
};

void	fatalError(const std::string& msg);

#endif
