#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <locale>
#include <deque>
#include <algorithm>
#include <stdexcept>
#include <string>

#ifdef DEBUG
#define long int
#endif  // DEBUG

class RPN {
 private:
	 static const std::string	operations_;

	 static long	multiplication(long a, long b);
	 static long	division(long a, long b);
	 static long	subtraction(long a, long b);
	 static long	addition(long a, long b);
	 static long	getNumber(std::deque<long>* buf);
	 static void	calculate(const char operation, std::deque<long>* buf);
	 static char	getToken(const std::string& str, std::string::const_iterator& it, const std::locale l);

	 // CONSTRUCTOR & DESUTRUCTOR
	 RPN();
	 ~RPN();

	 // DEBUG
	 void	printBuff(const std::deque<long>& buf);

 public:
	 // MEMBER FUNCTION
	 static void	execute(const std::string& str);
	 // DEBUG CALUCULATE_TEST
	 // static long	multiplication(long a, long b);
	 // static long	division(long a, long b);
	 // static long	subtraction(long a, long b);
	 // static long	addition(long a, long b);
};

#endif
