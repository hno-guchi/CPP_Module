/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:18:31 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/13 15:22:17 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/*
std::string *str_toupper(char *str)
{
	std::string	upper_str(str);
	std::size_t	str_size = upper_str.size();

	for (std::size_t i = 0; i < str_size; i++)
	{
		if ()
	}
}
*/

int	main(int argc, char *argv[])
{
	std::string	error_message("* LOUD AND UNBEARABLE FEEDBACK NOISE *");

	if (argc == 1)
	{
		std::cerr << error_message << std::endl;
		return (1);
	}

	for (int i = 1; i < argc; i++)
	{
		std::cout << argv[i] << std::flush;
	}
	std::cout << std::endl;
}
