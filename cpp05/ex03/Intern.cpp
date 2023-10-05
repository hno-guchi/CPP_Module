/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/05 15:26:57 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// CONSTRUCTER
Intern::Intern()
{
	debugMessage("Intern", DEFAULT_CONSTRUCT);
}

Intern::Intern() :
{
	debugMessage("Intern", HAS_ARGS_CONSTRUCT);
}

Intern::Intern(const Intern& src)
{
	debugMessage("Intern", COPY_CONSTRUCT);
	this->operator=(src);
}

// DESTRUCTER
Intern::~Intern()
{
	debugMessage("Intern", DESTRUCT);
}

// OPERATOR
Intern&	Intern::operator=(const Intern& rhs)
{
	if (this == &rhs) {
		return (*this);
	}
	debugMessage("Intern", COPY_OPERATOR);
	return (*this);
}

// GETTER

// SETTER

// SUBJECT FUNC

