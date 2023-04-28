/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline_prompt.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/28 11:42:22 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

bool	getline_prompt(std::string prompt, std::string *line)
{
	std::cout << prompt;
	std::cin.clear(std::ios::goodbit);
	std::cin.width(300);
	if (std::getline(std::cin, *line) == false) {
		if (std::cin.eof() == true || std::cin.fail() == true) {
			std::cout << "\nlog out." << std::endl;
		}
		return (false);
	}
	return (true);
}
