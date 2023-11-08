/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/08 18:39:53 by hnoguchi         ###   ########.fr       */
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
		throw RPN::InvalidArg();
		return ;
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
			// validationToken(token)
			if (token.size() != 1) {
				throw RPN::InvalidArg();
				// return ;
			}
			// if (std::isdigit(static_cast<char>(token[0]), l)) {
			if (std::isdigit(token[0], l)) {
				std::cout << "token: [" << token << "] | size: [" << token.size() << "] | type: [digit]" << std::endl;
			}
			else {
				std::cout << "token: [" << token << "] | size: [" << token.size() << "] | type: [operator]" << std::endl;
			}
			itr = tokenItr;
		}
	}
}

// EXCEPTION
RPN::InvalidArg::InvalidArg(const std::string& msg) : std::invalid_argument(msg) {}
