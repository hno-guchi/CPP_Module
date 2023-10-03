/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/03 15:32:57 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "debugMessage.hpp"
#include "color.hpp"
#include <iostream>
#include <exception>

# define LOWEST_RANGE 150
# define HIGHEST_RANGE 1
# define GRADE_TOO_HIGH_MESSAGE "Grade is too high."
# define GRADE_TOO_LOW_MESSAGE "Grade is too low."

class Bureaucrat {
private:
	// SUBJECT ATTRIBUTE
	const std::string	name_;
	unsigned int		grade_;

	// MY ATTRIBUTE

public:
	// CONSTRUCTER
	Bureaucrat();
	Bureaucrat(const std::string& name, const unsigned int& grade);
	Bureaucrat(const Bureaucrat& src);
	// DESTRUCTER
	virtual ~Bureaucrat();
	// OPERATOR
	Bureaucrat&			operator=(const Bureaucrat& rhs);
	// GETTER
	const std::string&	getName() const;
	const unsigned int&	getGrade() const;
	// SETTER

	// SUBJECT FUNC
	void	incrementGrade();
	void	decrementGrade();
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

std::ostream&	operator<<(std::ostream& lhs, const Bureaucrat& rhs);

#endif
