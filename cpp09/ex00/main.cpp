/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:48:41 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/02 15:08:02 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "color.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << RED << "Error: could not open file." << END << std::endl;
	}
	std::ifstream	fd(argv[1]);
	if (!fd.is_open()) {
		std::cerr << RED << "Error: could not open file." << END << std::endl;
	}
	std::string	line;
	while (std::getline(fd, line, '\n')) {
		if (fd.fail()) {
			std::cerr << RED << "Error: Failed getline." << END << std::endl;
			return (1);
			// throw std::runtime_error("Error: Failed getline.");
		}
		std::cout << line << std::endl;
	}
	return (0);
}
