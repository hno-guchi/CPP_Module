/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CanonicalFormTemp.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/25 11:34:46 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CanonicalFormTemp.hpp"

// CONSTRUCTER
CanonicalFormTemp::CanonicalFormTemp()
{
	debugMessage("CanonicalFormTemp", DEFAULT_CONSTRUCT);
}

CanonicalFormTemp::CanonicalFormTemp() :
{
	debugMessage("CanonicalFormTemp", DEFAULT_CONSTRUCT);
}

CanonicalFormTemp::CanonicalFormTemp(const CanonicalFormTemp& src)
{
	debugMessage("CanonicalFormTemp", COPY_CONSTRUCT);
	this->operator=(src);
}

// OPERATOR
CanonicalFormTemp&	CanonicalFormTemp::operator=(const CanonicalFormTemp& rhs)
{
	debugMessage("CanonicalFormTemp", COPY_OPERATOR);
	return (*this);
}

// GETTER

// SETTER

// SUBJECT FUNC

// DESTRUCTER
CanonicalFormTemp::~CanonicalFormTemp()
{
	debugMessage("CanonicalFormTemp", DESTRUCT);
}
