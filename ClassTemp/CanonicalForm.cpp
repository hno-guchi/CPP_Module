/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CanonicalForm.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/08 14:34:05 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CanonicalForm.hpp"

// CONSTRUCTER
CanonicalForm::CanonicalForm()
{
#ifdef DEBUG
	debugMessage("CanonicalForm", DEFAULT_CONSTRUCT);
#endif // DEBUG
}

CanonicalForm::CanonicalForm() :
{
#ifdef DEBUG
	debugMessage("CanonicalForm", HAS_ARG_CONSTRUCT);
#endif // DEBUG
}

CanonicalForm::CanonicalForm(const CanonicalForm& src)
{
#ifdef DEBUG
	debugMessage("CanonicalForm", COPY_CONSTRUCT);
#endif // DEBUG
	this->operator=(src);
}

// DESTRUCTER
CanonicalForm::~CanonicalForm()
{
#ifdef DEBUG
	debugMessage("CanonicalForm", DESTRUCT);
#endif // DEBUG
}

// OPERATOR
CanonicalForm&	CanonicalForm::operator=(const CanonicalForm& rhs)
{
	if (this == &rhs) {
		return (*this);
	}
#ifdef DEBUG
	debugMessage("CanonicalForm", COPY_OPERATOR);
#endif // DEBUG
	return (*this);
}

// GETTER

// SETTER

// SUBJECT FUNC

