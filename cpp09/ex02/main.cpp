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
		PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > >	vector(argc, argv);
		vector.sort();
		vector.printResult();
		vector.printMsTime("std::vector<int>");

		PmergeMe<std::list<int>, std::list<std::pair<int, int> > >	list(argc, argv);
		list.sort();
		// list.printResult();
		list.printMsTime("std::list<int>  ");
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
#include <deque>
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
		PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > >	vector(argc, argv);
		vector.sort();
		std::vector<int>			vec = vector.getBefore();
		start = std::clock();
		std::sort(vec.begin(), vec.end());
		finish = std::clock();

		if (vec == vector.getAfter()) {
			std::cout << "(" << vector.getBefore().size() << ") [" << GREEN << "OK" << END << "]" << std::flush;
		} else {
			std::cout << "(" << vector.getBefore().size() << ") [" << RED << "NG" << END << "]" << std::flush;
			// fatalError("Error", "Not sorted");
		}

		std::vector<Int>	vectorInt;
		Int::createContainer(&vectorInt, argc, argv);
		Int::resetComparisonCount();
		std::sort(vectorInt.begin(), vectorInt.end());

		time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
		std::cout << " PmergeMe: [" << vector.getMsTime() << "] ms (" << MAGENTA << vector.getCompareCount() << END << ") | (" << MAGENTA << Int::getComparisonCount() << END << ") [" << time << "] ms :std::sort();" << std::endl;



		std::cout << "Deque : " << std::flush;
		PmergeMe<std::deque<int>, std::deque<std::pair<int, int> > >	deque(argc, argv);
		deque.sort();
		std::deque<int>				deq = deque.getBefore();
		start = std::clock();
		std::sort(deq.begin(), deq.end());
		finish = std::clock();

		if (deq == deque.getAfter()) {
			std::cout << "(" << deque.getBefore().size() << ") [" << GREEN << "OK" << END << "]" << std::flush;
		} else {
			std::cout << "(" << deque.getBefore().size() << ") [" << RED << "NG" << END << "]" << std::flush;
			// fatalError("Error", "Not sorted");
		}
		std::deque<Int>	dequeInt;
		Int::createContainer(&dequeInt, argc, argv);
		Int::resetComparisonCount();
		std::sort(dequeInt.begin(), dequeInt.end());
		time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
		std::cout << " PmergeMe: [" << deque.getMsTime() << "] ms (" << MAGENTA << deque.getCompareCount() << END << ") | (" << MAGENTA << Int::getComparisonCount() << END << ") [" << time << "] ms :std::sort();" << std::endl;




		std::cout << "List  : " << std::flush;
		PmergeMe<std::list<int>, std::list<std::pair<int, int> > >	list(argc, argv);
		list.sort();
		std::list<int>				li = list.getBefore();
		start = std::clock();
		li.sort();
		finish = std::clock();

		if (li == list.getAfter()) {
			std::cout << "(" << list.getBefore().size() << ") [" << GREEN << "OK" << END << "]" << std::flush;
		} else {
			std::cout << "(" << list.getBefore().size() << ") [" << RED << "NG" << END << "]" << std::flush;
			// fatalError("Error", "Not sorted");
		}
		std::list<Int>	listInt;
		Int::createContainer(&listInt, argc, argv);
		Int::resetComparisonCount();
		listInt.sort();
		time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
		std::cout << " PmergeMe: [" << list.getMsTime() << "] ms (" << MAGENTA << list.getCompareCount() << END << ") | (" << MAGENTA << Int::getComparisonCount() << END << ") [" << time << "] ms :std::sort();" << std::endl;



		std::setprecision(6);
		std::cout << std::endl;
		std::cout << "VECTOR " << YELLOW << vector.getMsTime() << END << " ms | DEQUE " << YELLOW << deque.getMsTime() << END << " ms | LIST " << YELLOW << list.getMsTime() << END << " ms" << std::endl;
		std::cout << "--------------------------------------------------" << std::endl;
	} catch (const std::exception& e) {
		fatalError("Error", e.what());
	}
	return (0);
}

#endif  // DEBUG
