/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:31:58 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/31 17:17:44 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include "color.hpp"

#ifdef TEST

static void	printDataValue(const Span& sp)
{
	std::size_t	cap = sp.getCapacity();

	if (cap != 0) {
		std::vector<int>::const_iterator itr = sp.getBegin();
		for (std::size_t i = 0; i < cap; i++) {
			if (itr != sp.getEnd()) {
				std::cout << "[" << *itr << "]" << std::flush;
				itr += 1;
			}
			else {
				std::cout << CYAN << "[EMPTY]" << END << std::flush;
			}
			if ((i + 1) != cap) {
				std::cout << " -> " << std::flush;
			}
		}
	}
	else {
		std::cout << RED << "Not capacity." << END << std::flush;
	}
	std::cout << std::endl;
}

static void	printData(const std::string& sub, const Span& sp)
{
	std::cout << YELLOW << "[" << sub << "]" << END << std::endl;
	std::cout << "cap(Vector)   :[" << sp.getCapacity() << "]" << std::endl;
	std::cout << "size          :[" << sp.getSize() << "]" << std::endl;
	std::cout << "shortestSpan();[" << std::flush;
	try {
		std::cout << sp.shortestSpan() << "]" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << END << "]" << std::endl;
	}
	std::cout << "longestSpan(); [" << std::flush;
	try {
		std::cout << sp.longestSpan() << "]" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << END << "]" << std::endl;
	}
	printDataValue(sp);
	std::cout << std::endl;
}

#ifdef CONSTRUCT

int	main()
{
	std::cout << GREEN << "========== CONSTRUCTOR TEST ==========" << END << std::endl;
	Span	sp1 = Span();
	printData("sp1", sp1);

	Span	sp2 = Span(0);
	printData("sp2", sp2);

	Span	sp3 = Span(5);
	printData("sp3", sp3);

	Span	sp4 = Span(100000000);
	// printData("sp4", sp4);

	Span	sp5 = Span(sp3);
	printData("sp5", sp5);

#ifdef LEAKS
	system("leaks -q ex01");
#endif // LEAKS
	return (0);
}

#endif // CONSTRUCT

#ifdef COPY_ASSIGNMENT

int	main()
{
	std::cout << GREEN << "========== COPY_ASSIGNMENT TEST ==========" << END << std::endl;
	Span	sp0 = Span();

	Span	sp1 = Span(5);
	try {
		sp1.addNumber(0); sp1.addNumber(1); sp1.addNumber(2); sp1.addNumber(3); sp1.addNumber(4);
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
	}

	Span	sp2 = Span(10);
	try {
		sp2.addNumber(0); sp2.addNumber(1); sp2.addNumber(2); sp2.addNumber(3); sp2.addNumber(4);
		sp2.addNumber(5); sp2.addNumber(6); sp2.addNumber(7); sp2.addNumber(8); sp2.addNumber(9);
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
	}

	Span	sp3 = Span(1000000);
	// printData("sp3", sp3);

	std::cout << MAGENTA << "[CASE] sp0 = sp1 --------------------" << END << std::endl;
	printData("sp0", sp0); printData("sp1", sp1);
	sp0 = sp1; std::cout << std::endl;
	printData("sp0", sp0); printData("sp1", sp1);

	std::cout << MAGENTA << "[CASE] sp3 = sp1 --------------------" << END << std::endl;
	// printData("sp3", sp3);
	printData("sp1", sp1);
	sp3 = sp1; std::cout << std::endl;
	printData("sp3", sp3); printData("sp1", sp1);

	std::cout << MAGENTA << "[CASE] sp0 = sp2 --------------------" << END << std::endl;
	printData("sp0", sp0); printData("sp2", sp2);
	sp0 = sp2; std::cout << std::endl;
	printData("sp0", sp0); printData("sp2", sp2);

	std::cout << MAGENTA << "[CASE] sp3 = sp2 --------------------" << END << std::endl;
	printData("sp3", sp3); printData("sp2", sp2);
	sp3 = sp2; std::cout << std::endl;
	printData("sp3", sp3); printData("sp2", sp2);

#ifdef LEAKS
	system("leaks -q ex01");
#endif
	return (0);
}

#endif // COPY_ASSIGNMENT

#ifdef SUB_FUNC

int	main()
{
	std::cout << GREEN << "========== addNumber(); TEST ==========" << END << std::endl;
	Span	sp0 = Span();
	printData("sp0", sp0);

	try {
		sp0.addNumber(1);
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	printData("sp0", sp0);

	Span	sp1 = Span(5);
	printData("sp1", sp1);
	try {
		sp1.addNumber(INT_MIN);
		sp1.addNumber(INT_MAX);
		sp1.addNumber(INT_MIN);
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	printData("sp1", sp1);
	try {
		sp1.addNumber(0);
		sp1.addNumber(4);
		sp1.addNumber(5);
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	printData("sp1", sp1);

	// Span	sp2 = Span(10000);
	// printData("sp2", sp2);
	// try {
	// 	for (std::size_t i = 0; i < sp2.getCapacity(); i++) {
	// 		sp2.addNumber(i);
	// 	}
	// }
	// catch (const std::exception& e) {
	// 	std::cerr << RED << e.what() << END << std::endl;
	// }
	// printData("sp2", sp2);

	try {
		sp1.fillRandomNumber();
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	printData("sp1", sp1);

	Span	sp3 = Span(10);
	try {
		sp3.fillRandomNumber();
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	printData("sp3", sp3);

	Span	sp4 = Span(10);
	try {
		sp4.addNumber(0);
		sp4.addNumber(1);
		sp4.addNumber(2);
		sp4.fillRandomNumber();
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	printData("sp4", sp4);

#ifdef LEAKS
	system("leaks -q ex01");
#endif
	return (0);
}

#endif // SUB_FUNC

#else // TEST

int	main()
{
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

#ifdef LEAKS
	system("leaks -q ex01");
#endif
	return (0);
}

#endif // TEST
