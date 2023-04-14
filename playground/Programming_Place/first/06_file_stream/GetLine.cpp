/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetLine.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:50:53 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/14 17:49:06 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0

行単位の操作（std::getline）
改行を区切り文字として扱う。改行自体は、出力しない。
第３引数で、区切り文字の指定が可能

#include <string>

#endif

#include <fstream>
#include <iostream>
#include <string>

int	main()
{
	// Success
	std::ifstream	input_1("hello.txt");
	if (input_1 == NULL)
	{
		std::cerr << "Failed: input_1(\"hello.txt\");" << std::endl;
		// return 1;
	}
	std::string	str_1;
	if (!(std::getline(input_1, str_1)))
	{
		std::cerr << "Failed: std::getline(input_1, str_1);" << std::endl;
		// return 1;
	}
	else
	{
		std::cout << str_1 << std::endl;
	}

	// Empty_str
	std::ifstream	input_2("");
	if (input_2 == NULL)
	{
		std::cerr << "Failed: input_2(\"\");" << std::endl;
		// return 1;
	}
	std::string	str_2;
	if (!(std::getline(input_2, str_2)))
	{
		std::cerr << "Failed: std::getline(input_2, str_2);" << std::endl;
		// return 1;
	}
	else
	{
		std::cout << str_2 << std::endl;
	}

	// Not args
	// std::ifstream	input_3();
	// if (input_3 == NULL)
	// {
	// 	std::cerr << "Failed: input_3();" << std::endl;
	// 	// return 1;
	// }
	// std::string	str_3;
	// if (!(std::getline(input_3, str_3)))
	// {
	// 	std::cerr << "Failed: std::getline(input_2, str_3);" << std::endl;
	// 	// return 1;
	// }
	// else
	// {
	// 	std::cout << str_3 << std::endl;
	// }

	// NULL
	std::ifstream	input_4(NULL);
	if (input_4 == NULL)
	{
		std::cerr << "Failed: input_4();" << std::endl;
		// return 1;
	}
	std::string	str_4;
	if (!(std::getline(input_4, str_4)))
	{
		std::cerr << "Failed: std::getline(input_4, str_4);" << std::endl;
		// return 1;
	}
	else
	{
		std::cout << str_4 << std::endl;
	}

	// Not ();
	std::ifstream	input_5;
	if (input_5 == NULL)
	{
		std::cerr << "Failed: input_5;" << std::endl;
		// return 1;
	}
	std::string	str_5;
	if (!(std::getline(input_5, str_5)))
	{
		std::cerr << "Failed: std::getline(input_5, str_5);" << std::endl;
		// return 1;
	}
	else
	{
		std::cout << str_5 << std::endl;
	}
}
