/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/10 14:26:41 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "debugMessage.hpp"

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

static void	printBuff(const std::deque<int>& buf)
{
	if (buf.empty()) {
		return ;
	}
	int	i = 0;
	for (std::deque<int>::const_iterator itr = buf.begin(); itr != buf.end(); itr++) {
		std::cout << "[" << i << "]" << std::flush;
		if ((itr + 1) != buf.end()) {
			std::cout << " -> " << std::flush;
		}
		i += 1;
	}
	std:: cout << std::endl;
	for (std::deque<int>::const_iterator itr = buf.begin(); itr != buf.end(); itr++) {
		std::cout << "[" << *itr << "]" << std::flush;
		if ((itr + 1) != buf.end()) {
			std::cout << " -> " << std::flush;
		}
	}
	std:: cout << std::endl;
}

static void	multiplication(std::deque<int>& buf)
{
	int	a = buf.front();
	buf.pop_front();
	int	b = buf.front();
	buf.pop_front();
	int	result = a * b;
	buf.push_front(result);
}

static void	division(std::deque<int>& buf)
{
	int	a = buf.front();
	buf.pop_front();
	int	b = buf.front();
	buf.pop_front();
	int	result = a / b;
	buf.push_front(result);
}

static void	subtraction(std::deque<int>& buf)
{
	int	a = buf.front();
	buf.pop_front();
	int	b = buf.front();
	buf.pop_front();
	int	result = a - b;
	buf.push_front(result);
}

static void	addition(std::deque<int>& buf)
{
	int	a = buf.front();
	buf.pop_front();
	int	b = buf.front();
	buf.pop_front();
	int	result = a + b;
	buf.push_front(result);
}

// SUBJECT FUNC
void	RPN::execute(std::string str) const
{
	if (str.empty()) {
		throw RPN::InvalidArg("Empty argument.");
	}

	std::deque<int>	buff;
	std::locale		l = std::locale::classic();
	for (std::string::iterator itr = str.begin(); itr != str.end(); itr++) {
		if (!std::isspace(*itr, l)) {
			std::string				token; 
			// getToken(*itr, token);
			std::string::iterator	tokenItr = itr;
			for (; !std::isspace(*tokenItr, l); tokenItr++) {
				token += static_cast<char>(*tokenItr);
				if ((tokenItr + 1) == str.end()) {
					break ;
				}
			}
			// validationToken(token)
			if (token.size() != 1) {
				throw RPN::InvalidArg("Only use 0 ~ 9.");
			}
			if (std::isdigit(static_cast<char>(token[0]), l)) {
				buff.push_front(static_cast<char>(token[0]) - '0');
			}
			else if (this->operations_.find(token) != this->operations_.npos) {
				if (buff.size() < 2) {
					throw RPN::InvalidArg("Not enough numbers.");
				}
				// calculate(static_cast<char>(this->operations_.find(token)), buff);
				switch (static_cast<char>(token[0])) {
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
			else {
				throw RPN::InvalidArg("Non digit or operations(+-*/).");
			}
			itr = tokenItr;
		}
	}
	if (buff.size() != 1) {
		throw RPN::InvalidArg("Wrong format.");
	}
	printBuff(buff);
}

// EXCEPTION
RPN::InvalidArg::InvalidArg(const std::string& msg) : std::invalid_argument(msg) {}
