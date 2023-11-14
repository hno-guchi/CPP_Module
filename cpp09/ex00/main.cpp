/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:48:41 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/14 19:35:06 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "color.hpp"

# ifdef TEST

static void	parseLine(const std::string& line)
{
	std::istringstream				ss(line);
	std::string						date;

	if (!std::getline(ss, date, ',')) {
		std::cout << RED << "Error: Bad format. (Not [date,value])" << END << std::endl;
		return ;
	}

	double	value;

	if (!(ss >> value)) {
		std::cout << RED << "Error: Bad value." << END << std::endl;
		return ;
	}
	if (!ss.eof()) {
		std::cout << RED << "Error: Bad line. (Only [date,value])" << END << std::endl;
		return ;
	}
	std::map<std::string, double>	map;
	// if (!validationDate(date)) {
	// 	std::cout << RED << "Error: Bad date." << END << std::endl;
	// 	return ;
	// }
	map[date] = value;
	std::cout << date << ": [" << GREEN << map[date] << END << "]" << std::endl;
}

int	main()
{
	std::cout << "---------- [" << GREEN "OK" << END << "] ----------" << std::endl;
	parseLine("2011-01-01,0");
	parseLine("2011-01-01,0.5");
	parseLine("2011-01-01 ,0.5");
	parseLine("2011-01-01, 0.5");
	parseLine("2011-01-01 , 0.5");
	parseLine("2011-01-01,0.000000000000000000000000000000000000005");
	parseLine("2011-01-01,999999999999999999999990.000000000000000000000000000000000000005");
	parseLine("2011-01-01,999999999999999999999999999999999999999999999999999999999999999");

	std::cout << "\n---------- [" << RED "NG" << END << "] ----------" << std::endl;
	parseLine("2011-01-01");
	parseLine("2011-01-01,");
	parseLine("2011-01-01 ,");
	parseLine("2011-01-01, ");
	parseLine("2011-01-01 , ");
	parseLine("2011-01-01,a");
	parseLine("2011-01-01, 0a");
	parseLine("2011-01-01,0.5 2011-01-01,0.5");
}

# else // TEST

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << RED << "Error: could not open file." << END << std::endl;
		return (1);
	}
	// BitcoinExchange Class
	std::ifstream	fd(argv[1]);
	if (!fd.is_open()) {
		std::cerr << RED << "Error: could not open file." << END << std::endl;
		return (1);
	}
	// check extend.(.csv or .txt)
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

# endif // TEST
