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
static bool	isDuplicate(const CONTAINER& container, int num) {
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
			if (isDuplicate(*container, num)) {
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
		std::vector<int>	beforeVect;
		createContainer(&beforeVect, argc, argv);
		std::clock_t		startVect = std::clock();
		std::vector<int>	afterVect = mergeInsertionSort(beforeVect);
		std::clock_t		finishVect = std::clock();

		std::list<int>		beforeList;
		createContainer(&beforeList, argc, argv);
		std::clock_t		startList = std::clock();
		std::list<int>		afterList = mergeInsertionSort(beforeList);
		std::clock_t		finishList = std::clock();

		printInt("Before", beforeVect);
		printInt("After ", afterVect);
		double	vectTime = static_cast<double>(finishVect - startVect) / CLOCKS_PER_SEC * 1000.0;
		double	listTime = static_cast<double>(finishList - startList) / CLOCKS_PER_SEC * 1000.0;
		std::cout << "Time to process a range of " << GREEN << beforeVect.size() << END << " elements with std::vector<int> : " << GREEN << vectTime << END << " ms" << std::endl;
		std::cout << "Time to process a range of " << GREEN << beforeList.size() << END << " elements with std::list<int>   : " << GREEN << listTime << END << " ms" << std::endl;
	} catch (const std::exception& e) {
		fatalError("Error", e.what());
	}
	return (0);
}

#endif  // DEBUG

#ifdef DEBUG

#include <algorithm>
#include <deque>
#include "./Int.hpp"

int main(int argc, char** argv) {
	try {
		if (argc == 1) {
			fatalError("Error", "No arguments");
		}
		std::cout << "__________________________________________________" << std::endl;
		std::cout << "Vector: " << std::flush;

		std::vector<int>	beforeVector;
		createContainer(&beforeVector, argc, argv);

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
		std::vector<Int>	beforeVecInt;
		Int::createContainer(&beforeVecInt, argc, argv);
		Int::resetComparisonCount();
		std::sort(beforeVecInt.begin(), beforeVecInt.end());
		std::cout << " Merge: (" << MAGENTA << CntPairCompare + CntRecvCompare + CntBinaryInsertCompare << END << ") | (" << MAGENTA << Int::getComparisonCount() << END << ") :std::sort();" << std::endl;



		std::cout << "Deque : " << std::flush;
		CntPairCompare = 0;
		CntRecvCompare = 0;
		CntBinaryInsertCompare = 0;

		std::deque<int>		beforeDeque;
		createContainer(&beforeDeque, argc, argv);

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
		std::deque<Int>	beforeDeqInt;
		Int::createContainer(&beforeDeqInt, argc, argv);
		Int::resetComparisonCount();
		std::sort(beforeDeqInt.begin(), beforeDeqInt.end());
		std::cout << " Merge: (" << MAGENTA << CntPairCompare + CntRecvCompare + CntBinaryInsertCompare << END << ") | (" << MAGENTA << Int::getComparisonCount() << END << ") :std::sort();" << std::endl;




		std::cout << "List  : " << std::flush;
		CntPairCompare = 0;
		CntRecvCompare = 0;
		CntBinaryInsertCompare = 0;

		std::list<int>		beforeList; createContainer(&beforeList, argc, argv);

		std::clock_t		startList = std::clock();
		std::list<int>		afterList = mergeInsertionSort(beforeList);
		std::clock_t		finishList = std::clock();

		// std::clock_t		startSortList = std::clock();
		beforeList.sort();
		// std::clock_t		finishSortList = std::clock();

		if (beforeList == afterList) {
			std::cout << "(" << beforeList.size() << ") [" << GREEN << "OK" << END << "]" << std::flush;
		} else {
			std::cout << "(" << beforeList.size() << ") [" << RED << "NG" << END << "]" << std::flush;
			// fatalError("Error", "Not sorted");
		}
		std::list<Int>	beforeListInt; Int::createContainer(&beforeListInt, argc, argv);
		Int::resetComparisonCount();
		beforeListInt.sort();
		std::cout << " Merge: (" << MAGENTA << CntPairCompare + CntRecvCompare + CntBinaryInsertCompare << END << ") | (" << MAGENTA << Int::getComparisonCount() << END << ") :std::sort();" << std::endl;



		std::setprecision(6);
		double vecTime = static_cast<double>(finishVector - startVector) / CLOCKS_PER_SEC * 1000.0;
		double deqTime = static_cast<double>(finishDeque - startDeque) / CLOCKS_PER_SEC * 1000.0;
		double lisTime = static_cast<double>(finishList - startList) / CLOCKS_PER_SEC * 1000.0;
		std::cout << std::endl;
		std::cout << "VECTOR " << YELLOW << vecTime << END << " ms | DEQUE " << YELLOW << deqTime << END << " ms | LIST " << YELLOW << lisTime << END << " ms" << std::endl;
		std::cout << "--------------------------------------------------" << std::endl;
	} catch (const std::exception& e) {
		fatalError("Error", e.what());
	}
	return (0);
}

#endif  // DEBUG
