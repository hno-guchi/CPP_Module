/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:13:38 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/05 08:02:12 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	std::cout << GREEN << "++++++++++ Test ShrubberyCreationForm ++++++++++" << END << std::endl;
	{
		ShrubberyCreationForm	form_0;
		ShrubberyCreationForm	form_1("form_1");
		ShrubberyCreationForm	form_2(form_1);
		ShrubberyCreationForm	form_3("../../form_3");
		ShrubberyCreationForm	form_4("");
		
		form_0.action();
		form_1.action();
		form_2.action();
		form_3.action();
		form_4.action();

		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << GREEN << "++++++++++ Test RobotomyRequestForm ++++++++++" << END << std::endl;
	{
		RobotomyRequestForm	form_0;
		RobotomyRequestForm	form_1("form_1");
		RobotomyRequestForm	form_2(form_1);
		RobotomyRequestForm	form_3("");

		std::cout << std::endl;
		form_0.action();
		form_1.action();
		form_2.action();
		form_3.action();
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << GREEN << "++++++++++ Test PresidentialPardonForm ++++++++++" << END << std::endl;
	{
		PresidentialPardonForm		form_0;
		PresidentialPardonForm		form_1("form_1");
		PresidentialPardonForm		form_2(form_1);
		PresidentialPardonForm		form_3("");

		std::cout << std::endl;
		form_0.action();
		form_1.action();
		form_2.action();
		form_3.action();
		std::cout << std::endl;
	}

	{
		// Bureaucrat				user_0("user_0", 50);
	}
#ifdef LEAKS
	system("leaks -q ex02");
#endif
}
