/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/03 16:14:31 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "debugMessage.hpp"
#include "color.hpp"
#include <iostream>
#include <exception>

# define LOWEST_RANGE 150
# define HIGHEST_RANGE 1
# define GRADE_TOO_HIGH_MESSAGE "Grade is too high."
# define GRADE_TOO_LOW_MESSAGE "Grade is too low."

class Form {
private:
	// SUBJECT ATTRIBUTE
	const std::string	name_;
	bool				sign_; // construct(false)
	const unsigned int	grade_;

	// MY ATTRIBUTE

public:
	// CONSTRUCTER
	Form();
	Form(const std::string& name, const unsigned int& grade);
	Form(const Form& src);
	// DESTRUCTER
	virtual ~Form();
	// OPERATOR
	Form&	operator=(const Form& rhs);
	// GETTER
	const std::string&	getName() const;
	const bool&			getSign() const;
	const unsigned int&	getGrade() const;
	// SETTER

	// SUBJECT FUNC

	// EXCEPTION
	class GradeTooHighException : public std::exception {
	private:
		std::string	message_;
	
	public:
		GradeTooHighException() throw();
		~GradeTooHighException() throw();
		const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception {
	private:
		std::string	message_;
	
	public:
		GradeTooLowException() throw();
		~GradeTooLowException() throw();
		const char*	what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& lhs, const Form& rhs);

#endif
