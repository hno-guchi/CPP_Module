/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/12 14:44:39 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "debugMessage.hpp"
#include "color.hpp"
#include <iostream>
#include <stdexcept>
#include <exception>

class AForm;

class Bureaucrat {
private:
	// SUBJECT ATTRIBUTE
	const std::string	name_;
	unsigned int		grade_;
	// MY ATTRIBUTE
	const static int	lowestRange_ = 150;
	const static int	highestRange_ = 1;

public:
	// CONSTRUCTER
	// Bureaucrat();
	Bureaucrat(const std::string& name = "John Doe", const unsigned int grade = 150);
	Bureaucrat(const Bureaucrat& src);
	// DESTRUCTER
	~Bureaucrat();
	// OPERATOR
	Bureaucrat&			operator=(const Bureaucrat& rhs);
	// GETTER
	const std::string&	getName() const;
	const unsigned int&	getGrade() const;
	// SETTER

	// SUBJECT FUNC
	void	incrementGrade();
	void	decrementGrade();
	void	signForm(AForm& form);
	void	executeForm(AForm const & form);
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
};

std::ostream&	operator<<(std::ostream& lhs, const Bureaucrat& rhs);

#endif
