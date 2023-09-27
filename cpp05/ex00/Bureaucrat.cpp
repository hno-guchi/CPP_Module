/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/09/08 14:06:40 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// const char*	Bureaucrat::GradeTooHighException::what()
// {
// 	return ("Grade is too high.");
// }
// 
// const char*	Bureaucrat::GradeTooLowException::what()
// {
// 	return ("Grade is too low.");
// }

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
		throw Bureaucrat::GradeTooHighException;
	}
	if (LOWEST_RANGE < grade) {
		throw Bureaucrat::GradeTooLowException;
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

void	Bureaucrat::incrementGrade(const unsigned int& range)
{
	if ((this->grade_ - HIGHEST_RANGE) < range) {
		throw Bureaucrat::GradeTooHighException;
	}
	this->grade_ -= range;
}

void	Bureaucrat::decrementGrade(const unsigned int& range)
{
	if ((LOWEST_RANGE - this->grade_) < range) {
		throw Bureaucrat::GradeTooLowException;
	}
	this->grade_ += range;
}
