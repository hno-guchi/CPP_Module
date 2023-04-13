/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:18:31 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/13 19:08:21 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

static void	str_toupper(std::string *str)
{
	const std::string::const_iterator	iter_end = str->end();
	for (std::string::iterator iter = str->begin(); iter != iter_end; iter++)
	{
		*iter = std::toupper(*iter);
	}
}

int	main(int argc, char *argv[])
{
	std::string	error_message("* LOUD AND UNBEARABLE FEEDBACK NOISE *");

	if (argc == 1)
	{
		std::cerr << error_message << std::endl;
		return (1);
	}

	std::string	str;
	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		str_toupper(&str);
		std::cout << str << std::flush;
	}
	std::cout << std::endl;
}
