/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:38:49 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/19 16:04:40 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

static void	func(int* ptr)
{
	*ptr += 1;
}

int	main()
{
	int	ary[10] = {0};

	iter(ary, 10, &func);
	std::cout << "index : " << std::flush;
	for (std::size_t i = 0; i < 10; i++) {
		std::cout << " ["<< i << "] " << std::flush;
	}
	std::cout << std::endl;

	std::cout << "value : " << std::flush;
	for (std::size_t i = 0; i < 10; i++) {
		std::cout << " ["<< ary[i] << "] " << std::flush;
	}
	std::cout << std::endl;

	return (0);
}
