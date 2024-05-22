#include "./BitcoinExchange.hpp"

void	fatalError(const std::string& msg) {
	std::cerr << RED << "fatal error: " << END << msg << std::endl;
	exit(1);
}

static bool	isValue(const std::string &str) {
	if (str.empty()) {
		return (false);
	}
	std::locale					l = std::locale::classic();
	std::string::const_iterator	it = str.begin();
	if (!std::isdigit(*it, l)) {
		return (false);
	}
	it++;
	bool	dot = false;
	for (; it != str.end(); it++) {
		if (*it == '.' && dot) {
			return (false);
		} else if (*it == '.' && (it + 1) == str.end()) {
			return (false);
		} else if (*it == '.') {
			dot = true;
			continue;
		}
		if (!std::isdigit(*it, l)) {
			return (false);
		}
	}
	return (true);
}

// static bool	isFuncString(const std::string &str, bool (*func)(const char)) {
// 	return (std::find_if(str.begin(), str.end(), func) == str.end());
// }

// CONSTRUCTOR & DESTRUCTOR
BitcoinExchange::BitcoinExchange(const std::string& fileName) : Csv(fileName) {}
BitcoinExchange::~BitcoinExchange() {}

int	main(int argc, char** argv) {
	if (argc != 2) {
		fatalError("Usage: ./btc [input file name]");
	}
	try {
		BitcoinExchange	btc("data.csv");
		std::ifstream	fd(argv[1]);
		if (!fd.eof() && fd.fail()) {
			throw std::runtime_error("Failed std::ifstream()");
		}
		if (fd.eof()) {
			throw std::runtime_error("Empty file.");
		}
		std::string	line("");
		std::string	delimiter(" | ");
		std::getline(fd, line, '\n');
		if (!fd.eof() && fd.fail()) {
			throw std::runtime_error("Failed std::getline().");
		}
		while (std::getline(fd, line, '\n')) {
				if (line.empty()) {
					std::cout << RED << "Valid error: Empty line." << END << std::endl;
					continue;
				}
				std::string	dateStr = line.substr(0, line.find(delimiter));
				if (dateStr.empty()) {
					std::cout << RED << "Valid error: Empty date." << END << std::endl;
					continue;
				}
				if (line.find(delimiter) == std::string::npos) {
					std::cout << RED << "Valid error: Failed to find delimiter. => " << END << "[" << dateStr << "]" << std::endl;
					continue;
				}
				if (line.find(delimiter) + delimiter.size() >= line.size()) {
					std::cout << RED << "Valid error: Failed to find value. => " << END << "[" << dateStr << "]" << std::endl;
					continue;
				}
				time_t	date(0);
				try {
					date = btc.getUnixTimeStampFromStr(dateStr);
				} catch (const std::exception& e) {
					std::cout << RED << "Valid error: " << e.what() << " => " << END << "[" << dateStr << "]" << std::endl;
					continue;
				}
				std::string	valueStr = line.substr(line.find(delimiter) + delimiter.size());
				if (!isValue(valueStr)) {
					std::cout << RED << "Valid error: not a number. => " << END << "[" << valueStr << "]" << std::endl;
					continue;
				}
				float	value(0.0);
				try {
					value = btc.getFloatFromStr(valueStr);
				} catch (const std::exception& e) {
					std::cout << RED << "Valid error: " << e.what() << " => " << "[" << valueStr << "]" << std::endl;
					continue;
				}
				if (value < 0.0) {
					std::cout << RED << "Valid error: not a positive number. => " << END << "[" << valueStr << "]" << std::endl;
					continue;
				} else if (value > 1000.0) {
					std::cout << RED << "Valid error: too large a number. => " << END << "[" << valueStr << "]" << std::endl;
					continue;
				}
				std::cout << date << "," << value << std::endl;
		}
		if (!fd.eof() && fd.fail()) {
			throw std::runtime_error("Failed std::getline().");
		}
		fd.close();
		if (!fd.eof() && fd.fail()) {
			throw std::runtime_error("Failed std::ifstream::close().");
		}
	} catch (const std::exception& e) {
		fatalError(e.what());
	}
}
