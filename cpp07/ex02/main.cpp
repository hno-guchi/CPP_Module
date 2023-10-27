/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:49:32 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/27 10:53:56 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include "color.hpp"

#ifndef TEST
int	main()
{
	std::cout << GREEN << "========== CONSTRUCT TEST ==========" << END << std::endl;
	Array<int>	i;
	// try {
		Array<int>	ary(100);
	// }
	// catch (const std::exception& e) {
	// 	std::cerr << RED << e.what() << END << std::endl;
	// }
	Array<int>	ary2(ary);

	std::cout << "   i: ptr[" << &(i[0]) << "] | size[" << i.size() << "]   |    i[0] : [" << i[0] << "]" << std::endl;
	std::cout << " ary: ptr[" << &(ary[0]) << "] | size[" << ary.size() << "] |  ary[0] : [" << ary[0] << "]" << std::endl;
	std::cout << "ary2: ptr[" << &(ary2[0]) << "] | size[" << ary2.size() << "] | ary2[0] : [" << ary2[0] << "]" << std::endl;
	i = ary;
	std::cout << "   i: ptr[" << &(i[0]) << "] | size[" << i.size() << "] |    i[0] : [" << i[0] << "]" << std::endl;

	std::cout << GREEN << "========== OPEARATOR TEST ==========" << END << std::endl;
	try {
		int num = i[-1];
		std::cout << num << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	try {
		int num = i[100];
		std::cout << num << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	try {
		i[0] = 100;
		std::cout << i[0] << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	// COMPILE ERROR
	// Array<float>	f1;
	// Array<float>	f2(i);
	// Array<float>	f3 = i;
	// f1 = i;
#ifdef LEAKS
	system("leaks -q ex02");
#endif
	return (0);
}

#else // TEST

#ifdef SUB

#define MAX_VAL 750
int main()
{
	Array<int>	numbers(MAX_VAL);
	int*		mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int	value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int>	tmp = numbers;
		Array<int>	test(tmp);
	}
	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << RED << "didn't save the same value!!" << END << std::endl;
			return (1);
		}
	}
	try {
		numbers[-2] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	try {
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}
	delete [] mirror;
#ifdef LEAKS
	system("leaks -q ex02");
#endif // LEAKS
	return (0);
}
#endif // SUB

#ifdef WHILE_LEAKS
int	main()
{
	Array<int>	i;
	Array<int>	ary(100);

	// while (1) {
	for (int cnt = 0; cnt < 10; cnt++) {
		i = ary;
	}
	system("leaks -q ex02");
}
#endif // WHILE_LEAKS

#endif // TEST
