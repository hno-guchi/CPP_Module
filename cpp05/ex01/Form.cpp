/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/10 18:40:02 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// CONSTRUCTER
Form::Form() :
	name_(DEFAULT_FORM_NAME), sign_(false), signGrade_(150), executeGrade_(150)
{
	debugMessage("Form", DEFAULT_CONSTRUCT);
}

Form::Form(const std::string& name, const unsigned int& signGrade, const unsigned int& execGrade) :
	name_(name), sign_(false), signGrade_(signGrade), executeGrade_(execGrade)
{
	debugMessage("Form", HAS_ARGS_CONSTRUCT);
	// try {
	if (name.empty() == true) {
		throw Form::EmptyNameException();
	}
	if (signGrade < HIGHEST_RANGE || execGrade < HIGHEST_RANGE) {
		throw Form::GradeTooHighException();
	}
	if (LOWEST_RANGE < signGrade || LOWEST_RANGE < execGrade) {
		throw Form::GradeTooLowException();
	}
	// }
	// catch (std::exception& e) {
	// 	std::cerr << RED << e.what() << END << std::endl;
	// 	throw;
	// }
}

Form::Form(const Form& src) :
	name_(src.getName()), signGrade_(src.getSignGrade()), executeGrade_(src.getExecuteGrade())
{
	debugMessage("Form", COPY_CONSTRUCT);
	this->operator=(src);
}

// DESTRUCTER
Form::~Form()
{
	debugMessage("Form", DESTRUCT);
}

// OPERATOR
Form&	Form::operator=(const Form& rhs)
{
	if (this == &rhs) {
		return (*this);
	}
	debugMessage("Form", COPY_OPERATOR);
	this->sign_ = rhs.getSign();
	return (*this);
}

// GETTER
const std::string&	Form::getName() const
{
	return (this->name_);
}

const bool&		Form::getSign() const
{
	return (this->sign_);
}

const unsigned int&	Form::getSignGrade() const
{
	return (this->signGrade_);
}

const unsigned int&	Form::getExecuteGrade() const
{
	return (this->executeGrade_);
}

// SETTER
void	Form::setSign(const bool& sign)
{
	this->sign_ = sign;
}

// SUBJECT FUNC
void	Form::beSigned(const Bureaucrat& rhs)
{
	if (this->getSignGrade() < rhs.getGrade()) {
		throw Form::GradeTooLowException();
	}
	if (this->getSign() == true){
		throw Form::AlreadySignedException();
	}
	this->setSign(true);
}

// EXCEPTION
Form::GradeTooHighException::GradeTooHighException() throw()
	: message_(GRADE_TOO_HIGH_MESSAGE)
{
	debugMessage("GradeTooHighException", DEFAULT_CONSTRUCT);
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	debugMessage("GradeTooHighException", DESTRUCT);
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return (this->message_.c_str());
}

Form::GradeTooLowException::GradeTooLowException() throw()
	: message_(GRADE_TOO_LOW_MESSAGE)
{
	debugMessage("GradeTooLowException", DEFAULT_CONSTRUCT);
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
	debugMessage("GradeTooLowException", DESTRUCT);
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return (this->message_.c_str());
}

Form::AlreadySignedException::AlreadySignedException() throw()
	: message_(ALREADY_SIGNED_MESSAGE)
{
	debugMessage("AlreadySignedException", DEFAULT_CONSTRUCT);
}

Form::AlreadySignedException::~AlreadySignedException() throw()
{
	debugMessage("AlreadySignedException", DESTRUCT);
}

const char*	Form::AlreadySignedException::what() const throw()
{
	return (this->message_.c_str());
}

Form::EmptyNameException::EmptyNameException() throw()
	: message_(EMPTY_NAME_MESSAGE)
{
	debugMessage("EmptyNameException", DEFAULT_CONSTRUCT);
}

Form::EmptyNameException::~EmptyNameException() throw()
{
	debugMessage("EmptyNameException", DESTRUCT);
}

const char*	Form::EmptyNameException::what() const throw()
{
	return (this->message_.c_str());
}

std::ostream&	operator<<(std::ostream& lhs, const Form& rhs)
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
