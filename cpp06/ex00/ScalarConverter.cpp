/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/12 18:42:17 by hnoguchi         ###   ########.fr       */
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

static bool	ftIsPrint(const char& c)
{
	std::locale	l = std::locale::classic();

	return (std::isprint(c, l));
}

static bool	ftIsDigit(char c)
{
	std::locale	l = std::locale::classic();

	return (std::isdigit(c, l));
}

static void	printChar(const char& c)
{
	std::cout << "char: " << std::flush;
	if (ftIsPrint(c)) {
		std::cout << c << std::endl;
	}
	else {
		std::cout << "Non displayable" << std::endl;
	}
}

static void	printInt(const int& i)
{
	std::cout << "int: " << std::flush;
	std::cout << i << std::endl;
}

static void	printFloat(const float& f)
{
	std::cout << "float: " << std::flush;
	std::cout << f << std::endl;
}

static void	printDouble(const double& d)
{
	std::cout << "double: " << std::flush;
	std::cout << d << std::endl;
}

static void	convertChar(char c)
{
	printChar(c);
	printInt(static_cast<const int&>(c));
	printFloat(static_cast<const float&>(c));
	printDouble(static_cast<const double&>(c));
}

// convertDouble(); -> find("."); not std::setprecision
// convertInt(); -> find("."); not std::setprecision(1);
// floatの出力は、最後にfを出力する。

// SUBJECT FUNC
void	ScalarConverter::convert(std::string& str)
{
	// if (str.length() == 1 && !ftIsDigit(str[0])) {
	if (str.length() == 1) {
		convertChar(str[0]);
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
}
