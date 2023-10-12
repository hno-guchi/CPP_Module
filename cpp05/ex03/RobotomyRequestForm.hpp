/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/12 16:11:49 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "debugMessage.hpp"
#include "color.hpp"
#include <random>
#include <stdexcept>

class AForm;

class RobotomyRequestForm : public AForm {
private:
	// SUBJECT ATTRIBUTE

	// MY ATTRIBUTE
	const static int	signGrade_ = 72;
	const static int	execGrade_ = 45;
	// SUBJECT FUNC
	virtual void	action() const;
public:
	// CONSTRUCTER
	// RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target = "SAMPLE");
	RobotomyRequestForm(const RobotomyRequestForm& src);
	// DESTRUCTER
	~RobotomyRequestForm();
	// OPERATOR
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& rhs);
	// GETTER
	int						getSignGrade() const;
	int						getExecGrade() const;
	// SETTER
	// EXCEPTION
	class FailedRequestRobotomyException : public std::logic_error {
	public:
		FailedRequestRobotomyException(const std::string& msg = "Failed request robotomy.");
	};
};

#endif
