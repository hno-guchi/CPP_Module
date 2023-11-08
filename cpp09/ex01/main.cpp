/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:12:46 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/08 10:19:12 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "color.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << RED << "Please give a single argument." << END << std::endl;
		return (1);
	}
	try {
		const RPN	rpn(static_cast<std::string>(argv[1]));
		// rpn.excetuce();
	} catch (std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	return (0);
}
