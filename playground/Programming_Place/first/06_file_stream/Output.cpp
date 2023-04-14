/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Output.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:50:53 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/14 15:17:34 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0

出力ファイルストリーム(std::ofstream)
#include <fstream>
std::ofstream 型変数の生存期間が終了する際に、close();される。
（このような仕組みを「デストラクタ」と呼ぶ。）

#endif

#include <fstream>
#include <iostream>

int	main()
{
	// Success
	std::ofstream	output("hello.txt");
	if (output == NULL)
	{
		std::cerr << "Failed: output(\"hello.txt\");" << std::endl;
		// return 1;
	}
	output << "Hello, world" << std::endl;

	// Empty string
	std::ofstream	output_2("");
	if (output_2 == NULL)
	{
		std::cerr << "Failed: output_2(\"\");" << std::endl;
		// return 1;
	}
	else
	{
		output_2 << "Hello, world" << std::endl;
	}

	// Not args -> invalid error
	// std::ofstream	output_3();
	// if (output_3 == NULL)
	// {
	// 	std::cerr << "Failed: output_3();" << std::endl;
	// 	// return 1;
	// }
	// else
	// {
	// 	output_3 << "Hello, world" << std::endl;
	// }

	// Not ()
	std::ofstream	output_4;
	if (output_4 == NULL)
	{
		std::cerr << "Failed: output_4;" << std::endl;
		// return 1;
	}
	else
	{
		std::cout << output_4 << std::endl;
		output_4 << "output_4" << std::endl;
	}
}
