/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:56:07 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/19 15:01:05 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static void	colorMessage(eColor color, std::string message)
{
	switch(color) {
		case green:
			std::cout << GREEN << message << END << std::endl;
			break ;
		case yellow:
			std::cout << YELLOW << message << END << std::endl;
			break ;
		case red:
			std::cout << RED << message << END << std::endl;
			break ;
		default:
			std::cout << message << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& lhs, const Fixed& rhs)
{
	lhs << rhs.toFloat();
	return (lhs);
}

#ifndef TEST

int	main(void) {
	colorMessage(green,  "===== CONSTRUCT =======");
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	colorMessage(green,  "=======================");

	colorMessage(yellow, "===== DO FUNCTION =====");
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;
	colorMessage(yellow, "=======================");

	colorMessage(red,    "===== DESTRUCTOR ======");
}

#else //ifdef TEST

#include <cfloat>

int	main()
{
	const Fixed	small(12.33f);
	const Fixed	large(12.34f);
	const Fixed	zero(0.0f);
	const Fixed	divNum(2.3f);
	Fixed		dicZero(0.0f);
	Fixed		resultAdd(small + large);
	Fixed		resultSub(small - large);
	Fixed		resultMlt(small * large);
	Fixed		resultMlt1(zero * zero);
	Fixed		resultMlt2(zero * small);
	Fixed		resultMlt3(small * zero);
	Fixed		resultDiv1(large / divNum);
	Fixed		resultDiv2(large / large);


	colorMessage(yellow, "===== OPERATOR [==], [!=] ==");
	if ((small == small) == true) {
		colorMessage(green, "[true]");
	}
	else {
		colorMessage(red, "[false]");
	}
	if ((small == large) == true) {
		colorMessage(green, "[true]");
	}
	else {
		colorMessage(red, "[false]");
	}

	colorMessage(yellow, "\n===== OPERATOR [<], [>=] ===");
	if (small < large) {
		colorMessage(green, "[true]");
	}
	else {
		colorMessage(red, "[false]");
	}
	if ((small < small) == true) {
		colorMessage(green, "[true]");
	}
	else {
		colorMessage(red, "[false]");
	}

	colorMessage(yellow, "\n===== OPERATOR [>], [<=] ===");
	if (large > small) {
		colorMessage(green, "[true]");
	}
	else {
		colorMessage(red, "[false]");
	}
	if ((small > small) == true) {
		colorMessage(green, "[true]");
	}
	else {
		colorMessage(red, "[false]");
	}

	std::cout << std::endl;

	colorMessage(yellow, "\n===== OPERATOR [+] ========");
	std::cout << small << " + " << large <<  " = " << resultAdd << std::endl;
	colorMessage(yellow, "\n===== OPERATOR [-] ========");
	std::cout << small << " - " << large <<  " = " << resultSub << std::endl;
	colorMessage(yellow, "\n===== OPERATOR [*] ========");
	std::cout << small << " * " << large <<  " = " << resultMlt << std::endl;
	std::cout << zero << " * " << zero <<  " = " << resultMlt1 << std::endl;
	std::cout << zero << " * " << small <<  " = " << resultMlt2 << std::endl;
	std::cout << small << " * " << zero <<  " = " << resultMlt3 << std::endl;
	colorMessage(yellow, "\n===== OPERATOR [/] ========");
	std::cout << large << " / " << divNum <<  " = " << resultDiv1 << std::endl;
	std::cout << large << " / " << large <<  " = " << resultDiv2 << std::endl;
	colorMessage(yellow, "\n===== OPERATOR [--] ========");
	std::cout << --dicZero << std::endl;
	std::cout << dicZero-- << std::endl;
	std::cout << dicZero << std::endl;

	colorMessage(red,    "\n===== DESTRUCTOR ==========");
}

#endif // TEST
