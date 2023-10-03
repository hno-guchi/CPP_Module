/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/03 18:31:24 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "debugMessage.hpp"
#include "color.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

# define LOWEST_RANGE 150
# define HIGHEST_RANGE 1
# define DEFAULT_FORM_NAME "SAMPLE"
# define GRADE_TOO_HIGH_MESSAGE "Grade is too high."
# define GRADE_TOO_LOW_MESSAGE "Grade is too low."
# define ALREADY_SIGNED_MESSAGE "Already signed."

class Bureaucrat;

class Form {
private:
	// SUBJECT ATTRIBUTE
	const std::string	name_;
	bool				sign_;
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
	void				setSign(const bool& sign);
	// SUBJECT FUNC
	void	beSigned(const Bureaucrat& rhs);
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
	class AlreadySignedException : public std::exception {
	private:
		std::string	message_;
	
	public:
		AlreadySignedException() throw();
		~AlreadySignedException() throw();
		const char*	what() const throw();
	};
	class EmptyNameException : public std::exception {
	private:
		std::string	message_;
	
	public:
		EmptyNameException() throw();
		~EmptyNameException() throw();
		const char*	what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& lhs, const Form& rhs);

#endif
