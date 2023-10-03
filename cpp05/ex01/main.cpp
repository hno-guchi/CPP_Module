/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:13:38 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/03 16:27:10 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// static void	printData(const std::string& name, const Bureaucrat& rhs)
// {
// 	std::cout
// 		<< "----- " << name << " -----\n" \
// 		<< "[name]  : " << rhs.getName() << "\n" \
// 		<< "[grade] : " << rhs.getGrade() << "\n" \
// 		<< "-----------------\n" << std::endl;
// }

int	main()
{
	std::cout << GREEN << "++++++++++ Test Member Function. ++++++++++" << END << std::endl;
	{
		Bureaucrat	obj_0;
		Bureaucrat	obj_1("name_1", 100);
		Bureaucrat	obj_2(obj_1);

		std::cout << std::endl;
		std::cout << obj_0 << std::endl;
		std::cout << obj_1 << std::endl;
		std::cout << obj_2 << std::endl;

		obj_1.incrementGrade(); obj_1.incrementGrade();
		obj_2.decrementGrade(); obj_2.decrementGrade();

		std::cout << std::endl;
		std::cout << obj_1 << std::endl;
		std::cout << obj_2 << std::endl;
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << GREEN << "++++++++++ Test Constructer exception. ++++++++++" << END << std::endl;
	{
		Bureaucrat	obj_0("name_0", 1);
		Bureaucrat	obj_1("name_1", 150);
		Bureaucrat	obj_2("name_2", 0);
		Bureaucrat	obj_3("name_3", 151);

		std::cout << std::endl;
		std::cout << obj_0 << std::endl;
		std::cout << obj_1 << std::endl;
		std::cout << obj_2 << std::endl;
		std::cout << obj_3 << std::endl;
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << GREEN << "++++++++++ Test incremet / decrement. ++++++++++" << END << std::endl;
	{
		Bureaucrat	obj_0("name_0", 1);
		Bureaucrat	obj_1("name_1", 150);

		try {
			obj_0.incrementGrade();
		}
		catch (std::exception& e) {
			std::cerr << RED << e.what() << END << std::endl;
		}
		try {
			obj_1.decrementGrade();
		}
		catch (std::exception& e) {
			std::cerr << RED << e.what() << END << std::endl;
		}
		std::cout << std::endl;
		std::cout << obj_0 << std::endl;
		std::cout << obj_1 << std::endl;
		std::cout << std::endl;
	}
#ifdef LEAKS
	system("leaks -q ex01");
#endif
}
