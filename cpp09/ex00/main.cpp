#include "./BitcoinExchange.hpp"
#include "./color.hpp"

int	main(int argc, char** argv) {
	if (argc != 2) {
		fatalError("Usage: ./btc [input file name]");
	}
	try {
		BitcoinExchange	btc("data.csv");

		btc.printResults(argv[1]);
		std::cout << MAGENTA << "----------------------------------------\n" << END << std::endl;
	} catch (const std::exception& e) {
		fatalError(e.what());
	}
#ifdef LEAKS
	system("leaks -q btc");
#endif  // LEAKS
}
