/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:29:55 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/18 17:02:19 by hnoguchi         ###   ########.fr       */
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
	std::cout << "Before : a = [" << a << "] " << "b = [" << b << "]" << std::endl;
	swap(a, b);
	std::cout << "After  : a = [" << a << "] " << "b = [" << b << "]" << std::endl;
	std::cout << std::endl;

	std::string aStr = "hello";
	std::string bStr = "World";
	std::cout << GREEN << "++++++++++++++++++++" << END << std::endl;
	std::cout << "Before : a = [" << aStr << "] " << "b = [" << bStr << "]" << std::endl;
	swap(aStr, bStr);
	std::cout << "After  : a = [" << aStr << "] " << "b = [" << bStr << "]" << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "++++++++++++++++++++" << END << std::endl;
	std::cout << "Before : a = [" << a << "] " << "b = [" << a << "]" << std::endl;
	swap(a, a);
	std::cout << "After  : a = [" << a << "] " << "b = [" << a << "]" << std::endl;
	std::cout << std::endl;
}
