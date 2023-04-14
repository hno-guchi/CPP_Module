/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Eof.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:49:16 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/14 18:00:08 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int	main()
{
	// Success
	std::ifstream	input("hello.txt");
	if (input == NULL)
	{
		std::cerr << "Failed: input(\"hello.txt\");" << std::endl;
		// return 1;
	}
	while (!(input.eof()))
	{
		char	c;
		input.get(c);
		std::cout << c;
	}
	std::cout << std::flush;

	// 
	std::ifstream	input("hello.txt");
	if (input == NULL)
	{
		std::cerr << "Failed: input(\"hello.txt\");" << std::endl;
		// return 1;
	}
	while (!(input.eof()))
	{
		char	c;
		input.get(c);
		std::cout << c;
	}
	std::cout << std::flush;
}
