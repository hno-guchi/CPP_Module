/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:18:31 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/11 18:14:22 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <locale>

int	main(int argc, char *argv[])
{
	std::string	error_message("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
	std::string	str;
	std::locale	l = std::locale::classic();

	if (argc == 1) {
		std::cerr << error_message << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++) {
		str = argv[i];
		for (int j = 0; str[j] != '\0'; j++) {
			std::cout << (char)std::toupper(str[j], l) << std::flush;
		}
	}
	std::cout << std::endl;
}

// char	ft_toupper(char c)
// {
// 	if ('a' <= c && c <= 'z') {
// 		return ('A' + (c - 'a'));
// 	}
// 	return (c);
// }
// static std::string	str_toupper(char *str)
// {
// 	std::string	uppered_str;
// 
// 	for (int i = 0; str[i] != '\0'; i++) {
// 		uppered_str += ft_toupper(str[i]);
// 	}
// 	return (uppered_str);
// }

// int	main(int argc, char *argv[])
// {
// 	std::string	error_message("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
// 	std::string	str;
// 
// 	if (argc == 1) {
// 		std::cerr << error_message << std::endl;
// 		return (1);
// 	}
// 	for (int i = 1; i < argc; i++) {
// 		str = str_toupper(argv[i]);
// 		std::cout << str << std::flush;
// 	}
// 	std::cout << std::endl;
// }
