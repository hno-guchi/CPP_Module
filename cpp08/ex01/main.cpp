/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:31:58 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/27 15:34:15 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include "color.hpp"

int	main()
{
	std::cout << GREEN << "========== CONSTRUCTOR TEST ==========" << END << std::endl;
	Span	sp1 = Span();
	std::cout << "capacity:[" << sp1.getCapacity() << "]" << std::endl;
	std::cout << "    size:[" << sp1.getSize() << "]" << std::endl;
	std::cout << std::endl;

	Span	sp2 = Span(0);
	std::cout << "capacity:[" << sp2.getCapacity() << "]" << std::endl;
	std::cout << "    size:[" << sp2.getSize() << "]" << std::endl;
	std::cout << std::endl;

	Span	sp3 = Span(5);
	std::cout << "capacity:[" << sp3.getCapacity() << "]" << std::endl;
	std::cout << "    size:[" << sp3.getSize() << "]" << std::endl;
	std::cout << std::endl;

	Span	sp4 = Span(1000000);
	std::cout << "capacity:[" << sp4.getCapacity() << "]" << std::endl;
	std::cout << "    size:[" << sp4.getSize() << "]" << std::endl;
	std::cout << std::endl;

	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);

	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;

	return (0);
}
