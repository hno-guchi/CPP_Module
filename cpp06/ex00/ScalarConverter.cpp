/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/13 10:59:19 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// CONSTRUCTER
// DESTRUCTER
// OPERATOR
// GETTER
// SETTER

static bool	ftIsPrint(const char c)
{
	std::locale	l = std::locale::classic();

	return (std::isprint(c, l));
}

static bool	ftIsDigit(char c)
{
	std::locale	l = std::locale::classic();

	return (std::isdigit(c, l));
}

static void	printChar(const char c, const bool impossible = false)
{
	std::cout << "char  : " << std::flush;
	if (impossible == true) {
		std::cout << "impossible" << std::endl;
	}
	else if (ftIsPrint(c)) {
		std::cout << "'" << c << "'" << std::endl;
	}
	else {
		std::cout << "Non displayable" << std::endl;
	}
}

static void	printInt(const int i, const bool impossible = false)
{
	std::cout << "int   : " << std::flush;
	if (impossible == true) {
		std::cout << "impossible" << std::endl;
	}
	else {
		std::cout << i << std::endl;
	}
}

static void	printFloat(const float f, const bool setPrecision = false)
{
	std::cout << "float : " << std::flush;
	if (setPrecision == true) {
		std::cout << std::fixed << std::setprecision(1) << f << std::flush;
	}
	else {
		std::cout << f << std::flush;
	}
	std::cout << "f" << std::endl;
}

static void	printDouble(const double d, const bool setPrecision = false)
{
	std::cout << "double: " << std::flush;
	if (setPrecision == true) {
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	}
	else {
		std::cout << d << std::endl;
	}
}

static void	convertChar(const unsigned int i)
{
	printChar(i);
	printInt(i);
	printFloat(static_cast<const float>(i), true);
	printDouble(static_cast<const double>(i), true);
}

static void	convertInt(const int i)
{
	if (i < 0 || 127 < i) {
		printChar(0, true);
	}
	else {
		printChar(i);
	}
	printInt(i);
	printFloat(static_cast<const float>(i), true);
	printDouble(static_cast<const double>(i), true);
}

static void	convertDouble(const double d)
{
	if (d < 0 || 127 < d) {
		printChar(0, true);
	}
	else {
		printChar(d);
	}
	printInt(static_cast<const int>(d));
	printFloat(static_cast<const float>(d));
	printDouble(d);
}

// SUBJECT FUNC
void	ScalarConverter::convert(std::string& str)
{
	if (str.length() == 1 && !ftIsDigit(str[0])) {
		convertChar(static_cast<const unsigned int>(str[0]));
	}
	else if (str.find('.') == std::string::npos) {
		try {
			int	i = std::stoi(str);
			convertInt(i);
		}
		catch (std::exception& e) {
			std::cerr << RED << e.what() << END << std::endl;
		}
	}
	else {
		try {
			double	d = std::stod(str);
			convertDouble(d);
		}
		catch (std::exception& e) {
			std::cerr << RED << e.what() << END << std::endl;
		}
	}
}
