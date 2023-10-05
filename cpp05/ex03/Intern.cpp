/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/05 16:46:17 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// CONSTRUCTER
Intern::Intern()
{
	debugMessage("Intern", DEFAULT_CONSTRUCT);
}

Intern::Intern(const Intern& src)
{
	debugMessage("Intern", COPY_CONSTRUCT);
	this->operator=(src);
}

// DESTRUCTER
Intern::~Intern()
{
	debugMessage("Intern", DESTRUCT);
}

// OPERATOR
Intern&	Intern::operator=(const Intern& rhs)
{
	// if (this == &rhs) {
	// 	return (*this);
	// }
	(void)rhs;
	debugMessage("Intern", COPY_OPERATOR);
	return (*this);
}

// GETTER

// SETTER

static void	actionMessage(const std::string& name, const std::string& target, const std::string& action)
{
	std::cout << YELLOW \
		<< name << " " << action << " " << target
		<< END << std::endl;
}

static void	notActionMessage(const std::string& name, const std::string& target, const std::string& action)
{
	std::cerr \
		<< YELLOW << name << END \
		<< " couldn’t " << action << " " \
		<< YELLOW << target << END \
		<< " because " \
		<< std::flush;
}

// SUBJECT FUNC
AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	AForm*				ptr = NULL;
	unsigned int		i(0);
	static std::string	formList[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
		"",
	};

	while (name != formList[i]) {
		if (formList[i].empty() == true) {
			break ;
		}
		i += 1;
	}
	try {
		switch(i) {
			case 0:
				ptr = new ShrubberyCreationForm(target);
				break;
			case 1:
				ptr = new RobotomyRequestForm(target);
				break ;
			case 2:
				ptr = new PresidentialPardonForm(target);
				break ;
			default:
				throw Intern::NotExistFormException();
		}
		actionMessage("Intern", "creates", target);
	}
	catch (std::exception& e) {
		notActionMessage("Intern", "create", target);
		std::cerr << RED << e.what() << END << std::endl;
	}
	return (ptr);
}

// EXCEPTION
Intern::NotExistFormException::NotExistFormException() throw()
	: message_(NOT_EXIST_FORM_MESSAGE)
{
	debugMessage("NotExistFormException", DEFAULT_CONSTRUCT);
}

Intern::NotExistFormException::~NotExistFormException() throw()
{
	debugMessage("NotExistFormException", DESTRUCT);
}

const char*	Intern::NotExistFormException::what() const throw()
{
	return (this->message_.c_str());
}
