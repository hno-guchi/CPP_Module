/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:13:38 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/03 14:48:21 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	printData(const std::string& name, const Bureaucrat& rhs)
{
	std::cout
		<< "----- " << name << " -----\n" \
		<< "[name]  : " << rhs.getName() << "\n" \
		<< "[grade] : " << rhs.getGrade() << "\n" \
		<< "-----------------\n" << std::endl;
}

int	main()
{
	// Test Member Function
	{
		Bureaucrat	obj_0;
		Bureaucrat	obj_1("name_1", 100);
		Bureaucrat	obj_2(obj_1);

		printData("obj_0", obj_0);
		printData("obj_1", obj_1);
		printData("obj_2", obj_2);

		obj_1.incrementGrade(); obj_1.incrementGrade();
		obj_2.decrementGrade(); obj_2.decrementGrade();

		printData("obj_1", obj_1);
		printData("obj_2", obj_2);
	}

	std::cout << std::endl;

	// Test Constructer exception.
	{
		Bureaucrat	obj_0("name_0", 1);
		Bureaucrat	obj_1("name_1", 150);
		Bureaucrat	obj_2("name_2", 0);
		Bureaucrat	obj_3("name_3", 151);

		printData("obj_0", obj_0);
		printData("obj_1", obj_1);
		printData("obj_2", obj_2);
		printData("obj_3", obj_3);
	}

	std::cout << std::endl;

	// Test incremet / decrement
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
		printData("obj_0", obj_0);
		printData("obj_1", obj_1);
	}
}
