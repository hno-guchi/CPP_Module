/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/11 19:12:34 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// CONSTRUCTER
// DESTRUCTER
// OPERATOR
// ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& rhs)
// {
// 	if (this == &rhs) {
// 		return (*this);
// 	}
// 	debugMessage("ScalarConverter", COPY_OPERATOR);
// 	return (*this);
// }

// GETTER

// SETTER

static bool	ftIsPrint(char c)
{
	std::locale	l = std::locale::classic();

	return (std::isprint(c, l));
}

static void	printChar(unsigned int c)
{
	std::cout << "char:" << std::flush;
	if (ftIsPrint(c)) {
		std::cout << c << std::endl;
	}
	else {
		std::cout << NON_DISPLAYABLE_MESSAGE << std::endl;
	}
}

// static bool	ftIsDigit(char c)
// {
// 	std::locale	l = std::locale::classic();
// 
// 	return (std::isdigit(c, l));
// }
// 
// SUBJECT FUNC
void	ScalarConverter::convert(std::string& str)
{
	// if (str.length() == 1 && !ftIsDigit(str[0])) {
	if (str.length() == 1) {
		printChar(str[0]);
		// convertChar(str);
	}
	else {
		std::cout << "Over one." << std::endl;
	}
	// else if () {
	// 	convertDouble(str);
	// }
	// else {
	// 	convertInt(str);
	// }
	// std::cout << "char:" << std::endl;
	// std::cout << "int:" << std::endl;
	// std::cout << "float:" << std::endl;
	// std::cout << "double:" << std::endl;
	// std::cout << str << std::endl;
}
