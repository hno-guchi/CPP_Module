/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/12 15:32:48 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "debugMessage.hpp"
#include "color.hpp"
#include <iostream>
#include <stdexcept>
#include <exception>

class Bureaucrat;

class AForm {
private:
	// SUBJECT ATTRIBUTE
	const std::string	name_;
	bool				sign_;
	const unsigned int	signGrade_;
	const unsigned int	executeGrade_;
	// MY ATTRIBUTE
	const static int	lowestRange_ = 150;
	const static int	highestRange_ = 1;

	// SUBJECT FUNC
	virtual void		action() const = 0;
public:
	// CONSTRUCTER
	// AForm();
	AForm(const std::string& name = "SAMPLE", const unsigned int& signGrade = 150, const unsigned int& execGrade = 150);
	AForm(const AForm& src);
	// DESTRUCTER
	virtual ~AForm();
	// OPERATOR
	AForm&				operator=(const AForm& rhs);
	// GETTER
	const std::string&	getName() const;
	const bool&			getSign() const;
	const unsigned int&	getSignGrade() const;
	const unsigned int&	getExecuteGrade() const;
	// SETTER
	// SUBJECT FUNC
	void				beSigned(const Bureaucrat& rhs);
	void				execute(Bureaucrat const & executor) const;
	// EXCEPTION
	class GradeTooHighException : public std::out_of_range {
	public:
		GradeTooHighException(const std::string& msg = "Grade is too high.");
	};
	class GradeTooLowException : public std::out_of_range {
	public:
		GradeTooLowException(const std::string& msg = "Grade is too low.");
	};
	class EmptyNameException : public std::invalid_argument {
	public:
		EmptyNameException(const std::string& msg = "Name is empty.");
	};
	class AlreadySignedException : public std::logic_error {
	public:
		AlreadySignedException(const std::string& msg = "Already signed.");
	};
	class NotSignedException : public std::logic_error {
	public:
		NotSignedException(const std::string& msg = "Not yet signed.");
	};
};

std::ostream&	operator<<(std::ostream& lhs, const AForm& rhs);

#endif
