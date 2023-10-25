/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:49:09 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/25 18:26:51 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "color.hpp"
#include "easyfind.hpp"

int	main()
{
	// COMPILE ERROR
	// std::vector<int>	vec = {8, 4, 5, 9};
	std::cout << GREEN << "========== std::vector<int> ==========" << END << std::endl;
	std::vector<int>			vecI;
	vecI.push_back(8); vecI.push_back(4); vecI.push_back(5); vecI.push_back(9);
	for (int i = 0; i < 5; i++) {
		std::cout << "val is [" << i << "] | " << std::flush;
		if (easyfind(vecI, i) == vecI.end()) {
			std::cout << RED << "Not value." << END << std::endl;
		}
		else {
			std::cout << "Exist value." << std::endl;
		}
	}

	std::cout << GREEN << "========== std::vector<float> ==========" << END << std::endl;
	std::vector<float>			vecF;
	vecF.push_back(8.4); vecF.push_back(4.3); vecF.push_back(5.2); vecF.push_back(9.0);
	for (int i = 0; i < 5; i++) {
		std::cout << "val is [" << i << "] | " << std::flush;
		if (easyfind(vecF, i) == vecF.end()) {
			std::cout << RED << "Not value." << END << std::endl;
		}
		else {
			std::cout << "Exist value." << std::endl;
		}
	}

	// std::cout << GREEN << "========== std::vector<std::string> ==========" << END << std::endl;
	// std::vector<std::string>	vecS;
	// vecS.push_back("Hello"); vecS.push_back("World"); vecS.push_back("I am"); vecS.push_back("hungry.");
	// for (int i = 0; i < 5; i++) {
	// 	std::cout << "val is [" << i << "] | " << std::flush;
	// 	if (easyfind(vecS, i) == vecS.end()) {
	// 		std::cout << RED << "Not value." << END << std::endl;
	// 	}
	// 	else {
	// 		std::cout << "Exist value." << std::endl;
	// 	}
	// }
#ifdef LEAKS
	system("leaks -q ex00");
#endif
}
