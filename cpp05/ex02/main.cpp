/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:13:38 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/12 16:09:51 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	std::cout << GREEN << "++++++++++ Test ShrubberyCreationForm ++++++++++" << END << std::endl;
	{
		Bureaucrat				president("president", 1);
		ShrubberyCreationForm	form_0;
		ShrubberyCreationForm	form_1("form_1");
		ShrubberyCreationForm	form_2(form_1);
		ShrubberyCreationForm	form_3("../../form_3");
		std::cout << std::endl;
		try {
			ShrubberyCreationForm	form_4("");
		}
		catch (std::exception& e) {
			std::cerr << RED << e.what() << END << std::endl;
		}
		std::cout << std::endl;

		president.signForm(form_0); president.signForm(form_1);
		president.signForm(form_2); president.signForm(form_3);
		// president.signForm(form_4);
		std::cout << std::endl;

		president.executeForm(form_0); president.executeForm(form_1);
		president.executeForm(form_2); president.executeForm(form_3);
		// president.executeForm(form_4);
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << GREEN << "++++++++++ Test RobotomyRequestForm ++++++++++" << END << std::endl;
	{
		Bureaucrat			president("president", 1);
		RobotomyRequestForm	form_0;
		RobotomyRequestForm	form_1("form_1");
		RobotomyRequestForm	form_2(form_1);
		try {
			RobotomyRequestForm	form_3("");
		}
		catch (std::exception& e) {
			std::cerr << RED << e.what() << END << std::endl;
		}
		std::cout << std::endl;

		president.signForm(form_0); president.signForm(form_1);
		president.signForm(form_2);
		// president.signForm(form_3);
		std::cout << std::endl;

		president.executeForm(form_0); president.executeForm(form_1);
		president.executeForm(form_2);
		// president.executeForm(form_3);
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << GREEN << "++++++++++ Test PresidentialPardonForm ++++++++++" << END << std::endl;
	{
		Bureaucrat				president("president", 1);
		PresidentialPardonForm	form_0;
		PresidentialPardonForm	form_1("form_1");
		PresidentialPardonForm	form_2(form_1);
		std::cout << std::endl;
		try {
			PresidentialPardonForm	form_3("");
		}
		catch (std::exception& e) {
			std::cerr << RED << e.what() << END << std::endl;
		}
		std::cout << std::endl;

		president.signForm(form_0); president.signForm(form_1);
		president.signForm(form_2);
		// president.signForm(form_3);
		std::cout << std::endl;

		president.executeForm(form_0); president.executeForm(form_1);
		president.executeForm(form_2);
		// president.executeForm(form_3);
		std::cout << std::endl;
	}

	std::cout << GREEN << "++++++++++ Test execute member function [AForm class(abstract)] ++++++++++" << END << std::endl;
	{
		Bureaucrat				grade_25("grade_25", 25);
		Bureaucrat				grade_5("grade_5", 5);
		PresidentialPardonForm	exec_form("exec_form");

		std::cout << std::endl;
		grade_5.executeForm(exec_form);

		std::cout << std::endl;
		std::cout << exec_form << std::endl;

		grade_25.decrementGrade();
		grade_25.signForm(exec_form);
		std::cout << exec_form << std::endl;

		grade_25.incrementGrade();
		grade_25.signForm(exec_form);
		std::cout << exec_form << std::endl;

		std::cout << std::endl;
		grade_5.decrementGrade();
		grade_5.executeForm(exec_form);

		grade_5.incrementGrade();
		grade_5.executeForm(exec_form);

		std::cout << std::endl;
	}
#ifdef LEAKS
	system("leaks -q ex02");
#endif
}
