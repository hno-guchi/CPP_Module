/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/09/01 17:28:01 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char*	Bureaucrat::GradeTooHighException::what()
{
	return ("Grade is too high.");
}

const char*	Bureaucrat::GradeTooLowException::what()
{
	return ("Grade is too low.");
}

// void	debugMessage(const std::string &className, tMessageType type);
// 	DEFAULT_CONSTRUCT,
// 	HAS_ARGS_CONSTRUCT,
// 	COPY_CONSTRUCT,
// 	COPY_OPERATOR,
// 	DESTRUCT,
Bureaucrat::Bureaucrat() :
	name_(""), grade_(150)
{}

Bureaucrat::Bureaucrat(const std::string& name, const unsigned int& grade)
{
	if (20 < name.size()) {
		this->name_ = name.substr(0, 20);
	}
	if (grade < HIGHEST_RANGE) {
		throw GradeTooLowException;
	}
	if (LOWEST_RANGE < grade) {
		throw GradeTooHighException;
	}
	this->grade_ = grade;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	this->name_ = rhs.getName();
	this->grade_ = rhs.getGrade();
}

const std::string&	Bureaucrat::getName() const
{
	return (this->name_);
}

const unsigned int&	Bureaucrat::getGrade() const;
{
	return (this->grade_);
}
