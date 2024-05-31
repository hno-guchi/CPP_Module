#include <iostream>
#include <iomanip>
#include <sstream>
#include <utility>
#include <vector>
#include <list>
#include "./PmergeMe.hpp"
#include "./color.hpp"

// CONSTRUCTOR & DESTRUCTOR
PmergeMe::PmergeMe(int argc, char **argv) :
	vecCompareCount_(0), lstCompareCount_(0), vecMsTime_(0.0), lstMsTime_(0.0) {
	try {
		this->createContainer(argc, argv);
	} catch (std::exception& e) {
		throw;
	}
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::createContainer(int argc, char** argv) {
	try {
		for (int i = 1; i < argc; i++) {
			int	num = this->convertStringToInt(argv[i]);
			if (num < 0) {
				throw std::invalid_argument("Negative number");
			}
			if (this->isDuplicate(num)) {
				// std::cout << "Ignore duplicate number: " << num << std::endl;
				// throw std::invalid_argument("Duplicated number");
				continue;
			}
			this->vecBefore_.push_back(num);
			this->lstBefore_.push_back(num);
		}
	} catch (const std::exception& e) {
		throw;
	}
}

bool	PmergeMe::isDuplicate(int num) {
	try {
		for (std::vector<int>::const_iterator it = this->vecBefore_.begin(); it != this->vecBefore_.end(); it++) {
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

int	PmergeMe::convertStringToInt(const std::string& str) {
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

// GETTER
const std::vector<int>&	PmergeMe::getVecBefore() const {
	return (this->vecBefore_);
}

const std::list<int>&	PmergeMe::getLstBefore() const {
	return (this->lstBefore_);
}

const std::vector<int>&	PmergeMe::getVecAfter() const {
	return (this->vecAfter_);
}

const std::list<int>&	PmergeMe::getLstAfter() const {
	return (this->lstAfter_);
}

size_t	PmergeMe::getVecCompareCount() const {
	return (this->vecCompareCount_);
}

size_t	PmergeMe::getLstCompareCount() const {
	return (this->lstCompareCount_);
}

double	PmergeMe::getVecMsTime() const {
	return (this->vecMsTime_);
}

double	PmergeMe::getLstMsTime() const {
	return (this->lstMsTime_);
}

void	PmergeMe::resetCompareCount() {
	this->vecCompareCount_ = 0;
	this->lstCompareCount_ = 0;
}

size_t	PmergeMe::getJacobsthalNumber(size_t n) {
	if (n == 0) {
		return (0);
	}
	if (n == 1) {
		return (1);
	}

	size_t	twoPrev = 0;
	size_t	onePrev = 1;
	size_t	numN = 0;
	for (size_t i = 2; i <= n; i++) {
		numN = onePrev + 2 * twoPrev;
		twoPrev = onePrev;
		onePrev = numN;
	}
	return (numN);
}

void	PmergeMe::sort() {
	try {
		std::clock_t	start = 0;
		std::clock_t	finish = 0;

		start = std::clock();
		this->vecAfter_ = this->mergeInsertionSort(this->vecBefore_);
		finish = std::clock();
		this->vecMsTime_ = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;

		start = std::clock();
		this->lstAfter_ = this->mergeInsertionSort(this->lstBefore_);
		finish = std::clock();
		this->lstMsTime_ = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	} catch (std::exception& e) {
		throw;
	}
}

// DEBUG
void	PmergeMe::printContainer(const std::string& subject, const std::vector<int>& container) const {
	std::cout << subject << ": " << std::flush;
	for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); it++) {
		std::cout << *it << " " << std::flush;
	}
	std::cout << std::endl;
}

void	PmergeMe::printContainer(const std::string& subject, const std::list<int>& container) const {
	std::cout << subject << ": " << std::flush;
	for (std::list<int>::const_iterator it = container.begin(); it != container.end(); it++) {
		std::cout << *it << " " << std::flush;
	}
	std::cout << std::endl;
}

void	PmergeMe::printRange(const std::string& subject, std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) const {
	std::cout << subject << ": " << std::flush;
	for (; begin != end; begin++) {
		std::cout << *begin << ", "<< std::flush;
	}
	std::cout << *end << std::endl;
}

void	PmergeMe::printRange(const std::string& subject, std::list<int>::const_iterator begin, std::list<int>::const_iterator end) const {
	std::cout << subject << ": " << std::flush;
	for (; begin != end; begin++) {
		std::cout << *begin << ", "<< std::flush;
	}
	std::cout << *end << std::endl;
}

void	PmergeMe::printPairs(const std::string& str, const std::vector<std::pair<int, int> >& pairs) const {
	std::cout << str << ": " << std::flush;
	for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); it++) {
		std::cout << "[" << it->first << ", " << it->second << "]" << std::flush;
		if (it != pairs.end()) {
			std::cout << ", " << std::flush;
		}
	}
	std::cout << std::endl;
}

void	PmergeMe::printPairs(const std::string& str, const std::list<std::pair<int, int> >& pairs) const {
	std::cout << str << ": " << std::flush;
	for (std::list<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); it++) {
		std::cout << "[" << it->first << ", " << it->second << "]" << std::flush;
		if (it != pairs.end()) {
			std::cout << ", " << std::flush;
		}
	}
	std::cout << std::endl;
}

void	PmergeMe::printMsTime() const {
	// std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << GREEN << this->vecBefore_.size() << END << " elements with std::vector<int> : " << GREEN << this->vecMsTime_ << END << " ms" << std::endl;
	std::cout << "Time to process a range of " << GREEN << this->lstBefore_.size() << END << " elements with std::list<int> : " << GREEN << this->lstMsTime_ << END << " ms" << std::endl;
}

void	PmergeMe::printResult() const {
	this->printContainer("Before", this->vecBefore_);
	this->printContainer("After ", this->vecAfter_);
}
