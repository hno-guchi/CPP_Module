/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/12 14:37:12 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// CONSTRUCTER
// Form::Form() :
// 	name_(DEFAULT_FORM_NAME), sign_(false), signGrade_(150), executeGrade_(150)
// {
// 	debugMessage("Form", DEFAULT_CONSTRUCT);
// }

Form::Form(const std::string& name, const unsigned int& signGrade, const unsigned int& execGrade) :
	name_(name), sign_(false), signGrade_(signGrade), executeGrade_(execGrade)
{
	debugMessage("Form", HAS_ARGS_CONSTRUCT);
	if (name.empty() == true) {
		throw Form::EmptyNameException();
	}
	if (signGrade < this->highestRange_ || execGrade < this->highestRange_) {
		throw Form::GradeTooHighException();
	}
	if (this->lowestRange_ < signGrade || this->lowestRange_ < execGrade) {
		throw Form::GradeTooLowException();
	}
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

// SUBJECT FUNC
void	Form::beSigned(const Bureaucrat& rhs)
{
	if (this->getSignGrade() < rhs.getGrade()) {
		throw Form::GradeTooLowException();
	}
	if (this->getSign() == true){
		throw Form::AlreadySignedException();
	}
	this->sign_ = true;
}

// EXCEPTION
Form::GradeTooHighException::GradeTooHighException(const std::string& msg) : std::out_of_range(msg) {}

Form::GradeTooLowException::GradeTooLowException(const std::string& msg) : std::out_of_range(msg) {}

Form::EmptyNameException::EmptyNameException(const std::string& msg) : std::invalid_argument(msg) {}

Form::AlreadySignedException::AlreadySignedException(const std::string& msg) : std::logic_error(msg) {}

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
