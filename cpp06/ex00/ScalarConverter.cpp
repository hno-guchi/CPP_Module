/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/19 09:47:57 by hnoguchi         ###   ########.fr       */
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

static void	convertCharFromInt(const int i)
{
	if (i < 0 || 127 < i) {
		printChar(0, true);
	}
	else {
		printChar(static_cast<const char>(i));
	}
}

static void	convertCharFromFloat(const float f)
{
	if (f < 0.0f || 127.0f < f) {
		printChar(0, true);
	}
	else {
		printChar(static_cast<const char>(f));
	}
}

static void	convertCharFromDouble(const double d)
{
	if (d < 0.0 || 127.0 < d) {
		printChar(0, true);
	}
	else {
		printChar(static_cast<const char>(d));
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

static void	convertIntFromFloat(const float f)
{
	if (f < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < f) {
		printInt(0, true);
	}
	else {
		printInt(static_cast<const int>(f));
	}
}

static void	convertIntFromDouble(const double d)
{
	if (d < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < d) {
		printInt(0, true);
	}
	else {
		printInt(static_cast<const int>(d));
	}
}

static bool	isExistDecimal(float f)
{
	if (f < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < f) {
		return (true);
	}
	if ((f - static_cast<int>(f)) != 0) {
		return (true);
	}
	return (false);
}

static void	printFloat(float f, const bool setPrecision = false, const bool impossible = false)
{
	std::cout << "float : " << std::flush;
	if (impossible == true) {
		std::cout << "impossible" << std::endl;
	}
	else if (setPrecision == true || !isExistDecimal(f)) {
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	else {
		std::cout << f << "f" << std::endl;
	}
}

static void	convertFloatFromDouble(const double d)
{
	if (d < -(std::numeric_limits<float>::max()) || std::numeric_limits<float>::max() < d) {
		printFloat(0, true);
	}
	else {
		printFloat(static_cast<const float>(d));
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

static void	convertChar(unsigned char i)
{
	printChar(i);
	printInt(static_cast<int>(i));
	printFloat(static_cast<float>(i), true);
	printDouble(static_cast<const double>(i), true);
}

static void	convertInt(std::string& str)
{
	try {
		int	i = std::stoi(str);

		convertCharFromInt(i);
		printInt(i);
		printFloat(static_cast<const float>(i), true);
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

		convertCharFromFloat(f);
		convertIntFromFloat(f);
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

		convertCharFromDouble(d);
		convertIntFromDouble(d);
		convertFloatFromDouble(d);
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
		convertChar(static_cast<unsigned char>(str[0]));
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
