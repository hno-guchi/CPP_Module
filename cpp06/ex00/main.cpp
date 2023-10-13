/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:46:07 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/13 09:24:46 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "color.hpp"
// #include <string>
// #include <iostream>
// #include <iomanip>

int	main(int argc, char **argv)
{
	if (argc == 1) {
		std::cerr << RED << "Please pass the arguments." << END << std::endl;
		return (1);
	}
	std::string	str = argv[1];
	ScalarConverter::convert(str);
	// std::cout << std::stoi(str) << std::endl;

	// std::cout << std::endl;
	// std::cout << GREEN << "++++++++++ float manip ++++++++++" << END << std::endl;
	// std::cout << "std::fixed << std::setprecision(1) << std::stof(str) : [" << std::fixed << std::setprecision(1) << std::stof(str) << "]" << std::endl;
	// std::cout << "std::fixed << std::hexfloat << std::stof(str)        : [" << std::fixed << std::hexfloat << std::stof(str) << "]" << std::endl;
	// std::cout << "std::fixed << std::defaultfloat << std::stof(str)    : [" << std::fixed <<  std::defaultfloat << std::stof(str) << "]" << std::endl;

	// std::cout << std::endl;
	// std::cout << GREEN << "++++++++++ double manip ++++++++++" << END << std::endl;
	// std::cout << std::fixed << std::setprecision(1) << std::stod(str) << std::endl;
}
