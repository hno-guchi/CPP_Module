/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/12 14:39:13 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Bureaucrat::Bureaucrat() :
// 	name_(DEFAULT_NAME), grade_(150)
// {
// 	debugMessage("Bureaucrat", DEFAULT_CONSTRUCT);
// }

Bureaucrat::Bureaucrat(const std::string& name, const unsigned int grade) :
	name_(name)
{
	debugMessage("Bureaucrat", HAS_ARGS_CONSTRUCT);
	if (name.empty() == true) {
		throw Bureaucrat::EmptyNameException();
	}
	if (grade < this->highestRange_) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (this->lowestRange_ < grade) {
		throw Bureaucrat::GradeTooLowException();
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
	if (this->grade_ == this->highestRange_) {
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade_ -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade_ == this->lowestRange_) {
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

void	Bureaucrat::signForm(Form& rhs)
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

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& msg) : std::out_of_range(msg) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& msg) : std::out_of_range(msg) {}

Bureaucrat::EmptyNameException::EmptyNameException(const std::string& msg) : std::invalid_argument(msg) {}

std::ostream&	operator<<(std::ostream& lhs, const Bureaucrat& rhs)
{
	lhs << YELLOW << rhs.getName() << END \
		<< ", bureaucrat grade " \
		<< YELLOW << rhs.getGrade() << END \
		<< ".";
	return (lhs);
}
