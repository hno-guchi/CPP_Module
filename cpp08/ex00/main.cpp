/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:49:09 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/25 17:38:22 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int	main()
{
	// COMPILE ERROR
	// std::vector<int>	vec = {8, 4, 5, 9};
	std::vector<int>	vec;
	// std::vector<float>		vecF;

	vec.push_back(8); vec.push_back(4); vec.push_back(5); vec.push_back(9);
	// vecF.push_back(8.4); vecF.push_back(4.3); vecF.push_back(5.2); vecF.push_back(9.0);
	for (int i = 0; i < 5; i++) {
		std::cout << "val is [" << i << "] | " << std::flush;
		if (easyfind(vec, i) == vec.end()) {
			std::cout << RED << "Not value." << END << std::endl;
		}
		else {
			std::cout << "Exist value." << std::endl;
		}
	}
	// for (int i = 0; i < 5; i++) {
	// 	std::cout << "val is [" << i << "] | " << std::flush;
	// 	if (easyfind(vecF, i) == vecF.end()) {
	// 		std::cout << RED << "Not value." << END << std::endl;
	// 	}
	// 	else {
	// 		std::cout << "Exist value." << std::endl;
	// 	}
	// }
}
