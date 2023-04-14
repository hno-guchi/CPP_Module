/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:50:53 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/14 15:53:42 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0

入力ファイルストリーム(std::ifstream)
#include <fstream>
std::ofstream 型変数の生存期間が終了する際に、close();される。
（このような仕組みを「デストラクタ」と呼ぶ。）

#endif

#include <fstream>
#include <iostream>

int	main()
{
	// Success
	std::ifstream	input("hello.txt");
	if (input == NULL)
	{
		std::cerr << "Failed: input(\"hello.txt\");" << std::endl;
		// return 1;
	}
	else
	{
		std::string	str;
		if (!(input >> str))
		{
			std::cerr << "Failed: (input >> str);" << std::endl;
		}
		std::cout << str << std::endl;
	}

	// empty str
	std::ifstream	input_2("");
	if (input_2 == NULL)
	{
		std::cerr << "Failed: input_2(\"\");" << std::endl;
	}
	else
	{
		std::string	str_2;
		if (!(input_2 >> str_2))
		{
			std::cerr << "Failed: (input_2 >> str_2);" << std::endl;
		}
		std::cout << str_2 << std::endl;
	}

	// Not args
	// std::ifstream	input_3();
	// if (input_3 == NULL)
	// {
	// 	std::cerr << "Failed: input_3();" << std::endl;
	// }
	// else
	// {
	// 	std::string	str_3;
	// 	if (!(input_3 >> str_3))
	// 	{
	// 		std::cerr << "Failed: (input_3 >> str_3);" << std::endl;
	// 	}
	// 	std::cout << str_3 << std::endl;
	// }

	// Not ()
	std::ifstream	input_4;
	if (input_4 == NULL)
	{
		std::cerr << "Failed: input_4;" << std::endl;
	}
	else
	{
		std::string	str_4;
		if (!(input_4 >> str_4))
		{
			std::cerr << "Failed: (input_4 >> str_4);" << std::endl;
		}
		std::cout << str_4 << std::endl;
	}

	// NULL
	std::ifstream	input_5(NULL);
	if (input_5 == NULL)
	{
		std::cerr << "Failed: input_5(NULL);" << std::endl;
	}
	else
	{
		std::string	str_5;
		if (!(input_5 >> str_5))
		{
			std::cerr << "Failed: (input_5 >> str_5);" << std::endl;
		}
		std::cout << str_5 << std::endl;
	}
}
