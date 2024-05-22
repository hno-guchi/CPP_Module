#include "./BitcoinExchange.hpp"
#include "./Csv.hpp"
#include "./color.hpp"

# ifdef TEST

#ifdef CSV

#include "./Csv.hpp"

int	main()
{
	Csv	csv("data.csv", true);

	csv.debugPrint();
#ifdef LEAKS
	system("leaks -q btc");
#endif // LEAKS
}

#else // CSV


static void	printHeader(const std::map<size_t, std::string>& header)
{
	for (std::map<size_t, std::string>::const_iterator itr = header.begin(); itr != header.end(); itr++) {
		std::cout << itr->first << "[" << GREEN << itr->second << END << "]" << std::flush;
		if (itr != --header.end()) {
			std::cout << "  " << std::flush;
		}
		else {
			std::cout << std::endl;
		}
	}
}

static void	setHeaderTest(std::string line, const std::string& delimiter)
{
	BitcoinExchange	btc;
	// std::cout << "line: " << line << std::endl;
	// std::cout << "delimiter: " << delimiter << std::endl;
	try {
		btc.setHeader(line, delimiter);
		printHeader(btc.getCsvHeader());
	} catch (const std::exception& e) {
		std::cout << "Error: " << RED << e.what() << END << " => [" << RED << line << END << "]" << std::endl;
	}
	// printHeader(btc.getCsvHeader());
}

static void	validationDateTest(const std::string& date, BitcoinExchange& btc)
{
	// std::cout << "date: " << line << std::endl;
	try {
		btc.validationDate(date);
	} catch (const std::exception& e) {
		std::cout << "Error: " << RED << e.what() << END << " => [" << RED << date << END << "]" << std::endl;
	}
}

static void	parseLineTest(std::string line, const std::string& delimiter, BitcoinExchange& btc)
{
	// std::cout << "line: " << line << std::endl;
	// std::cout << "delimiter: " << delimiter << std::endl;
	try {
		btc.parseLine(line, delimiter);
	} catch (const std::exception& e) {
		std::cout << "Error: " << RED << e.what() << END << " => [" << RED << line << END << "]" << std::endl;
	}
}

int	main()
{
	BitcoinExchange	btc;

	std::cout << " [setHeader(); TEST]" << std::endl;
	std::cout << "---------- [" << GREEN "OK" << END << "] ----------" << std::endl;
	setHeaderTest("2011-01-01,0", ",");					setHeaderTest("2011-01-01 | 0", " | ");
	setHeaderTest("2011-01-01,0", ",");					setHeaderTest("2011-01-01 | 0", " | ");
	setHeaderTest("2011-01-01,0.5", ",");					setHeaderTest("2011-01-01 | 0.5", " | ");

	setHeaderTest("2011-01-01,0.000000000000000000000000000000000000005", ",");
	setHeaderTest("2011-01-01 | 0.000000000000000000000000000000000000005", " | ");

	setHeaderTest("2011-01-01,999999999999999999999990.000000000000000000000000000000000000005", ",");
	setHeaderTest("2011-01-01 | 999999999999999999999990.000000000000000000000000000000000000005", " | ");

	setHeaderTest("2011-01-01,999999999999999999999999999999999999999999999999999999999999999", ",");
	setHeaderTest("2011-01-01 | 999999999999999999999999999999999999999999999999999999999999999", " | ");
	std::cout << std::endl;

	std::cout << "---------- [" << RED "NG" << END << "] ----------" << std::endl;
	setHeaderTest("2011-01-01", ",");						setHeaderTest("2011-01-01", " | ");
	setHeaderTest("2011-01-01,", ",");						setHeaderTest("2011-01-01 | ", " | ");
	setHeaderTest("2011-01-01 ,", ",");					setHeaderTest("2011-01-01  | ", " | ");
	setHeaderTest("2011-01-01, ", ",");					setHeaderTest("2011-01-01 |  ", " | ");
	setHeaderTest("2011-01-01 , ", ",");					setHeaderTest("2011-01-01  |  ", " | ");
	setHeaderTest("2011-01-01,a", ",");					setHeaderTest("2011-01-01 | a", " | ");
	setHeaderTest("2011-01-01, 0a", ",");					setHeaderTest("2011-01-01 |  0a", " | ");
	setHeaderTest("2011-01-01,0.5 2011-01-01,0.5", ",");	setHeaderTest("2011-01-01 | 0.5 2011-01-01 | 0.5", " | ");

	setHeaderTest("2011-01-01,-999999999999999999999999999999999999999999999999999999999999999", ",");
	setHeaderTest("2011-01-01 | -999999999999999999999999999999999999999999999999999999999999999", " | ");

	setHeaderTest("2011-01-01 ,0.5", ",");					setHeaderTest("2011-01-01  | 0.5", " | ");
	setHeaderTest("2011-01-01, 0.5", ",");					setHeaderTest("2011-01-01 |  0.5", " | ");
	setHeaderTest("2011-01-01 , 0.5", ",");				setHeaderTest("2011-01-01  |  0.5", " | ");
	setHeaderTest("     2011-01-01,0.5", ",");				setHeaderTest("     2011-01-01 | 0.5", " | ");
	setHeaderTest("2011-01-01     ,0.5", ",");				setHeaderTest("2011-01-01      | 0.5", " | ");
	setHeaderTest("2011-01-01,     0.5", ",");				setHeaderTest("2011-01-01 |      0.5", " | ");
	setHeaderTest("2011-01-01,0.5     ", ",");				setHeaderTest("2011-01-01 | 0.5     ", " | ");
	setHeaderTest("", ",");								setHeaderTest("", " | ");
	setHeaderTest(" ", ",");								setHeaderTest(" ", " | ");
	setHeaderTest(", 0.5", ",");							setHeaderTest(" |  0.5", " | ");
	setHeaderTest(" , 0.5", ",");							setHeaderTest("  |  0.5", " | ");
	setHeaderTest(",2011-01-01,0.5", ",");					setHeaderTest(" | 2011-01-01 | 0.5", " | ");
	setHeaderTest("2011-01-01,,0.5", ",");					setHeaderTest("2011-01-01 |  | 0.5", " | ");
	setHeaderTest("2011-01-01,0.5,", ",");					setHeaderTest("2011-01-01 | 0.5 | ", " | ");
	setHeaderTest("2011-01-01, ,0.5", ",");					setHeaderTest("2011-01-01 |   | 0.5", " | ");
	setHeaderTest(",", ",");					setHeaderTest(" | ", " | ");
	setHeaderTest(",,", ",");					setHeaderTest(" |  | ", " | ");
	setHeaderTest(",,,", ",");					setHeaderTest(" |  |  | ", " | ");
	// setHeaderTest("2011-01-01,0.5", ",");					setHeaderTest("2011-01-01 | 0.5", " | ");
	std::cout << std::endl;

	std::cout << " [parseLine(); TEST]" << std::endl;
	std::cout << "---------- [" << GREEN "OK" << END << "] ----------" << std::endl;
	parseLineTest("2011-01-01,0", ",", btc);					parseLineTest("2011-01-01 | 0", " | ", btc);
	parseLineTest("2011-01-01,0.5", ",", btc);					parseLineTest("2011-01-01 | 0.5", " | ", btc);

	parseLineTest("2011-01-01,0.000000000000000000000000000000000000005", ",", btc);
	parseLineTest("2011-01-01 | 0.000000000000000000000000000000000000005", " | ", btc);

	parseLineTest("2011-01-01,999999999999999999999990.000000000000000000000000000000000000005", ",", btc);
	parseLineTest("2011-01-01 | 999999999999999999999990.000000000000000000000000000000000000005", " | ", btc);

	parseLineTest("2011-01-01,999999999999999999999999999999999999999999999999999999999999999", ",", btc);
	parseLineTest("2011-01-01 | 999999999999999999999999999999999999999999999999999999999999999", " | ", btc);


	std::cout << "\n---------- [" << RED "NG" << END << "] ----------" << std::endl;
	parseLineTest("2011-01-01", ",", btc);						parseLineTest("2011-01-01", " | ", btc);
	parseLineTest("2011-01-01,", ",", btc);						parseLineTest("2011-01-01 | ", " | ", btc);
	parseLineTest("2011-01-01 ,", ",", btc);					parseLineTest("2011-01-01  | ", " | ", btc);
	parseLineTest("2011-01-01, ", ",", btc);					parseLineTest("2011-01-01 |  ", " | ", btc);
	parseLineTest("2011-01-01 , ", ",", btc);					parseLineTest("2011-01-01  |  ", " | ", btc);
	parseLineTest("2011-01-01,a", ",", btc);					parseLineTest("2011-01-01 | a", " | ", btc);
	parseLineTest("2011-01-01, 0a", ",", btc);					parseLineTest("2011-01-01 |  0a", " | ", btc);
	parseLineTest("2011-01-01,0.5 2011-01-01,0.5", ",", btc);	parseLineTest("2011-01-01 | 0.5 2011-01-01 | 0.5", " | ", btc);

	parseLineTest("2011-01-01,-999999999999999999999999999999999999999999999999999999999999999", ",", btc);
	parseLineTest("2011-01-01 | -999999999999999999999999999999999999999999999999999999999999999", " | ", btc);

	parseLineTest("2011-01-01 ,0.5", ",", btc);					parseLineTest("2011-01-01  | 0.5", " | ", btc);
	parseLineTest("2011-01-01, 0.5", ",", btc);					parseLineTest("2011-01-01 |  0.5", " | ", btc);
	parseLineTest("2011-01-01 , 0.5", ",", btc);				parseLineTest("2011-01-01  |  0.5", " | ", btc);
	parseLineTest("     2011-01-01,0.5", ",", btc);				parseLineTest("     2011-01-01 | 0.5", " | ", btc);
	parseLineTest("2011-01-01     ,0.5", ",", btc);				parseLineTest("2011-01-01      | 0.5", " | ", btc);
	parseLineTest("2011-01-01,     0.5", ",", btc);				parseLineTest("2011-01-01 |      0.5", " | ", btc);
	parseLineTest("2011-01-01,0.5     ", ",", btc);				parseLineTest("2011-01-01 | 0.5     ", " | ", btc);
	parseLineTest("", ",", btc);								parseLineTest("", " | ", btc);
	parseLineTest(" ", ",", btc);								parseLineTest(" ", " | ", btc);
	parseLineTest(", 0.5", ",", btc);							parseLineTest(" |  0.5", " | ", btc);
	parseLineTest(" , 0.5", ",", btc);							parseLineTest("  |  0.5", " | ", btc);
	parseLineTest(",2011-01-01,0.5", ",", btc);					parseLineTest(" | 2011-01-01 | 0.5", " | ", btc);
	parseLineTest("2011-01-01,,0.5", ",", btc);					parseLineTest("2011-01-01 |  | 0.5", " | ", btc);
	parseLineTest("2011-01-01,0.5,", ",", btc);					parseLineTest("2011-01-01 | 0.5 | ", " | ", btc);
	parseLineTest("2011-01-01, ,0.5", ",", btc);					parseLineTest("2011-01-01 |   | 0.5", " | ", btc);
	parseLineTest(",", ",", btc);					parseLineTest(" | ", " | ", btc);
	parseLineTest(",,", ",", btc);					parseLineTest(" |  | ", " | ", btc);
	parseLineTest(",,,", ",", btc);					parseLineTest(" |  |  | ", " | ", btc);
	// parseLineTest("2011-01-01,0.5", ",", btc);					parseLineTest("2011-01-01 | 0.5", " | ", btc);

	std::cout << "\n\n [validationDate(); TEST]" << std::endl;
	std::cout << "---------- [" << GREEN "OK" << END << "] ----------" << std::endl;
	validationDateTest("2011-01-01", btc);
	validationDateTest("2012-2-29", btc);

	validationDateTest("2020-04-30", btc);
	validationDateTest("2020-06-30", btc);
	validationDateTest("2020-09-30", btc);
	validationDateTest("2020-11-30", btc);

	validationDateTest("2020-01-31", btc);
	validationDateTest("2020-03-31", btc);
	validationDateTest("2020-05-31", btc);
	validationDateTest("2020-07-31", btc);
	validationDateTest("2020-08-31", btc);
	validationDateTest("2020-10-31", btc);
	validationDateTest("2020-12-31", btc);

	validationDateTest("2011-2-28", btc);
	validationDateTest("2012-2-29", btc);
	validationDateTest("2015-2-28", btc);
	validationDateTest("2016-2-29", btc);
	validationDateTest("2019-2-28", btc);
	validationDateTest("2020-2-29", btc);

	std::cout << "\n---------- [" << RED "NG" << END << "] ----------" << std::endl;
	validationDateTest("a-01-01", btc);
	validationDateTest("2011-a-01", btc);
	validationDateTest("2011-01-a", btc);
	validationDateTest("2011*01-01", btc);
	validationDateTest("2011-01*01", btc);
	validationDateTest("2011-01", btc);
	validationDateTest("-2011-01-01", btc);
	validationDateTest("2011--01-01", btc);
	validationDateTest("2011-01--01", btc);
	validationDateTest("-2147483648-12-31", btc);
	validationDateTest("2012--2147483648-31", btc);
	validationDateTest("2012-12--2147483648", btc);
	validationDateTest("-2147483649-12-31", btc);
	validationDateTest("2012--2147483649-31", btc);
	validationDateTest("2012-12--2147483649", btc);
	validationDateTest("2147483647-12-31", btc);
	validationDateTest("2012-2147483647-31", btc);
	validationDateTest("2012-12-2147483647", btc);
	validationDateTest("2147483648-12-31", btc);
	validationDateTest("2012-2147483648-31", btc);
	validationDateTest("2012-12-2147483648", btc);

	validationDateTest("2008-01-01", btc);
	validationDateTest("2009-00-01", btc);
	validationDateTest("2009-0-01", btc);
	validationDateTest("2009-01-00", btc);

	validationDateTest("2009-13-01", btc);

	validationDateTest("2024-11-15", btc);
	validationDateTest("2023-12-31", btc);
	validationDateTest("2023-11-31", btc);

	validationDateTest("2020-04-31", btc);
	validationDateTest("2020-06-31", btc);
	validationDateTest("2020-09-31", btc);
	validationDateTest("2020-11-31", btc);

	validationDateTest("2020-01-32", btc);
	validationDateTest("2020-03-32", btc);
	validationDateTest("2020-05-32", btc);
	validationDateTest("2020-07-32", btc);
	validationDateTest("2020-08-32", btc);
	validationDateTest("2020-10-32", btc);
	validationDateTest("2020-12-32", btc);

	validationDateTest("2009-2-29", btc);
	validationDateTest("2010-2-29", btc);
	validationDateTest("2011-2-29", btc);
	validationDateTest("2012-2-30", btc);
	validationDateTest("2013-2-29", btc);
	validationDateTest("2014-2-29", btc);
	validationDateTest("2015-2-29", btc);
	validationDateTest("2016-2-30", btc);
	validationDateTest("2017-2-29", btc);
	validationDateTest("2018-2-29", btc);
	validationDateTest("2019-2-29", btc);
	validationDateTest("2020-2-30", btc);
#ifdef LEAKS
	system("leaks -q btc");
#endif // LEAKS
}

#endif // CSV

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
	if (fd.fail() || fd.eof()) {
		std::cout << "Error: " << RED << "failed open file or eof." << END << std::endl;
		return (1);
	}
	std::string	line("");
	// set header
	// std::getline(fd, line, '\n');
	// set record
	while (std::getline(fd, line, '\n')) {
		// if (fd.fail()) {
		// 	std::cout << "Error: " << RED << "Failed getline." << END << std::endl;
		// 	fd.close();
		// 	return (1);
		// }
		std::cout << line << std::endl;
	}
	if (fd.fail()) {
		std::cout << "Error: " << RED << "Failed getline." << END << std::endl;
	}
	fd.close();
	// check extend.(.txt)
	return (0);
}

# endif // TEST
