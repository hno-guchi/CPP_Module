/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/05 08:04:27 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// CONSTRUCTER
PresidentialPardonForm::PresidentialPardonForm() :
	AForm(DEFAULT_FORM_NAME, PP_SIGN_GRADE, PP_EXEC_GRADE)
{
	debugMessage("PresidentialPardonForm", DEFAULT_CONSTRUCT);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm(target, PP_SIGN_GRADE, PP_EXEC_GRADE)
{
	debugMessage("PresidentialPardonForm", HAS_ARGS_CONSTRUCT);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) :
	AForm(src)
{
	debugMessage("PresidentialPardonForm", COPY_CONSTRUCT);
	this->operator=(src);
}

// DESTRUCTER
PresidentialPardonForm::~PresidentialPardonForm()
{
	debugMessage("PresidentialPardonForm", DESTRUCT);
}

// OPERATOR
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this == &rhs) {
		return (*this);
	}
	AForm::operator=(rhs);
	debugMessage("PresidentialPardonForm", COPY_OPERATOR);
	return (*this);
}

// GETTER

// SETTER

// SUBJECT FUNC
void	PresidentialPardonForm::action() const
{
	std::cout \
		<< BLUE << this->getName() << " has been pardoned by Zaphod Beeblebrox." << END \
		<< std::endl;
}
