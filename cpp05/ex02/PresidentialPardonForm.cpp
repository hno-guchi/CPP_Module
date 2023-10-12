/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/12 16:13:12 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

// CONSTRUCTER
// PresidentialPardonForm::PresidentialPardonForm() :
// 	AForm(DEFAULT_FORM_NAME, PP_SIGN_GRADE, PP_EXEC_GRADE)
// {
// 	debugMessage("PresidentialPardonForm", DEFAULT_CONSTRUCT);
// }

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm(target, this->getSignGrade(), this->getExecGrade())
{
	debugMessage("PresidentialPardonForm", HAS_ARGS_CONSTRUCT);
	this->target_ = "DEFAULT_TARGET";
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
int	PresidentialPardonForm::getSignGrade() const
{
	return (this->signGrade_);
}

int	PresidentialPardonForm::getExecGrade() const
{
	return (this->execGrade_);
}

const std::string&	PresidentialPardonForm::getTarget() const
{
	return (this->target_);
}

// SETTER
void	PresidentialPardonForm::setTarget(const std::string& target)
{
	this->target_ = target;
}

// SUBJECT FUNC
void	PresidentialPardonForm::action() const
{
	std::cout \
		<< BLUE << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << END \
		<< std::endl;
}
