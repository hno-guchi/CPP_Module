/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/08 10:26:23 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "debugMessage.hpp"

// CONSTRUCTER
// RPN::RPN()
// {
// 	debugMessage("RPN", DEFAULT_CONSTRUCT);
// }

RPN::RPN(const std::string& str)
{
	(void)str;
	debugMessage("RPN", HAS_ARG_CONSTRUCT);
}

RPN::RPN(const RPN& src)
{
	debugMessage("RPN", COPY_CONSTRUCT);
	this->operator=(src);
}

// DESTRUCTER
RPN::~RPN()
{
	debugMessage("RPN", DESTRUCT);
}

// OPERATOR
RPN&	RPN::operator=(const RPN& rhs)
{
	if (this == &rhs) {
		return (*this);
	}
	debugMessage("RPN", COPY_OPERATOR);
	return (*this);
}

// GETTER

// SETTER

// SUBJECT FUNC

