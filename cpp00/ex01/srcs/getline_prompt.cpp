/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline_prompt.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/28 18:10:49 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

int	getline_prompt(std::string prompt, std::string *line)
{
	char	buffer[111];

	std::cout << prompt;
	std::cin.clear(std::ios::goodbit);
	std::cin.width(110);
	std::cin.getline(buffer, 110);
	if (std::cin.eof() == true) {
		std::cout << "\nlog out." << std::endl;
		return (-1);
	} else if (std::cin.fail() == true) {
		std::cout << "\nPhoneBook: Fatal error: std::cin" << std::endl;
		return (-1);
	}
	*line = buffer;
	return (0);
}

// bool	getline_prompt(std::string prompt, std::string *line)
// {
// 	std::cout << prompt;
// 	std::cin.clear(std::ios::goodbit);
// 	std::cin.width(110);
// 	if (std::getline(std::cin, *line) == false) {
// 		if (std::cin.eof() == true || std::cin.fail() == true) {
// 			std::cout << "\nlog out." << std::endl;
// 		}
// 		return (false);
// 	}
// 	return (true);
// }
// int	main()
// {
// 	std::string	line;
// 
// 	while (1) {
// 		if (getline_prompt("sample : ", &line) < 0) {
// 			std::cout << "\nlog out." << std::endl;
// 			return (0);
// 		}
// 		if (line == "") {
// 			continue ;
// 		}
// 		if (line == "ADD") {
// 			while (1) {
// 				std::string	data;
// 
// 				if (getline_prompt("ADD : ", &data) < 0) {
// 					if (std::cin.eof() == true) {
// 						std::cout << "eof() == true\n" << std::endl;
// 						std::cin.clear(std::ios::goodbit);
// 						break;
// 					} else if (std::cin.fail() == true) {
// 						std::cout << "fail() == true\n" << std::endl;
// 						return (0);
// 					}
// 				}
// 				if (data == "") {
// 					continue ;
// 				}
// 				std::cout << data << std::endl;
// 				break ;
// 			}
// 		}
// 		std::cout << line << std::endl;
// 	}
// }
