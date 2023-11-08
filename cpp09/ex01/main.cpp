/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:12:46 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/08 16:21:23 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "color.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << RED << "Please give a single argument." << END << std::endl;
		return (1);
	}
	try {
		const RPN	rpn;
		rpn.execute(static_cast<std::string>(argv[1]));
	} catch (std::exception& e) {
		std::cout << RED << e.what() << END << std::endl;
	}
#ifdef LEAKS
	system("leaks -q RPN");
#endif
	return (0);
}
