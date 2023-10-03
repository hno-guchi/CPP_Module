/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/03 16:24:39 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// CONSTRUCTER
Form::Form() :
	name_(""), sign_(false), grade_(150)
{
	debugMessage("Form", DEFAULT_CONSTRUCT);
}

Form::Form(const std::string& name, const unsigned int& grade) :
	name_(name), sign_(false), grade_(grade)
{
	debugMessage("Form", HAS_ARGS_CONSTRUCT);
	try {
		if (grade < HIGHEST_RANGE) {
			throw Form::GradeTooHighException();
		}
		if (LOWEST_RANGE < grade) {
			throw Form::GradeTooLowException();
		}
	}
	catch (std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
		// throw;
	}
}

Form::Form(const Form& src) :
	name_(src.getName()), grade_(src.getGrade())
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

const unsigned int&	Form::getGrade() const
{
	return (this->grade_);
}

// SETTER

// SUBJECT FUNC

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

std::ostream&	operator<<(std::ostream& lhs, const Form& rhs)
{
	// std::string	message = rhs.getName();
	lhs << YELLOW << rhs.getName() << END \
		<< ", Form sign " \
		<< YELLOW << rhs.getSign() << END \
		<< ", Form grade " \
		<< YELLOW << rhs.getGrade() << END \
		<< ".";
	return (lhs);
}
