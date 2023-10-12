/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:13:38 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/12 16:22:51 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	std::cout << GREEN << "++++++++++ Test Intern ++++++++++" << END << std::endl;
	{
		Intern					intern_0;
		AForm*					ptr;

		std::cout << std::endl;
		ptr = intern_0.makeForm("shrubbery creation", "form_0");
		std::cout << "ptr : [" << GREEN << ptr << END << "] | " << "makeForm(\"shrubbery creation\", \"form_0\");" << std::endl;
		delete ptr;

		std::cout << std::endl;
		ptr = intern_0.makeForm("robotomy request", "Bender");
		std::cout << "ptr : ["<< GREEN << ptr << END << "] | " << "makeForm(\"robotomy request\", \"Bender\");" << std::endl;
		delete ptr;

		std::cout << std::endl;
		ptr = intern_0.makeForm("presidential pardon", "form_1");
		std::cout << "ptr : ["<< GREEN << ptr << END << "] | " << "makeForm(\"presidential pardon\", \"form_1\");" << std::endl;
		delete ptr;

		std::cout << std::endl;
		ptr = intern_0.makeForm("WRONG FORM", "form_2");
		std::cout << "ptr : ["<< GREEN << ptr << END << "] | " << "makeForm(\"WRONG FORM\", \"form_2\");" << std::endl;
		delete ptr;

		std::cout << std::endl;
		ptr = intern_0.makeForm("", "form_3");
		std::cout << "ptr : ["<< GREEN << ptr << END << "] | " << "makeForm(\"\", \"form_3\");" << std::endl;
		delete ptr;

		std::cout << std::endl;
	}
#ifdef LEAKS
	system("leaks -q ex03");
#endif
}
