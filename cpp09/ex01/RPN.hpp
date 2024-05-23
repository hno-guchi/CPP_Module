#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <locale>
#include <deque>
#include <algorithm>
#include <stdexcept>
#include <string>

class RPN {
 private:
	 const std::string	operations_;

	 long	multiplication(long a, long b) const;
	 long	division(long a, long b) const;
	 long	subtraction(long a, long b) const;
	 long	addition(long a, long b) const;
	 long	getNumber(std::deque<long>* buf) const;
	 void	calculate(const char operation, std::deque<long>* buf) const;
	 char	getToken(const std::string& str, std::string::const_iterator& it, const std::locale l) const;

 public:
	 // CONSTRUCTOR & DESUTRUCTOR
	 RPN();
	 ~RPN();
	 // MEMBER FUNCTION
	 void	execute(const std::string& str) const;
// EXCEPTION
class InvalidArg : public std::invalid_argument {
 public:
	 explicit InvalidArg(const std::string& msg = "Invalid argument.");
};
class OverInt : public std::out_of_range {
 public:
	 explicit OverInt(const std::string& msg = "Over INT_MAX or under INT_MIN.");
};
};

#endif
