/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:13:38 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/12 14:37:47 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << GREEN << "++++++++++ Test Member Function. ++++++++++" << END << std::endl;
	{
		Bureaucrat	obj_0("name_0", 100);
		Form		form_0;
		Form		form_1("form_1", 100, 100);
		Form		form_2(form_1);

		std::cout << std::endl;
		std::cout << obj_0 << std::endl;
		std::cout << form_0 << std::endl;
		std::cout << form_1 << std::endl;
		std::cout << form_2 << std::endl;
		std::cout << std::endl;

		obj_0.signForm(form_1);
		obj_0.incrementGrade();
		obj_0.signForm(form_2);

		std::cout << std::endl;
		std::cout << obj_0 << std::endl;
		std::cout << form_1 << std::endl;
		std::cout << form_2 << std::endl;
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << GREEN << "++++++++++ Test Constructer exception. ++++++++++" << END << std::endl;
	{
		// try {
		Form	form_0("form_0", 1, 1);
		// }
		// catch (std::exception& e) {
		// 	std::cerr << RED << e.what() << END << std::endl;
		// }
		Form	form_1("form_1", 150, 150);
		std::cout << std::endl;

		try {
			Form	form_2("", 150, 150);
		}
		catch (std::exception& e) {
			std::cerr << RED << e.what() << END << std::endl;
		}
		std::cout << std::endl;

		try {
			Form	form_3("form_3", 0, 1);
		}
		catch (std::exception& e) {
			std::cerr << RED << e.what() << END << std::endl;
		}
		std::cout << std::endl;

		try {
			Form	form_4("form_4", 1, 0);
		}
		catch (std::exception& e) {
			std::cerr << RED << e.what() << END << std::endl;
		}
		std::cout << std::endl;

		try {
			Form	form_5("form_5", 151, 150);
		}
		catch (std::exception& e) {
			std::cerr << RED << e.what() << END << std::endl;
		}
		std::cout << std::endl;

		try {
			Form	form_6("form_4", 150, 151);
		}
		catch (std::exception& e) {
			std::cerr << RED << e.what() << END << std::endl;
		}
		std::cout << std::endl;

		std::cout << form_0 << std::endl;
		std::cout << form_1 << std::endl;
		// std::cout << form_2 << std::endl;
		// std::cout << form_3 << std::endl;
		// std::cout << form_4 << std::endl;
		// std::cout << form_5 << std::endl;
		// std::cout << form_6 << std::endl;
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << GREEN << "++++++++++ Test signForm();. ++++++++++" << END << std::endl;
	{
		Form		form_0("form_0", 75, 75);
		Form		form_1("form_1", 75, 75);
		Form		form_2("form_2", 75, 75);
		Bureaucrat	obj_0("obj_0", 75);

		obj_0.signForm(form_0);
		try {
			obj_0.incrementGrade();
		}
		catch (std::exception& e) {
			std::cerr << RED << e.what() << END << std::endl;
		}
		obj_0.signForm(form_1);
		obj_0.signForm(form_0);
		try {
			obj_0.decrementGrade();
			obj_0.decrementGrade();
		}
		catch (std::exception& e) {
			std::cerr << RED << e.what() << END << std::endl;
		}
		obj_0.signForm(form_2);
		std::cout << std::endl;
		std::cout << form_0 << std::endl;
		std::cout << form_1 << std::endl;
		std::cout << form_2 << std::endl;
		std::cout << std::endl;
	}
#ifdef LEAKS
	system("leaks -q ex01");
#endif
}
