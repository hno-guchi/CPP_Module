/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/12 14:10:08 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Bureaucrat::Bureaucrat() : name_("John Doe"), grade_(150)
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
		throw Bureaucrat::GradeTooHighException("Grade is too high.");
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
		throw Bureaucrat::GradeTooHighException("Grade is too high.");
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
