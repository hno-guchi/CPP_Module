/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:13:38 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/04 18:03:15 by hnoguchi         ###   ########.fr       */
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
		
		form_0.createAsciiTree();
		form_1.createAsciiTree();
		form_2.createAsciiTree();
		form_3.createAsciiTree();
		form_4.createAsciiTree();

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
		form_0.randomRequestRobotomy();
		form_1.randomRequestRobotomy();
		form_2.randomRequestRobotomy();
		form_3.randomRequestRobotomy();
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
		form_0.informPardoned();
		form_1.informPardoned();
		form_2.informPardoned();
		form_3.informPardoned();
		std::cout << std::endl;
	}
#ifdef LEAKS
	system("leaks -q ex02");
#endif
}
