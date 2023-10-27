/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:31:58 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/27 17:21:39 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include "color.hpp"

static void	printData(const std::string& sub, const Span& sp)
{
	std::cout << YELLOW << "[" << sub << "]" << END << std::endl;
	std::cout << "capacity:[" << sp.getCapacity() << "]" << std::endl;
	std::cout << "    size:[" << sp.getSize() << "]" << std::endl;
	for (std::size_t i = 0; i < sp.getSize(); i++) {
		std::cout << "[" << sp.getData()[i] << "]" << std::flush;
		if (i != (sp.getSize() - 1)) {
			std::cout << " -> " << std::flush;
		}
	}
	std::cout << std::endl;
}

int	main()
{
	std::cout << GREEN << "========== CONSTRUCTOR TEST ==========" << END << std::endl;
	Span	sp1 = Span();
	printData("sp1", sp1);

	Span	sp2 = Span(0);
	printData("sp2", sp2);

	Span	sp3 = Span(5);
	try {
		sp3.addNumber(0); sp3.addNumber(1); sp3.addNumber(2); sp3.addNumber(3); sp3.addNumber(4);
		sp3.addNumber(0); sp3.addNumber(1); sp3.addNumber(2); sp3.addNumber(3); sp3.addNumber(4);
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	printData("sp3", sp3);

	Span	sp4 = Span(1000000);
	printData("sp4", sp4);

	std::cout << GREEN << "========== OPERATOR TEST ==========" << END << std::endl;
	sp1 = sp4;
	printData("sp1", sp1);
	printData("sp4", sp4);

	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);

	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
#ifdef LEAKS
	system("leaks -q ex01");
#endif
	return (0);
}
