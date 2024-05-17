// #include <ctime>
#include <deque>
#include <iomanip>
#include <list>
#include <sstream>
#include <vector>
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
		std::Deque<int>	afterDeque = mergeInsertionSort(beforeDeque);
		std::List<int>	afterList = mergeInsertionSort(beforeList);
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
		std::cout << "__________________________________________________" << std::endl;

		std::cout << "Vector: " << std::flush;

		std::vector<int>	beforeVector;	createContainer(&beforeVector, argc, argv);

		std::clock_t		startVector = std::clock();
		std::vector<int>	afterVector = mergeInsertionSort(beforeVector);
		std::clock_t		finishVector = std::clock();

		// std::clock_t		startSortVec = std::clock();
		std::sort(beforeVector.begin(), beforeVector.end());
		// std::clock_t		finishSortVec = std::clock();
		if (beforeVector == afterVector) {
			std::cout << "(" << beforeVector.size() << ") [" << GREEN << "OK" << END << "]" << std::flush;
		} else {
			std::cout << "(" << beforeVector.size() << ") [" << RED << "NG" << END << "]" << std::flush;
			// fatalError("Error", "Not sorted");
		}
		std::vector<Int>	beforeInt = Int::createVectorInt(argc, argv);
		std::sort(beforeInt.begin(), beforeInt.end());
		std::cout << " Merge: (" << MAGENTA << CntPairCompare + CntRecvCompare + CntBinaryInsertCompare << END << ") | (" << MAGENTA << Int::getComparisonCount() << END << ") :std::sort();" << std::endl;



		std::cout << "Deque : " << std::flush;
		CntPairCompare = 0;
		CntRecvCompare = 0;
		CntBinaryInsertCompare = 0;

		std::deque<int>		beforeDeque;	createContainer(&beforeDeque, argc, argv);

		std::clock_t		startDeque = std::clock();
		std::deque<int>		afterDeque = mergeInsertionSort(beforeDeque);
		std::clock_t		finishDeque = std::clock();

		// std::clock_t		startSortDeque = std::clock();
		std::sort(beforeDeque.begin(), beforeDeque.end());
		// std::clock_t		finishSortDeque = std::clock();
		if (beforeDeque == afterDeque) {
			std::cout << "(" << beforeDeque.size() << ") [" << GREEN << "OK" << END << "]" << std::flush;
		} else {
			std::cout << "(" << beforeDeque.size() << ") [" << RED << "NG" << END << "]" << std::flush;
			// fatalError("Error", "Not sorted");
		}
		// std::vector<Int>	beforeInt = Int::createVectorInt(argc, argv);
		// std::sort(beforeInt.begin(), beforeInt.end());
		std::cout << " Merge: (" << MAGENTA << CntPairCompare + CntRecvCompare + CntBinaryInsertCompare << END << ")" << std::endl;
		// | (" << MAGENTA << Int::getComparisonCount() << END << ") :std::sort();" << std::endl;




		std::cout << "List  : " << std::flush;
		CntPairCompare = 0;
		CntRecvCompare = 0;
		CntBinaryInsertCompare = 0;

		std::list<int>		beforeList; createContainer(&beforeList, argc, argv);

		std::clock_t		startList = std::clock();
		std::list<int>		afterList = mergeInsertionSort(beforeList);
		std::clock_t		finishList = std::clock();

		// std::clock_t		startSortList = std::clock();
		// std::sort(beforeList.begin(), beforeList.end());
		// std::clock_t		finishSortList = std::clock();

		beforeList.sort();
		if (beforeList == afterList) {
			std::cout << "(" << beforeList.size() << ") [" << GREEN << "OK" << END << "]" << std::flush;
		} else {
			std::cout << "(" << beforeList.size() << ") [" << RED << "NG" << END << "]" << std::flush;
			// fatalError("Error", "Not sorted");
		}
		// std::vector<Int>	beforeInt = Int::createVectorInt(argc, argv);
		// std::sort(beforeInt.begin(), beforeInt.end());
		std::cout << " Merge: (" << MAGENTA << CntPairCompare + CntRecvCompare + CntBinaryInsertCompare << END << ")" << std::endl;
		// | (" << MAGENTA << Int::getComparisonCount() << END << ") :std::sort();" << std::endl;


		std::setprecision(6);
		double vecTime = static_cast<double>(finishVector - startVector) / CLOCKS_PER_SEC * 1000.0;
		double deqTime = static_cast<double>(finishDeque - startDeque) / CLOCKS_PER_SEC * 1000.0;
		double lisTime = static_cast<double>(finishList - startList) / CLOCKS_PER_SEC * 1000.0;
		std::cout << "VECTOR " << vecTime << " ms | DEQUE " << deqTime << " ms | LIST " << lisTime << " ms" << std::endl;
		std::cout << "--------------------------------------------------" << std::endl;
	} catch (const std::exception& e) {
		fatalError("Error", e.what());
	}
	return (0);
}

#endif  // DEBUG
