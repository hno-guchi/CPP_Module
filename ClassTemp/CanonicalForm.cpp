/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CanonicalForm.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/08 10:26:01 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CanonicalForm.hpp"

// CONSTRUCTER
CanonicalForm::CanonicalForm()
{
	debugMessage("CanonicalForm", DEFAULT_CONSTRUCT);
}

CanonicalForm::CanonicalForm() :
{
	debugMessage("CanonicalForm", HAS_ARG_CONSTRUCT);
}

CanonicalForm::CanonicalForm(const CanonicalForm& src)
{
	debugMessage("CanonicalForm", COPY_CONSTRUCT);
	this->operator=(src);
}

// DESTRUCTER
CanonicalForm::~CanonicalForm()
{
	debugMessage("CanonicalForm", DESTRUCT);
}

// OPERATOR
CanonicalForm&	CanonicalForm::operator=(const CanonicalForm& rhs)
{
	if (this == &rhs) {
		return (*this);
	}
	debugMessage("CanonicalForm", COPY_OPERATOR);
	return (*this);
}

// GETTER

// SETTER

// SUBJECT FUNC

