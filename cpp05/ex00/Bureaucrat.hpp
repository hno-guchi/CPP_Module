/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/02 12:24:54 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "debugMessage.hpp"
#include <iostream>
#include <exception>

# define LOWEST_RANGE 150
# define HIGHEST_RANGE 1

class GradeTooHighException : public std::exception {
public:
	virtual const char*	what();
};

class GradeTooLowException : public std::exception {
public:
	virtual const char*	what();
};

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
	// const Bureaucrat&	operator<<(const Bureaucrat& rhs) const;

	// GETTER
	const std::string&	getName() const;
	const unsigned int&	getGrade() const;

	// SETTER

	// SUBJECT FUNC
	void	incrementGrade(const unsigned int& range);
	void	decrementGrade(const unsigned int& range);
};

#endif
