/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:29:55 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/20 16:36:38 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "color.hpp"
#include <iostream>

#ifdef SWAP

int	main()
{
	int	a = 0;
	int	b = 100;
	std::cout << GREEN << "+++++++++ swap() test +++++++++++" << END << std::endl;
	std::cout << "Before : a = [" << a << "] " << "b = [" << b << "]" << std::endl;
	swap(a, b);
	std::cout << "After  : a = [" << a << "] " << "b = [" << b << "]" << std::endl;
	std::cout << std::endl;

	std::string aStr = "hello";
	std::string bStr = "World";
	std::cout << GREEN << "++++++++++++++++++++" << END << std::endl;
	std::cout << "Before : a = [" << aStr << "] " << "b = [" << bStr << "]" << std::endl;
	swap(aStr, bStr);
	std::cout << "After  : a = [" << aStr << "] " << "b = [" << bStr << "]" << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "++++++++++++++++++++" << END << std::endl;
	std::cout << "Before : a = [" << a << "] " << "b = [" << a << "]" << std::endl;
	swap(a, a);
	std::cout << "After  : a = [" << a << "] " << "b = [" << a << "]" << std::endl;
	std::cout << std::endl;

	// const int	c = 0;
	// const int	d = 0;
	// std::cout << GREEN << "+++++++++ swap() test +++++++++++" << END << std::endl;
	// std::cout << "Before : const c = [" << c << "] " << "const d = [" << d << "]" << std::endl;
	// swap(c, d);
	// std::cout << "After  : const c = [" << c << "] " << "const d = [" << d << "]" << std::endl;
	// std::cout << std::endl;
}

#elif MIN

int	main()
{
	int	a = 0;
	int	b = 100;
	int	result = -1;
	std::cout << GREEN << "+++++++++ min() test +++++++++++" << END << std::endl;
	std::cout << " value : a = [" << a << "] " << "b = [" << b << "]" << std::endl;
	result = min(a, b);
	std::cout << "result : [" << result << "]" << std::endl;
	std::cout << std::endl;

	float	c = -0.4;
	float	d = -0.3;
	float	resultF = -1;
	std::cout << GREEN << "++++++++++++++++++++" << END << std::endl;
	std::cout << " value : c = [" << c << "] " << "d = [" << d << "]" << std::endl;
	resultF = min(c, d);
	std::cout << "result : [" << resultF << "]" << std::endl;
	std::cout << std::endl;

	b = 0;
	result = -1;
	std::cout << GREEN << "++++++++++++++++++++" << END << std::endl;
	std::cout << "Before : a = [" << a << "] " << "b = [" << b << "]" << std::endl;
	std::cout << "       : a = [" << &a << "] " << "b = [" << &b << "]" << std::endl;
	result = min(a, b);
	std::cout << "result : [" << result << "]" << std::endl;
	std::cout << "       : [" << &result << "]" << std::endl;
	std::cout << std::endl;

	const int	e = 0;
	const int	f = 100;
	std::cout << GREEN << "++++++++++++++++++++" << END << std::endl;
	std::cout << "  value : const e = [" << e << "] " << "const f = [" << f << "]" << std::endl;
	const int	result2 = min(e, f);
	std::cout << "result2 : [" << result2 << "]" << std::endl;
	std::cout << std::endl;
}

#elif MAX

int	main()
{
	int	a = 0;
	int	b = 100;
	int	result = -1;
	std::cout << GREEN << "+++++++++ max() test +++++++++++" << END << std::endl;
	std::cout << " value : a = [" << a << "] " << "b = [" << b << "]" << std::endl;
	result = max(a, b);
	std::cout << "result : [" << result << "]" << std::endl;
	std::cout << std::endl;

	float	c = -0.4;
	float	d = -0.3;
	float	resultF = -1;
	std::cout << GREEN << "++++++++++++++++++++" << END << std::endl;
	std::cout << " value : c = [" << c << "] " << "d = [" << d << "]" << std::endl;
	resultF = max(c, d);
	std::cout << "result : [" << resultF << "]" << std::endl;
	std::cout << std::endl;

	b = 0;
	result = -1;
	std::cout << GREEN << "++++++++++++++++++++" << END << std::endl;
	std::cout << "Before : a = [" << a << "] " << "b = [" << b << "]" << std::endl;
	std::cout << "       : a = [" << &a << "] " << "b = [" << &b << "]" << std::endl;
	result = max(a, b);
	std::cout << "result : [" << result << "]" << std::endl;
	std::cout << "       : [" << &result << "]" << std::endl;
	std::cout << std::endl;

	const int	e = 0;
	const int	f = 100;
	std::cout << GREEN << "++++++++++++++++++++" << END << std::endl;
	std::cout << "  value : const e = [" << e << "] " << "const f = [" << f << "]" << std::endl;
	const int	result2 = max(e, f);
	std::cout << "result2 : [" << result2 << "]" << std::endl;
	std::cout << std::endl;
}

#elif SUB

int	main(void)
{
	int	a = 2;
	int	b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return (0);
}

#else

#include <string>

int	main(int argc, char *argv[])
{
	if (argc != 4) {
		std::cerr << "Please have 3 args. ~$ ./ex00 [Data type(int, float, double)] [value 1] [value 2]" << std::endl;
		return (0);
	}
	std::string	type = static_cast<std::string>(argv[1]);
	std::string	value1 = static_cast<std::string>(argv[2]);
	std::string	value2 = static_cast<std::string>(argv[3]);

	if (type == "int") {
		int	a = std::stoi(value1);
		int	b = std::stoi(value2);
		executeTest(a, b);
	}
	else if (type == "float") {
		float	a = std::stof(value1);
		float	b = std::stof(value2);
		executeTest(a, b);
	}
	else if (type == "double") {
		double	a = std::stod(value1);
		double	b = std::stod(value2);
		executeTest(a, b);
	}
}

#endif
