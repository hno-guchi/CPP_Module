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

template <typename CONTAINER>
static bool	isDuplicated(const CONTAINER& container, int num) {
	try {
		for (typename CONTAINER::const_iterator it = container.begin(); it != container.end(); it++) {
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

template <typename CONTAINER>
void	createContainer(CONTAINER* container, int argc, char** argv) {
	try {
		for (int i = 1; i < argc; i++) {
			int	num = convertStringToInt(argv[i]);
			if (num < 0) {
				throw std::invalid_argument("Negative number");
			}
			if (isDuplicated(*container, num)) {
				continue;
				// throw std::invalid_argument("Duplicated number");
			}
			container->push_back(num);
		}
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
		std::vector<int>	beforeVector;
		std::deque<int>		beforeDeque;
		std::list<int>		beforeList;

		createContainer(&beforeVector, argc, argv);
		createContainer(&beforeDeque, argc, argv);
		createContainer(&beforeList, argc, argv);
		std::vector<int>	afterVector = mergeInsertionSort(beforeVector);
		std::vector<int>	after = mergeInsertionSort(beforeDeque);
		std::vector<int>	after = mergeInsertionSort(beforeList);
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
		std::vector<int>	before; createContainer(&before, argc, argv);
		std::vector<int>	after = mergeInsertionSort(before);
		std::sort(before.begin(), before.end());
		if (before == after) {
			std::cout << "(" << before.size() << ")[" << GREEN << "OK" << END << "]" << std::flush;
		} else {
			fatalError("Error", "Not sorted");
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
