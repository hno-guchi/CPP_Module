/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/12 16:12:01 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

// CONSTRUCTER
// RobotomyRequestForm::RobotomyRequestForm() :
// 	AForm(DEFAULT_FORM_NAME, RR_SIGN_GRADE, RR_EXEC_GRADE)
// {
// 	debugMessage("RobotomyRequestForm", DEFAULT_CONSTRUCT);
// 	std::srand(static_cast<unsigned>(std::time(0)));
// }

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm(target, this->getSignGrade(), this->getExecGrade())
{
	debugMessage("RobotomyRequestForm", HAS_ARGS_CONSTRUCT);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) :
	AForm(src)
{
	debugMessage("RobotomyRequestForm", COPY_CONSTRUCT);
	this->operator=(src);
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
int	RobotomyRequestForm::getSignGrade() const
{
	return (this->signGrade_);
}

int	RobotomyRequestForm::getExecGrade() const
{
	return (this->execGrade_);
}

// SETTER

// SUBJECT FUNC
void	RobotomyRequestForm::action() const
{
	int	execFlag = std::rand() % 2;

	if (execFlag == 0) {
		throw RobotomyRequestForm::FailedRequestRobotomyException();
	}
	std::cout << BLUE << this->getName() << " has been robotomized." << END << std::endl;
}

// EXCEPTION
RobotomyRequestForm::FailedRequestRobotomyException::FailedRequestRobotomyException(const std::string& msg) : std::logic_error(msg) {}
