/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/17 10:34:30 by hnoguchi         ###   ########.fr       */
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

static bool	ftIsDigit(const char c)
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

static void	printFloat(float f, const bool setPrecision = false, const bool impossible = false)
{
	std::cout << "float : " << std::flush;
	if (impossible == true) {
		std::cout << "impossible" << std::endl;
	}
	else if (setPrecision == true || (static_cast<int>(f) - f) == 0) {
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	else {
		std::cout << f << "f" << std::endl;
	}
}

static void	printDouble(const double d, const bool setPrecision = false, const bool impossible = false)
{
	std::cout << "double: " << std::flush;
	if (impossible == true) {
		std::cout << "impossible" << std::endl;
	}
	else if (setPrecision == true) {
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	}
	else {
		std::cout << d << std::endl;
	}
}

static void	convertChar(unsigned int i)
{
	printChar(i);
	printInt(i);
	printFloat(static_cast<float>(i), true);
	printDouble(static_cast<const double>(i), true);
}

static void	convertInt(std::string& str)
{
	try {
		int	i = std::stoi(str);
		if (i < 0 || 127 < i) {
			printChar(0, true);
		}
		else {
			printChar(i);
		}
		printInt(i);
		printFloat(static_cast<float>(i), true);
		printDouble(static_cast<const double>(i), true);
		return ;
	}
	catch (std::exception& e) {
			printChar(0, true);
			printInt(0, true);
	}

	try {
		float	f = std::stof(str);
		printFloat(f, true);
	}
	catch (std::exception& e) {
		printFloat(0, true, true);
	}

	try {
		double	d = std::stod(str);
		printDouble(d, true);
	}
	catch (std::exception& e) {
		printDouble(0, true, true);
	}
}

static void	convertFloat(std::string& str)
{
	try {
		float	f = std::stof(str);
		if (f < 0 || 127 < f) {
			printChar(0, true);
		}
		else {
			printChar(static_cast<const char>(f));
		}
		printInt(static_cast<const int>(f));
		printFloat(f, false);
		printDouble(static_cast<const double>(f));
	}
	catch (std::exception& e) {
			printChar(0, true);
			printInt(0, true);
			printFloat(0, false, true);
			printDouble(0, false, true);
	}
}

static void	convertDouble(std::string& str)
{
	try {
		double	d = std::stod(str);
		if (d < 0 || 127 < d) {
			printChar(0, true);
		}
		else {
			printChar(static_cast<const char>(d));
		}
		printInt(static_cast<const int>(d));
		printFloat(static_cast<float>(d), false);
		printDouble(d);
	}
	catch (std::exception& e) {
			printChar(0, true);
			printInt(0, true);
			printFloat(0, false, true);
			printDouble(0, false, true);
	}
}

// SUBJECT FUNC
void	ScalarConverter::convert(std::string& str)
{
	if (str.length() == 1 && !ftIsDigit(str[0])) {
		convertChar(static_cast<const unsigned int>(str[0]));
	}
	else if (str.find('.') != std::string::npos) {
		if (str.back() == 'f') {
			convertFloat(str);
		}
		else {
			convertDouble(str);
		}
	}
	else {
		convertInt(str);
	}
}
