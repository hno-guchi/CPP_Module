/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/09 16:26:14 by hnoguchi         ###   ########.fr       */
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

// SUBJECT FUNC
void	RPN::execute(std::string str) const
{
	if (str.empty()) {
		throw RPN::InvalidArg();
		return ;
	}
	std::deque<int>	buff;
	std::locale		l = std::locale::classic();
	for (std::string::iterator itr = str.begin(); itr != str.end(); itr++) {
		if (!std::isspace(*itr, l)) {
			std::string	token; 
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
				throw RPN::InvalidArg();
				// return ;
			}
			if (std::isdigit(static_cast<char>(token[0]), l)) {
				switch (static_cast<char>(token[0])) {
					case '0':
						buff.push_front(0);
						break;
					case '1':
						buff.push_front(1);
						break;
					case '2':
						buff.push_front(2);
						break;
					case '3':
						buff.push_front(3);
						break;
					case '4':
						buff.push_front(4);
						break;
					case '5':
						buff.push_front(5);
						break;
					case '6':
						buff.push_front(6);
						break;
					case '7':
						buff.push_front(7);
						break;
					case '8':
						buff.push_front(8);
						break;
					case '9':
						buff.push_front(9);
						break;
					default:
						throw RPN::InvalidArg();
						return ;
				}
			}
			else if (this->operations_.find(token) != this->operations_.npos) {
				switch (static_cast<char>(token[0])) {
					case '+':
						std::cout << "token: [" << token << "] | size: [" << token.size() << "] | type: [operator]" << std::endl;
						break;
					case '-':
						std::cout << "token: [" << token << "] | size: [" << token.size() << "] | type: [operator]" << std::endl;
						break;
					case '/':
						std::cout << "token: [" << token << "] | size: [" << token.size() << "] | type: [operator]" << std::endl;
						break;
					case '*':
						std::cout << "token: [" << token << "] | size: [" << token.size() << "] | type: [operator]" << std::endl;
						break;
					default:
						throw RPN::InvalidArg();
						return ;
				}
			}
			else {
				throw RPN::InvalidArg();
				return ;
			}
			itr = tokenItr;
		}
	}
	printBuff(buff);
}

// EXCEPTION
RPN::InvalidArg::InvalidArg(const std::string& msg) : std::invalid_argument(msg) {}
