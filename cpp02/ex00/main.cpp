/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:56:07 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/17 10:44:54 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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
		<< YELLOW << "====== CONSTRUCT =====" << END
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

#ifdef LEAKS
	system("leaks -q ex00");
#endif
	return (0);
}
