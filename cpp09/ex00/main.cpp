/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:48:41 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/15 15:45:03 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "color.hpp"

# ifdef TEST

int	main()
{
	BitcoinExchange	btc;

	std::cout << " [parseLine(); TEST]" << std::endl;
	std::cout << "---------- [" << GREEN "OK" << END << "] ----------" << std::endl;
	try { btc.parseLine("2011-01-01,0"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseLine("2011-01-01,0.5"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseLine("2011-01-01 ,0.5"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseLine("2011-01-01, 0.5"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseLine("2011-01-01 , 0.5"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }

	try { btc.parseLine("2011-01-01,0.000000000000000000000000000000000000005");
	} catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }

	try { btc.parseLine("2011-01-01,999999999999999999999990.000000000000000000000000000000000000005");
	} catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }

	try { btc.parseLine("2011-01-01,999999999999999999999999999999999999999999999999999999999999999");
	} catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }

	std::cout << "\n---------- [" << RED "NG" << END << "] ----------" << std::endl;
	try { btc.parseLine("2011-01-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseLine("2011-01-01,"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseLine("2011-01-01 ,"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseLine("2011-01-01, "); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseLine("2011-01-01 , "); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseLine("2011-01-01,a"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseLine("2011-01-01, 0a"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseLine("2011-01-01,0.5 2011-01-01,0.5"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }

	std::cout << " [parseDate(); TEST]" << std::endl;
	std::cout << "---------- [" << GREEN "OK" << END << "] ----------" << std::endl;
	try { btc.parseDate("2011-01-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	
	std::cout << "\n---------- [" << RED "NG" << END << "] ----------" << std::endl;
	try { btc.parseDate("a-01-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseDate("2011-a-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseDate("2011-01-a"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseDate("2011*01-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseDate("2011-01*01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseDate("2011-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseDate("-2011-01-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseDate("2011--01-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseDate("2011-01--01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseDate("2008-01-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.parseDate("2023-12-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
}

# else // TEST

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "Error: " << RED << "could not open file." << END << std::endl;
		return (1);
	}
	// BitcoinExchange Class
	// Read csv file.
	std::ifstream	fd(argv[1]);
	if (!fd.is_open()) {
		std::cout << "Error: " << RED << "could not open file." << END << std::endl;
		return (1);
	}
	// check extend.(.txt)
	std::string	line;
	while (std::getline(fd, line, '\n')) {
		if (fd.fail()) {
			std::cout << "Error: " << RED << "Failed getline." << END << std::endl;
			return (1);
		}
		std::cout << line << std::endl;
	}
	return (0);
}

# endif // TEST
