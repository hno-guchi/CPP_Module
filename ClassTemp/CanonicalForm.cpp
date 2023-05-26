/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CanonicalForm.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/26 17:39:03 by hnoguchi         ###   ########.fr       */
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
	debugMessage("CanonicalForm", DEFAULT_CONSTRUCT);
}

CanonicalForm::CanonicalForm(const CanonicalForm& src)
{
	debugMessage("CanonicalForm", COPY_CONSTRUCT);
	this->operator=(src);
}

// OPERATOR
CanonicalForm&	CanonicalForm::operator=(const CanonicalForm& rhs)
{
	debugMessage("CanonicalForm", COPY_OPERATOR);
	return (*this);
}

// GETTER

// SETTER

// SUBJECT FUNC

// DESTRUCTER
CanonicalForm::~CanonicalForm()
{
	debugMessage("CanonicalForm", DESTRUCT);
}
