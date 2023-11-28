/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:59:46 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/28 14:48:10 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main()
{
	// eof() == true, fail() == true
	std::ifstream	fd("exist_file");

	// eof() == false, fail() == true
	// std::ifstream	fd("not_exist_file");

	// eof() == true, fail() == true
	// std::ifstream	fd("empty_file");

	std::cout << fd << std::endl;

	std::string		str;
	if (std::getline(fd, str, '\n')) {
		std::cout << "true  : " << fd << std::endl;
	}
	else {
		std::cout << "false : " << fd << std::endl;
	}

	std::cout << "\n++++++++++++++++++++++++++++++" << std::endl;
	while (std::getline(fd, str, '\n')) {
		std::cout << fd << std::endl;
		// std::cout << str << std::endl;
	}
	std::cout << "++++++++++++++++++++++++++++++\n" << std::endl;

	std::cout << fd << std::endl;

	if (fd.eof()) {
		std::cout << "eof" << std::endl;
	}
	if (fd.fail()) {
		std::cout << "fail" << std::endl;
	}
}
