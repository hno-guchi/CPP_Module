/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:29:55 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/18 16:46:46 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "color.hpp"
#include <iostream>

int	main()
{
	int	a = 0;
	int	b = 100;

	std::cout << GREEN << "++++++++++++++++++++" << END << std::endl;
	std::cout << "Befor : a = [" << a << "] | " << "b = [" << b << "]" << std::endl;
	swap(a, b);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
}
