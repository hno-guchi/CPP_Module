/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:48:41 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/16 11:07:23 by hnoguchi         ###   ########.fr       */
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
	try { btc.parseLine("2011-01-01,-999999999999999999999999999999999999999999999999999999999999999");
	} catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }

	std::cout << " [validationDate(); TEST]" << std::endl;
	std::cout << "---------- [" << GREEN "OK" << END << "] ----------" << std::endl;
	try { btc.validationDate("2011-01-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2012-2-29"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }

	try { btc.validationDate("2020-04-30"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-06-30"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-09-30"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-11-30"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }

	try { btc.validationDate("2020-01-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-03-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-05-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-07-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-08-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-10-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-12-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }

	try { btc.validationDate("2011-2-28"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2012-2-29"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2015-2-28"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2016-2-29"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2019-2-28"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-2-29"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }

	std::cout << "\n---------- [" << RED "NG" << END << "] ----------" << std::endl;
	try { btc.validationDate("a-01-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2011-a-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2011-01-a"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2011*01-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2011-01*01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2011-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("-2011-01-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2011--01-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2011-01--01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("-2147483648-12-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2012--2147483648-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2012-12--2147483648"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("-2147483649-12-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2012--2147483649-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2012-12--2147483649"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2147483647-12-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2012-2147483647-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2012-12-2147483647"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2147483648-12-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2012-2147483648-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2012-12-2147483648"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }

	try { btc.validationDate("2008-01-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2009-00-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2009-0-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2009-01-00"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }

	try { btc.validationDate("2009-13-01"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }

	try { btc.validationDate("2024-11-15"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2023-12-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2023-11-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }

	try { btc.validationDate("2020-04-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-06-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-09-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-11-31"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }

	try { btc.validationDate("2020-01-32"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-03-32"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-05-32"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-07-32"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-08-32"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-10-32"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-12-32"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }

	try { btc.validationDate("2009-2-29"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2010-2-29"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2011-2-29"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2012-2-30"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2013-2-29"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2014-2-29"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2015-2-29"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2016-2-30"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2017-2-29"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2018-2-29"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2019-2-29"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
	try { btc.validationDate("2020-2-30"); } catch (const std::exception& e) { std::cout << "Error: " << RED << e.what() << END << std::endl; }
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
