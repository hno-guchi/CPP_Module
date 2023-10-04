/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/04 11:58:52 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
	name_(DEFAULT_NAME), grade_(150)
{
	debugMessage("Bureaucrat", DEFAULT_CONSTRUCT);
}

Bureaucrat::Bureaucrat(const std::string& name, const unsigned int& grade) :
	name_(name)
{
	debugMessage("Bureaucrat", HAS_ARGS_CONSTRUCT);
	try {
		if (name.empty() == true) {
			throw Bureaucrat::EmptyNameException();
		}
		if (grade < HIGHEST_RANGE) {
			this->grade_ = HIGHEST_RANGE;
			throw Bureaucrat::GradeTooHighException();
		}
		if (LOWEST_RANGE < grade) {
			this->grade_ = LOWEST_RANGE;
			throw Bureaucrat::GradeTooLowException();
		}
		this->grade_ = grade;
	}
	catch (std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
		// throw;
	}
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
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade_ -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade_ == LOWEST_RANGE) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->grade_ += 1;
}

static void	signedMessage(const std::string& name, const std::string& target)
{
	std::cout \
		<< YELLOW << name << END \
		<< " signed " \
		<< YELLOW << target << END \
		<< std::endl;
}

static void	notSignedMessage(const std::string& name, const std::string& target)
{
	std::cerr \
		<< YELLOW << name << END \
		<< " couldn’t sign " \
		<< YELLOW << target << END \
		<< " because " \
		<< std::flush;
}

void	Bureaucrat::signForm(AForm& rhs)
{
	try {
		rhs.beSigned(*this);
		signedMessage(this->getName(), rhs.getName());
	}
	catch (std::exception& e) {
		notSignedMessage(this->getName(), rhs.getName());
		std::cerr << RED << e.what() << END << std::endl;
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException() throw()
	: message_(GRADE_TOO_HIGH_MESSAGE)
{
	debugMessage("GradeTooHighException", DEFAULT_CONSTRUCT);
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	debugMessage("GradeTooHighException", DESTRUCT);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return (this->message_.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException() throw()
	: message_(GRADE_TOO_LOW_MESSAGE)
{
	debugMessage("GradeTooLowException", DEFAULT_CONSTRUCT);
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	debugMessage("GradeTooLowException", DESTRUCT);
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return (this->message_.c_str());
}

Bureaucrat::EmptyNameException::EmptyNameException() throw()
	: message_(EMPTY_NAME_MESSAGE)
{
	debugMessage("EmptyNameException", DEFAULT_CONSTRUCT);
}

Bureaucrat::EmptyNameException::~EmptyNameException() throw()
{
	debugMessage("EmptyNameException", DESTRUCT);
}

const char*	Bureaucrat::EmptyNameException::what() const throw()
{
	return (this->message_.c_str());
}
std::ostream&	operator<<(std::ostream& lhs, const Bureaucrat& rhs)
{
	lhs << YELLOW << rhs.getName() << END \
		<< ", bureaucrat grade " \
		<< YELLOW << rhs.getGrade() << END \
		<< ".";
	return (lhs);
}
