/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:56:07 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/18 18:18:11 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#ifndef TEST

int	main(void) {
	std::cout
		<< GREEN << "====== CONSTRUCT =====" << END
		<< std::endl;
	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	c = b;
	std::cout
		<< GREEN << "======================" << END
		<< "\n"
		<< std::endl;

	std::cout
		<< YELLOW << "====== DO FUNCTION =====" << END
		<< std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout
		<< YELLOW << "======================" << END
		<< "\n"
		<< std::endl;

	std::cout
		<< RED << "====== DESTRUCTOR =====" << END
		<< std::endl;
}

#else

int	main(void) {
	std::cout
		<< GREEN << "====== CONST TEST =====" << END
		<< std::endl;
	const Fixed	a;
	const Fixed	b(a);
	const Fixed	c;
	Fixed		d;

	// c = b; // Compile Error; [Object c is const]
	std::cout
		<< GREEN << "======================" << END
		<< "\n"
		<< std::endl;

	std::cout
		<< YELLOW << "====== DO FUNCTION =====" << END
		<< std::endl;
	std::cout << a.getRawBits() << std::endl;
	// a.setRawBits(200); // Compile Error [Not const member func. setRawBits()]
	// std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << std::endl;
	std::cout << d.getRawBits() << std::endl;
	d.setRawBits(200);
	std::cout << d.getRawBits() << std::endl;
	std::cout
		<< YELLOW << "======================" << END
		<< "\n"
		<< std::endl;

	std::cout
		<< RED << "====== DESTRUCTOR =====" << END
		<< std::endl;
}

#endif // TEST
