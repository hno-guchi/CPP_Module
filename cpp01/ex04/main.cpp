/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:14:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/10 12:32:37 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char *argv[])
{
	if (argc != 4) {
		std::cerr << "Error: Invalid arguments." << std::endl;
		return (1);
	}
	// check args (s1 != s2) s1[0] == isspace()
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	if (s1 == s2) {
		std::cerr << "Error: s1 == s2." << std::endl;
		return (1);
	}
	// open file
	std::ifstream	sourceFile(argv[1]);
	std::string		line;
	if (sourceFile.is_open() == false) {
		std::cerr << "Error: Failed open." << std::endl;
		return (1);
	}
	std::ofstream	replaceFile();
	// read file (new line)
	while (std::getline(sourceFile, line, '\n')) {
		if (sourceFile.fail() == true) {
			std::cerr << "Error: Failed getline." << std::endl;
			break ;
		}
		std::cout << line << std::endl;
	}
	sourceFile.close();
	// replace
	// create new file
	// write data.
}
