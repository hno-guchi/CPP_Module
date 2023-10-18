/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:17:15 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/18 15:56:00 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main()
{
	std::cout << GREEN << "++++++++++ class A ++++++++++" << END << std::endl;
	A	a;
	Base *ptr = a.generate();

	a.identify(ptr);
	a.identify(*ptr);
	delete ptr;
	std::cout << std::endl;

	std::cout << GREEN << "++++++++++ class B ++++++++++" << END << std::endl;
	B	b;
	ptr = b.generate();

	b.identify(ptr);
	b.identify(*ptr);
	delete ptr;
	std::cout << std::endl;

	std::cout << GREEN << "++++++++++ class C ++++++++++" << END << std::endl;
	C	c;
	ptr = c.generate();

	c.identify(ptr);
	c.identify(*ptr);
	delete ptr;
	std::cout << std::endl;
#ifdef LEAKS
	system("leaks -q identify");
#endif
}
