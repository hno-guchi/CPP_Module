/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/05 17:02:27 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "debugMessage.hpp"
#include "color.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define NOT_EXIST_FORM_MESSAGE "Not exist form."

class AForm;
class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

class Intern {
private:
	// SUBJECT ATTRIBUTE
	// MY ATTRIBUTE
public:
	// CONSTRUCTER
	Intern();
	Intern(const Intern& src);
	// DESTRUCTER
	~Intern();
	// OPERATOR
	Intern&	operator=(const Intern& rhs);
	// GETTER

	// SETTER

	// SUBJECT FUNC
	AForm*	makeForm(const std::string& name, const std::string& target);
	// EXCEPTION
	class NotExistFormException : public std::exception {
	private:
		std::string	message_;
	
	public:
		NotExistFormException() throw();
		~NotExistFormException() throw();
		const char*	what() const throw();
	};
};

#endif
