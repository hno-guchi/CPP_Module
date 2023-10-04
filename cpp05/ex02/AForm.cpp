/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/04 11:56:43 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// CONSTRUCTER
AForm::AForm() :
	name_(DEFAULT_FORM_NAME), sign_(false), signGrade_(150), executeGrade_(150)
{
	debugMessage("AForm", DEFAULT_CONSTRUCT);
}

AForm::AForm(const std::string& name, const unsigned int& signGrade, const unsigned int& execGrade) :
	name_(name), sign_(false), signGrade_(signGrade), executeGrade_(execGrade)
{
	debugMessage("AForm", HAS_ARGS_CONSTRUCT);
	try {
		if (name.empty() == true) {
			throw AForm::EmptyNameException();
		}
		if (signGrade < HIGHEST_RANGE || execGrade < HIGHEST_RANGE) {
			throw AForm::GradeTooHighException();
		}
		if (LOWEST_RANGE < signGrade || LOWEST_RANGE < execGrade) {
			throw AForm::GradeTooLowException();
		}
	}
	catch (std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
		// throw;
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
void	AForm::setSign(const bool& sign)
{
	this->sign_ = sign;
}

// SUBJECT FUNC
void	AForm::beSigned(const Bureaucrat& rhs)
{
	if (this->getSignGrade() < rhs.getGrade()) {
		throw AForm::GradeTooLowException();
	}
	if (this->getSign() == true){
		throw AForm::AlreadySignedException();
	}
	this->setSign(true);
}

// EXCEPTION
AForm::GradeTooHighException::GradeTooHighException() throw()
	: message_(GRADE_TOO_HIGH_MESSAGE)
{
	debugMessage("GradeTooHighException", DEFAULT_CONSTRUCT);
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
	debugMessage("GradeTooHighException", DESTRUCT);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return (this->message_.c_str());
}

AForm::GradeTooLowException::GradeTooLowException() throw()
	: message_(GRADE_TOO_LOW_MESSAGE)
{
	debugMessage("GradeTooLowException", DEFAULT_CONSTRUCT);
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
	debugMessage("GradeTooLowException", DESTRUCT);
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return (this->message_.c_str());
}

AForm::AlreadySignedException::AlreadySignedException() throw()
	: message_(ALREADY_SIGNED_MESSAGE)
{
	debugMessage("AlreadySignedException", DEFAULT_CONSTRUCT);
}

AForm::AlreadySignedException::~AlreadySignedException() throw()
{
	debugMessage("AlreadySignedException", DESTRUCT);
}

const char*	AForm::AlreadySignedException::what() const throw()
{
	return (this->message_.c_str());
}

AForm::EmptyNameException::EmptyNameException() throw()
	: message_(EMPTY_NAME_MESSAGE)
{
	debugMessage("EmptyNameException", DEFAULT_CONSTRUCT);
}

AForm::EmptyNameException::~EmptyNameException() throw()
{
	debugMessage("EmptyNameException", DESTRUCT);
}

const char*	AForm::EmptyNameException::what() const throw()
{
	return (this->message_.c_str());
}

std::ostream&	operator<<(std::ostream& lhs, const AForm& rhs)
{
	lhs << YELLOW << rhs.getName() << END \
		<< ", Form sign " \
		<< YELLOW << rhs.getSign() << END \
		<< ", Form sign grade " \
		<< YELLOW << rhs.getSignGrade() << END \
		<< ", Form execute grade " \
		<< YELLOW << rhs.getExecuteGrade() << END \
		<< ".";
	return (lhs);
}
