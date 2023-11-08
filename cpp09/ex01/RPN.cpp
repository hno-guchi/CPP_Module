/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/08 16:30:15 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "debugMessage.hpp"

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

// SUBJECT FUNC
void	RPN::execute(std::string str) const
{
	if (str.empty()) {
		throw RPN::EmptyArg();
	}
	std::locale	l = std::locale::classic();
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
			// if ()
			std::cout << token << std::endl;
			itr = tokenItr;
		}
	}
}

// EXCEPTION
RPN::EmptyArg::EmptyArg(const std::string& msg) : std::invalid_argument(msg) {}
