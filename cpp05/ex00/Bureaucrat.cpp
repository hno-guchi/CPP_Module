/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/03 13:28:07 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

GradeTooHighException::GradeTooHighException() throw()
	: message_(GRADE_TOO_HIGH_MESSAGE)
{
	debugMessage("GradeTooHighException", DEFAULT_CONSTRUCT);
}

GradeTooHighException::~GradeTooHighException() throw()
{
	debugMessage("GradeTooHighException", DESTRUCT);
}

const char*	GradeTooHighException::what() const throw()
{
	return (this->message_.c_str());
}

GradeTooLowException::GradeTooLowException() throw()
	: message_(GRADE_TOO_LOW_MESSAGE)
{
	debugMessage("GradeTooLowException", DEFAULT_CONSTRUCT);
}

GradeTooLowException::~GradeTooLowException() throw()
{
	debugMessage("GradeTooLowException", DESTRUCT);
}

const char*	GradeTooLowException::what() const throw()
{
	return (this->message_.c_str());
}

Bureaucrat::Bureaucrat() :
	name_(""), grade_(150)
{
	debugMessage("Bureaucrat", DEFAULT_CONSTRUCT);
}

Bureaucrat::Bureaucrat(const std::string& name, const unsigned int& grade) :
	name_(name)
{
	debugMessage("Bureaucrat", HAS_ARGS_CONSTRUCT);
	if (grade < HIGHEST_RANGE) {
		throw GradeTooHighException();
	}
	if (LOWEST_RANGE < grade) {
		throw GradeTooLowException();
	}
	this->grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) :
	name_(src.getName())
{
	debugMessage("Bureaucrat", COPY_CONSTRUCT);
	this->operator=(src);
}

Bureaucrat::~Bureaucrat()
{
	debugMessage("Bureaucrat", DESTRUCT);
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this == &rhs) {
		return (*this);
	}
	debugMessage("Bureaucrat", COPY_OPERATOR);
	this->grade_ = rhs.getGrade();
	return (*this);
}

const std::string&	Bureaucrat::getName() const
{
	return (this->name_);
}

const unsigned int&	Bureaucrat::getGrade() const
{
	return (this->grade_);
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade_ == HIGHEST_RANGE) {
		throw GradeTooHighException();
	}
	this->grade_ -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade_ == LOWEST_RANGE) {
		throw GradeTooLowException();
	}
	this->grade_ += 1;
}
