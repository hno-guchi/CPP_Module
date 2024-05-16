#include <sstream>
#include "./PmergeMe.hpp"
#include "./color.hpp"

int	CntPairCompare = 0;
int	CntRecvCompare = 0;
int	CntBinaryInsertCompare = 0;

static int convertStringToInt(const std::string& str) {
	try {
		std::stringstream	ss(str);
		int					ret;

		ss >> ret;
		if (ss.fail()) {
			throw std::runtime_error("Failed to convertStringToInt();");
		}
		return (ret);
	} catch (const std::exception& e) {
		throw;
	}
}

static bool	isDuplicated(const std::vector<int>& vec, int num) {
	try {
		for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++) {
			if (*it == num) {
				return (true);
				// throw std::invalid_argument("Duplicated number");
			}
		}
		return (false);
	} catch (const std::exception& e) {
		throw;
	}
}

std::vector<int>	createVectorInt(int argc, char** argv) {
	try {
		std::vector<int>	ret;
		for (int i = 1; i < argc; i++) {
			int	num = convertStringToInt(argv[i]);
			if (num < 0) {
				throw std::invalid_argument("Negative number");
			}
			if (isDuplicated(ret, num)) {
				continue;
				// throw std::invalid_argument("Duplicated number");
			}
			ret.push_back(num);
		}
		return (ret);
	} catch (const std::exception& e) {
		throw;
	}
}

#ifndef DEBUG

int main(int argc, char** argv) {
	try {
		if (argc == 1) {
			fatalError("Error", "No arguments");
		}
		std::vector<int>	before = createVectorInt(argc, argv);
		std::vector<int>	after = mergeInsertionSort(before);
		printInt("Before", before);
		printInt("After ", after);
	} catch (const std::exception& e) {
		fatalError("Error", e.what());
	}
	return (0);
}

#endif  // DEBUG

#ifdef DEBUG

#include <algorithm>
#include "./Int.hpp"

int main(int argc, char** argv) {
	try {
		if (argc == 1) {
			fatalError("Error", "No arguments");
		}
		std::vector<int>	before = createVectorInt(argc, argv);
		std::vector<int>	after = mergeInsertionSort(before);
		std::sort(before.begin(), before.end());
		if (before != after) {
			fatalError("Error", "Not sorted");
		} else {
			std::cout << "(" << before.size() << ")[" << GREEN << "OK" << END << "]" << std::flush;
		}
		std::vector<Int>	beforeInt = Int::createVectorInt(argc, argv);
		std::sort(beforeInt.begin(), beforeInt.end());

		std::cout << " Merge: " << MAGENTA << CntPairCompare + CntRecvCompare + CntBinaryInsertCompare << END << std::flush;
		std::cout << " | " << MAGENTA << Int::getComparisonCount() << END << " :std::sort();" << std::flush;
	} catch (const std::exception& e) {
		fatalError("Error", e.what());
	}
	return (0);
}

#endif  // DEBUG
