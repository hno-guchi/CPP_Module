#ifndef CSV_HPP
# define CSV_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "./color.hpp"

class Csv {
 private:
	 const std::string			fileName_;
	 const bool					isHeader_;
	 const std::string			delimiter_;
	 std::map<time_t, float>	records_;

	 void			setRecords(std::ifstream* fd, const std::string& delimiter);

 public:
	 // CONSTRUCTOR & DESTRUCTOR
	 explicit Csv(const std::string& fileName = "data.csv", const bool isHeader = true);
	 ~Csv();
	 // GETTER
	 const std::string&	getFileName() const;
	 bool				getIsHeader() const;
	 const std::string&	getDelimiter() const;

	 time_t				getUnixTimeStampFromStr(const std::string& str);
	 float				getFloatFromStr(const std::string& str);
	 std::string		getDateStrFromUnixTimeStamp(const time_t date) const;
	// DEBUG
	void	debugPrint() const;
};

#endif
