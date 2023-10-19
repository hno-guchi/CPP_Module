/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:38:49 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/19 18:02:04 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

static void	func(int* ptr)
{
	*ptr += 1;
}

static void	func1(int const* ptr)
{
	std::cout << " ["<< *ptr << "] " << std::flush;
}

static void	printIndex(std::size_t size)
{
	std::cout << "index : " << std::flush;
	for (std::size_t i = 0; i < size; i++) {
		std::cout << " ["<< i << "] " << std::flush;
	}
	std::cout << std::endl;
}

int	main()
{
	int	ary1[10] = {0};

	iter(ary1, (sizeof(ary1) / sizeof(int)), &func);
	printIndex(sizeof(ary1) / sizeof(int));
	PrintAryData(ary1, sizeof(ary1) / sizeof(int));

	int const	ary2[10] = {0};
	printIndex(sizeof(ary2) / sizeof(int));
	std::cout << "value : " << std::flush;
	iter(ary2, (sizeof(ary2) / sizeof(int)), &func1);
	std::cout << std::endl;
	// PrintAryData(ary2, sizeof(ary2) / sizeof(int));

#ifdef LEAKS
	system("leaks -q ex01");
#endif
	return (0);
}
