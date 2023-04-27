/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline_prompt.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/27 20:20:20 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

bool	getline_prompt(std::string prompt, std::string *line)
{
	std::cout << prompt;
	std::cin.clear();
	if (std::getline(std::cin, *line) == false) {
		if (std::cin.eof() == true || std::cin.fail() == true) {
			std::cout << "\nlog out." << std::endl;
		}
		return (false);
	}
	return (true);
}
