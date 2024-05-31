#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
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
	 std::map<time_t, double>	records_;

	 // CONSTRUCTOR & COPY OPERATOR
	 explicit BitcoinExchange(const BitcoinExchange& rhs);
	 BitcoinExchange& operator=(const BitcoinExchange& rhs);

	 bool			isValue(const std::string &str);
	 time_t			getUnixTimeStampFromStructTm(struct tm* tm);
	 time_t			getUnixTimeStampFromStr(const std::string& str);
	 double			getDoubleFromStr(const std::string& str);
	 void			setRecords(std::ifstream* fd, const std::string& delimiter);
	 std::string	getDateFromLine(const std::string& line);
	 double			getValueFromLine(const std::string& line);
	 double			getRateFromDate(const std::string& dateStr);
	 void			printResult(const std::string& date, const double value, const double rate);
	 // DEBUG
	 std::string	getDateStrFromUnixTimeStamp(const time_t date) const;

 public:
	 // CONSTRUCTOR & DESTRUCTOR
	 explicit BitcoinExchange(const std::string& fileName = "data.csv");
	 ~BitcoinExchange();

	 // GETTER & SETTER
	 const std::string&				getFileName() const;
	 const std::string&				getDelimiter() const;
	 const std::map<time_t, double>&	getRecords() const;

	 // MEMBER FUNCTION
	 void	printResults(const std::string& fileName);
	 // DEBUG
	 void	debugPrint() const;
};

#endif
