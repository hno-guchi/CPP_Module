/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:13:38 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/04 17:38:36 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

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

	// std::cout << GREEN << "++++++++++ Test signForm();. ++++++++++" << END << std::endl;
	// {
	// 	Form		form_0("form_0", 75, 75);
	// 	Form		form_1("form_1", 75, 75);
	// 	Form		form_2("form_2", 75, 75);
	// 	Bureaucrat	obj_0("obj_0", 75);

	// 	obj_0.signForm(form_0);
	// 	try {
	// 		obj_0.incrementGrade();
	// 	}
	// 	catch (std::exception& e) {
	// 		std::cerr << RED << e.what() << END << std::endl;
	// 	}
	// 	obj_0.signForm(form_1);
	// 	obj_0.signForm(form_0);
	// 	try {
	// 		obj_0.decrementGrade();
	// 		obj_0.decrementGrade();
	// 	}
	// 	catch (std::exception& e) {
	// 		std::cerr << RED << e.what() << END << std::endl;
	// 	}
	// 	obj_0.signForm(form_2);
	// 	std::cout << std::endl;
	// 	std::cout << form_0 << std::endl;
	// 	std::cout << form_1 << std::endl;
	// 	std::cout << form_2 << std::endl;
	// 	std::cout << std::endl;
	// }
#ifdef LEAKS
	system("leaks -q ex02");
#endif
}
