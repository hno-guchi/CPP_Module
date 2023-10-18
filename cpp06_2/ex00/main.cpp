/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:46:07 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/17 17:29:17 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "color.hpp"

#ifndef TEST

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

#else // #ifdef TEST

int	main()
{
	std::string	str;

	// EXCEPTION
	str = "";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "0";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "255";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "-2147483649";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "-2147483648";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "2147483647";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "2147483648";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "-3.40282e+38";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "-3.40283e+38";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "1.17549e-38";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "1.17550e-38";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "3.40282e+38";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "3.40283e+38";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "-1.79769e+308";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "-1.79770e+308";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "2.22507e-308";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "2.22508e-308";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "1.79769e+308";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "1.79770e+308";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;

	// CHAR
	str = "a";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "~";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;

	// INT
	str = "0";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "42";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "-42";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;

	// FLOAT
	str = "0.0f";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "-4.2f";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "4.2f";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "inff";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "-inff";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "+inff";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "nanf";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;

	// DOUBLE
	str = "0.0";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "-4.2";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "4.2";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "inf";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "-inf";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "+inf";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
	str = "nan";
	std::cout << GREEN << "========== [" << END << str << GREEN << "] ==========" << END << std::endl;
	ScalarConverter::convert(str); std::cout << std::endl;
}

#endif // TEST
