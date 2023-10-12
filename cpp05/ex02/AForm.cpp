/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/12 15:32:47 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// CONSTRUCTER
// AForm::AForm() :
// 	name_(DEFAULT_FORM_NAME), sign_(false), signGrade_(150), executeGrade_(150)
// {
// 	debugMessage("AForm", DEFAULT_CONSTRUCT);
// }

AForm::AForm(const std::string& name, const unsigned int& signGrade, const unsigned int& execGrade) :
	name_(name), sign_(false), signGrade_(signGrade), executeGrade_(execGrade)
{
	debugMessage("AForm", HAS_ARGS_CONSTRUCT);
	if (name.empty() == true) {
		throw AForm::EmptyNameException();
	}
	if (signGrade < this->highestRange_ || execGrade < this->highestRange_) {
		throw AForm::GradeTooHighException();
	}
	if (this->lowestRange_ < signGrade || this->lowestRange_ < execGrade) {
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(const AForm& src) :
	name_(src.getName()), signGrade_(src.getSignGrade()), executeGrade_(src.getExecuteGrade())
{
	debugMessage("AForm", COPY_CONSTRUCT);
	this->operator=(src);
}

// DESTRUCTER
AForm::~AForm()
{
	debugMessage("AForm", DESTRUCT);
}

// OPERATOR
AForm&	AForm::operator=(const AForm& rhs)
{
	if (this == &rhs) {
		return (*this);
	}
	debugMessage("AForm", COPY_OPERATOR);
	this->sign_ = rhs.getSign();
	return (*this);
}

// GETTER
const std::string&	AForm::getName() const
{
	return (this->name_);
}

const bool&		AForm::getSign() const
{
	return (this->sign_);
}

const unsigned int&	AForm::getSignGrade() const
{
	return (this->signGrade_);
}

const unsigned int&	AForm::getExecuteGrade() const
{
	return (this->executeGrade_);
}

// SETTER
// SUBJECT FUNC
void	AForm::beSigned(const Bureaucrat& rhs)
{
	if (this->getSignGrade() < rhs.getGrade()) {
		throw AForm::GradeTooLowException();
	}
	if (this->getSign() == true){
		throw AForm::AlreadySignedException();
	}
	this->sign_ = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() == false) {
		throw AForm::NotSignedException();
	}
	if (this->getExecuteGrade() < executor.getGrade()) {
		throw AForm::GradeTooLowException();
	}
	try {
		this->action();
	}
	catch (std::exception& e) {
		throw ;
	}
}

// EXCEPTION
AForm::GradeTooHighException::GradeTooHighException(const std::string& msg) : std::out_of_range(msg) {}

AForm::GradeTooLowException::GradeTooLowException(const std::string& msg) : std::out_of_range(msg) {}

AForm::EmptyNameException::EmptyNameException(const std::string& msg) : std::invalid_argument(msg) {}

AForm::AlreadySignedException::AlreadySignedException(const std::string& msg) : std::logic_error(msg) {}

AForm::NotSignedException::NotSignedException(const std::string& msg) : std::logic_error(msg) {}

std::ostream&	operator<<(std::ostream& lhs, const AForm& rhs)
{
	lhs << YELLOW << rhs.getName() << END \
		<< ", Form sign " \
		<< std::boolalpha << YELLOW << rhs.getSign() << END \
		<< ", Form sign grade " \
		<< YELLOW << rhs.getSignGrade() << END \
		<< ", Form execute grade " \
		<< YELLOW << rhs.getExecuteGrade() << END \
		<< ".";
	return (lhs);
}
