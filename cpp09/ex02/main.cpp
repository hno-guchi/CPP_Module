#include <iomanip>
#include <list>
// #include <sstream>
#include <vector>
#include "./PmergeMe.hpp"
#include "./color.hpp"

void	fatalError(const std::string& subject, const std::string& message) {
	std::cout << RED << subject << ": " << message << END << std::endl;
	exit(1);
}

#ifndef DEBUG

int main(int argc, char** argv) {
	try {
		if (argc == 1) {
			fatalError("Error", "No arguments");
		}
		PmergeMe	p(argc, argv);
		p.sort();
		p.printResult();
		p.printMsTime();

	} catch (const std::exception& e) {
		fatalError("Error", e.what());
	}
#ifdef LEAKS
	system("leaks -q PmergeMe");
#endif  // LEAKS
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

		std::clock_t				start;
		std::clock_t				finish;
		double						time(0.0);

		std::cout << "__________________________________________________" << std::endl;
		std::cout << "Vector: " << std::flush;
		PmergeMe	p(argc, argv);
		p.sort();
		std::vector<int>			vec = p.getVecBefore();
		start = std::clock();
		std::sort(vec.begin(), vec.end());
		finish = std::clock();

		std::vector<Int>	vectorInt;
		Int::setValues(&vectorInt, argc, argv);
		Int::resetComparisonCount();
		std::sort(vectorInt.begin(), vectorInt.end());

		if (vec == p.getVecAfter()) {
			std::cout << "(" << p.getVecBefore().size() << ") [" << GREEN << "OK" << END << "]" << std::flush;
		} else {
			std::cout << "(" << p.getVecBefore().size() << ") [" << RED << "NG" << END << "]" << std::flush;
		}
		time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
		std::cout << " PmergeMe: [" << p.getVecMsTime() << "] ms (" << MAGENTA << p.getVecCompareCount() << END << ") | (" << MAGENTA << Int::getComparisonCount() << END << ") [" << time << "] ms :std::sort();" << std::endl;

		std::cout << "List  : " << std::flush;
		std::list<int>				li = p.getLstBefore();
		start = std::clock();
		li.sort();
		finish = std::clock();

		std::list<Int>	listInt;
		Int::setValues(&listInt, argc, argv);
		Int::resetComparisonCount();
		listInt.sort();
		if (li == p.getLstAfter()) {
			std::cout << "(" << p.getLstBefore().size() << ") [" << GREEN << "OK" << END << "]" << std::flush;
		} else {
			std::cout << "(" << p.getLstBefore().size() << ") [" << RED << "NG" << END << "]" << std::flush;
			// fatalError("Error", "Not sorted");
		}
		time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
		std::cout << " PmergeMe: [" << p.getLstMsTime() << "] ms (" << MAGENTA << p.getLstCompareCount() << END << ") | (" << MAGENTA << Int::getComparisonCount() << END << ") [" << time << "] ms :std::sort();" << std::endl;
		std::cout << "--------------------------------------------------" << std::endl;
	} catch (const std::exception& e) {
		fatalError("Error", e.what());
	}
	return (0);
}

#endif  // DEBUG
