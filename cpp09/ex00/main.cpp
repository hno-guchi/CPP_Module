/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:48:41 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/14 16:39:26 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "color.hpp"

int	main()
{
	std::string					line("aaaaa,bbbbbb,cccccc,dddddd,eeeeeee,");
	std::vector<std::string>	header;

	size_t	pos(0);
	size_t	found(0);

	while ((found = line.find(',', pos)) != std::string::npos) {
		header.push_back(line.substr(pos, found - pos));
		pos = found + 1;
	}
	for (std::vector<std::string>::iterator itr = header.begin(); itr != header.end(); itr++) {
		std::cout << *itr << " | " << std::flush;
	}
	std::cout << std::endl;
	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	if (argc != 2) {
// 		std::cerr << RED << "Error: could not open file." << END << std::endl;
// 	}
// 	// BitcoinExchange Class
// 	std::ifstream	fd(argv[1]);
// 	if (!fd.is_open()) {
// 		std::cerr << RED << "Error: could not open file." << END << std::endl;
// 	}
// 	// check extend.(.csv or .txt)
// 	std::string	line;
// 	std::getline(fd, line, '\n')
// 	std::map<std::string, std::string>	header;
// 
// 
// 
// 	while (std::getline(fd, line, '\n')) {
// 		if (fd.fail()) {
// 			std::cerr << RED << "Error: Failed getline." << END << std::endl;
// 			return (1);
// 			// throw std::runtime_error("Error: Failed getline.");
// 		}
// 		std::map<std::string, std::string>	data;
// 		data["date"] = line.substr(0, line.find(','));
// 		data["sep"] = line.substr(line.find(','), 1);
// 		data["value"] = line.substr(line.find(',') + 1, line.back() - line.find(',') + 1);
// 
// 		std::cout << data["date"] << " | " << data["sep"] << " | " << data["value"] << std::endl;
// 		// std::cout << line << std::endl;
// 	}
// 	return (0);
// }
