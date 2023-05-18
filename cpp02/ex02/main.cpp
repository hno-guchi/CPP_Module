/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:56:07 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/18 19:46:57 by hnoguchi         ###   ########.fr       */
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

#ifndef SAMPLE

std::ostream&	operator<<(std::ostream& lhs, const Fixed& rhs)
{
	lhs << rhs.toFloat();
	return (lhs);
}


int	main(void) {
	colorMessage(green,  "===== CONSTRUCT =======");
	Fixed		a;
	// Fixed const	b(Fixed(5.05f) * Fixed(2));
	colorMessage(green,  "=======================");

	colorMessage(yellow, "===== DO FUNCTION =====");
	std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;
	colorMessage(yellow, "=======================");

	colorMessage(red,    "===== DESTRUCTOR ======");
}

#endif

#ifdef SAMPLE

#include "Fixed.hpp"

int	main()
{
}

#endif
