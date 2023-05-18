/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:56:07 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/18 19:07:44 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE

#include "Fixed.hpp"

std::ostream&	operator<<(std::ostream& lhs, const Fixed& rhs)
{
	lhs << rhs.toFloat();
	return (lhs);
}

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

	std::cout << std::endl;

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
}

#endif

#ifdef SAMPLE

#include <cfloat>
#include "Fixed.hpp"

# define FRACTIONAL_BITS 8

void	converter(float fromNum)
{
	std::cout << GREEN << "========== " << fromNum << " ==========" << END << std::endl;
	// int		fixed = static_cast<int>(roundf(fromNum * (1 << FRACTIONAL_BITS)));
	int		fixed = static_cast<int>(roundf(fromNum * (1 << 8)));

	float	fromFixed = static_cast<float>(fixed);
	fromFixed /= (1 << FRACTIONAL_BITS);

	std::cout << "Floating point number     : [" << fromNum << "]" << std::endl;
	std::cout << "Fixed point number        : [" << fixed << "]" << std::endl;
	std::cout << "Floating point from fixed : [" << fromFixed << "]" << std::endl;

	std::cout << std::endl;
}

int	main()
{
	converter(FLT_MAX); // 3.40282e+38
	converter(1234.4312f);
	converter(42.42f);
	converter(0.42f);

	converter(0);

	converter(-0.42f);
	converter(-42.42f);
	converter(-1234.4312f);
	converter(FLT_MIN); // 1.17549e-38

	converter(42);
	converter(-42);

}

#endif
