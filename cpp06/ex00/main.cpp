/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:46:07 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/05 13:52:42 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1) {
		std::cerr << RED << "Please pass the arguments." << END << std::endl;
		return (1);
	}
	std::string	str = argv[1];
	// ScalarConverter::convert(static_cast<std::string&>(argv[1]));
	ScalarConverter::convert(str);
}
