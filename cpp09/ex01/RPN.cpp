/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/10 17:47:17 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "debugMessage.hpp"

// debug
// static void	printBuff(const std::deque<long>& buf);

const std::string	RPN::operations_ = "+-/*";

// CONSTRUCTER
RPN::RPN()
{
#ifdef DEBUG
	debugMessage("RPN", DEFAULT_CONSTRUCT);
#endif // DEBUG
}

// DESTRUCTER
RPN::~RPN()
{
#ifdef DEBUG
	debugMessage("RPN", DESTRUCT);
#endif // DEBUG
}

static void	multiplication(std::deque<long>& buf)
{
	long	b = buf.front();
	buf.pop_front();
	long	a = buf.front();
	buf.pop_front();
	long	result = a * b;
	if (result < INT_MIN || INT_MAX < result) {
		throw RPN::OverInt();
	}
	buf.push_front(result);
}

static void	division(std::deque<long>& buf)
{
	long	b = buf.front();
	buf.pop_front();
	long	a = buf.front();
	buf.pop_front();
	if (b == 0) {
		throw RPN::InvalidArg("Occurs Zero division.");
	}
	long	result = a / b;
	if (result < INT_MIN || INT_MAX < result) {
		throw RPN::OverInt();
	}
	buf.push_front(result);
}

static void	subtraction(std::deque<long>& buf)
{
	long	b = buf.front();
	buf.pop_front();
	long	a = buf.front();
	buf.pop_front();
	long	result = a - b;
	if (result < INT_MIN || INT_MAX < result) {
		throw RPN::OverInt();
	}
	buf.push_front(result);
}

static void	addition(std::deque<long>& buf)
{
	long	b = buf.front();
	buf.pop_front();
	long	a = buf.front();
	buf.pop_front();
	long	result = a + b;
	if (result < INT_MIN || INT_MAX < result) {
		throw RPN::OverInt();
	}
	buf.push_front(result);
}

static void	calculate(const char operation, std::deque<long>& buff)
{
	if (buff.size() < 2) {
		throw RPN::InvalidArg("Not enough numbers.");
	}
	try {
		switch (operation) {
			case '+':
				addition(buff);
				break;
			case '-':
				subtraction(buff);
				break;
			case '/':
				division(buff);
				break;
			case '*':
				multiplication(buff);
				break;
			default:
				throw RPN::InvalidArg("Wrong operation.");
		}
	}
	catch(const std::exception& e) {
		throw ;
	}
}

static std::string	getToken(std::string& str, std::string::iterator& itr, const std::locale& l)
{
	std::string	token;

	for (; !std::isspace(*itr, l); itr++) {
		token += static_cast<char>(*itr);
		if ((itr + 1) == str.end()) {
			break ;
		}
	}
	if (token.size() != 1) {
		throw RPN::InvalidArg("Only use 0 ~ 9 or +, -, *, /.");
	}
	return (token);
}

// SUBJECT FUNC
void	RPN::execute(std::string str) const
{
	if (str.empty()) {
		throw RPN::InvalidArg("Empty argument.");
	}

	std::deque<long>	buff;
	std::locale			l = std::locale::classic();
	try {
		for (std::string::iterator itr = str.begin(); itr != str.end(); itr++) {
			if (std::isspace(*itr, l)) {
				continue ;
			}

			std::string	token = getToken(str, itr, l);

			if (std::isdigit(static_cast<char>(token[0]), l)) {
				buff.push_front(static_cast<char>(token[0]) - '0');
			}
			else if (this->operations_.find(token[0]) != this->operations_.npos) {
				calculate(static_cast<char>(token[0]), buff);
			}
			else {
				throw RPN::InvalidArg("Non digit or operations(+-*/).");
			}
		}
		if (buff.size() != 1) {
			throw RPN::InvalidArg("Wrong format.");
		}
	}
	catch (const std::exception& e) {
		throw ;
	}
	// printBuff(buff);
	std::cout << buff.front() << std::endl;
}

// EXCEPTION
RPN::InvalidArg::InvalidArg(const std::string& msg) : std::invalid_argument(msg) {}
RPN::OverInt::OverInt(const std::string& msg) : std::out_of_range(msg) {}

// debug
// static void	printBuff(const std::deque<long>& buf)
// {
// 	if (buf.empty()) {
// 		return ;
// 	}
// 	long	i = 0;
// 	for (std::deque<long>::const_iterator itr = buf.begin(); itr != buf.end(); itr++) {
// 		std::cout << "[" << i << "]" << std::flush;
// 		if ((itr + 1) != buf.end()) {
// 			std::cout << " -> " << std::flush;
// 		}
// 		i += 1;
// 	}
// 	std:: cout << std::endl;
// 	for (std::deque<long>::const_iterator itr = buf.begin(); itr != buf.end(); itr++) {
// 		std::cout << "[" << *itr << "]" << std::flush;
// 		if ((itr + 1) != buf.end()) {
// 			std::cout << " -> " << std::flush;
// 		}
// 	}
// 	std:: cout << std::endl;
// }
