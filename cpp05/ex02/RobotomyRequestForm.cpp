/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/04 17:57:33 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// CONSTRUCTER
RobotomyRequestForm::RobotomyRequestForm() :
	AForm(DEFAULT_FORM_NAME, RR_SIGN_GRADE, RR_EXEC_GRADE)
{
	debugMessage("RobotomyRequestForm", DEFAULT_CONSTRUCT);
	std::srand(static_cast<unsigned>(std::time(0)));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm(target, RR_SIGN_GRADE, RR_EXEC_GRADE)
{
	debugMessage("RobotomyRequestForm", HAS_ARGS_CONSTRUCT);
	std::srand(static_cast<unsigned>(std::time(0)));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) :
	AForm(src)
{
	debugMessage("RobotomyRequestForm", COPY_CONSTRUCT);
	this->operator=(src);
	std::srand(static_cast<unsigned>(std::time(0)));
}

// DESTRUCTER
RobotomyRequestForm::~RobotomyRequestForm()
{
	debugMessage("RobotomyRequestForm", DESTRUCT);
}

// OPERATOR
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this == &rhs) {
		return (*this);
	}
	AForm::operator=(rhs);
	debugMessage("RobotomyRequestForm", COPY_OPERATOR);
	return (*this);
}

// GETTER

// SETTER

// SUBJECT FUNC
void	RobotomyRequestForm::randomRequestRobotomy()
{
	try {
		int	execFlag = std::rand() % 2;

		if (execFlag == 0) {
			throw RobotomyRequestForm::FailedRequestRobotomyException();
		}
		std::cout << BLUE << this->getName() << " has been robotomized." << END << std::endl;
	} catch (std::exception& e) {
			std::cerr << RED << e.what() << END << std::endl;
	}
}

// EXCEPTION
RobotomyRequestForm::FailedRequestRobotomyException::FailedRequestRobotomyException() throw()
	: message_(FAILED_REQUEST_ROBOTOMY_MESSAGE)
{
	debugMessage("FailedRequestRobotomyException", DEFAULT_CONSTRUCT);
}

RobotomyRequestForm::FailedRequestRobotomyException::~FailedRequestRobotomyException() throw()
{
	debugMessage("FailedRequestRobotomyException", DESTRUCT);
}

const char*	RobotomyRequestForm::FailedRequestRobotomyException::what() const throw()
{
	return (this->message_.c_str());
}
