/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/04 17:05:52 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "debugMessage.hpp"
#include "AForm.hpp"
// #include <experimental/random>
#include <random>

# define RR_SIGN_GRADE 72
# define RR_EXEC_GRADE 45
# define FAILED_REQUEST_ROBOTOMY_MESSAGE "Failed request robotomy."

class AForm;

class RobotomyRequestForm : public AForm {
private:
	// SUBJECT ATTRIBUTE

	// MY ATTRIBUTE

public:
	// CONSTRUCTER
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& name);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	// DESTRUCTER
	virtual ~RobotomyRequestForm();

	// OPERATOR
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& rhs);

	// GETTER

	// SETTER

	// SUBJECT FUNC
	void	randomRequestRobotomy();
	// EXCEPTION
	class FailedRequestRobotomyException : public std::exception {
	private:
		std::string	message_;
	
	public:
		FailedRequestRobotomyException() throw();
		~FailedRequestRobotomyException() throw();
		const char*	what() const throw();
	};
};

#endif
