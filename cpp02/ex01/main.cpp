/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:56:07 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/18 11:52:13 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE

#include "Fixed.hpp"

int	main(void) {
	std::cout
		<< GREEN << "====== CONSTRUCT =====" << END
		<< std::endl;
	Fixed		a;
	Fixed const	b(10);
	Fixed const	c(42.42f);
	Fixed const	d(b);

	a = Fixed(1234.4321f);
	std::cout
		<< GREEN << "======================" << END
		<< "\n"
		<< std::endl;

	std::cout
		<< YELLOW << "====== DO FUNCTION =====" << END
		<< std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "\n" << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout
		<< YELLOW << "======================" << END
		<< "\n"
		<< std::endl;

	std::cout
		<< RED << "====== DESTRUCTOR =====" << END
		<< std::endl;

#ifdef LEAKS
	system("leaks -q ex00");
#endif
	return (0);
}

#endif

#ifdef SAMPLE

#include <iostream>
#include <cmath>

int	main()
{
	float	fp_num = 42.42f;
	int		fixed = static_cast<int>(roundf(fp_num * (1 << 8)));

	std::cout << "Floating point number    : [" << fp_num << "]" << std::endl;
	std::cout << "fp_num * (1 << 8)        : [" << fp_num * (1 << 8) << "]" << std::endl;
	std::cout << "Fixed point number       : [" << fixed << "]" << std::endl;

	// float	fp_num = 42.42f;
	// int		intger_part = static_cast<int>(roundf(fp_num));
	// float	fractional_part = fp_num - intger_part;
	// int		fractional_part_intger = static_cast<int>(fractional_part);
	// if (errno != 0) {
	// 	std::cout << "error: roundf(); [" << errno << "]" << std::endl;
	// 	return (1);
	// }

	// std::cout << "Floating point number    : [" << fp_num << "]" << std::endl;
	// std::cout << "Intger part number       : [" << intger_part << "]" << std::endl;
	// std::cout << "Fractional part number   : [" << fractional_part << "]" << std::endl;
	// std::cout << "Fractional part (intger) : [" << fractional_part_intger << "]" << std::endl;
#ifdef LEAKS
	system("leaks -q ex01");
#endif
}

#endif
