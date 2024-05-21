#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <list>
#include "./PmergeMe.hpp"
#include "./color.hpp"

void	fatalError(const std::string& subject, const std::string& message) {
	std::cout << RED << subject << ": " << message << END << std::endl;
	exit(1);
}

// CONSTRUCTOR & DESTRUCTOR
template <typename CONTAINER>
PmergeMe<CONTAINER>::PmergeMe(int argc, char **argv) : compareCount_(0), msTime_(0.0) {
	try {
		this->createContainer(argc, argv);
	} catch (std::exception& e) {
		throw;
	}
}

template <typename CONTAINER>
PmergeMe<CONTAINER>::~PmergeMe() {}

template <typename CONTAINER>
void	PmergeMe<CONTAINER>::createContainer(int argc, char** argv) {
	try {
		for (int i = 1; i < argc; i++) {
			int	num = this->convertStringToInt(argv[i]);
			if (num < 0) {
				throw std::invalid_argument("Negative number");
			}
			if (this->isDuplicate(num)) {
				continue;
				// throw std::invalid_argument("Duplicated number");
			}
			this->before_.push_back(num);
		}
	} catch (const std::exception& e) {
		throw;
	}
}

template <typename CONTAINER>
bool	PmergeMe<CONTAINER>::isDuplicate(int num) {
	try {
		for (typename CONTAINER::const_iterator it = this->before_.begin(); it != this->before_.end(); it++) {
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
int	PmergeMe<CONTAINER>::convertStringToInt(const std::string& str) {
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
template <typename CONTAINER>
const CONTAINER&	PmergeMe<CONTAINER>::getBefore() const {
	return (this->before_);
}

template <typename CONTAINER>
const CONTAINER&	PmergeMe<CONTAINER>::getAfter() const {
	return (this->after_);
}

template <typename CONTAINER>
size_t	PmergeMe<CONTAINER>::getCompareCount() const {
	return (this->compareCount_);
}

template <typename CONTAINER>
double	PmergeMe<CONTAINER>::getMsTime() const {
	return (this->msTime_);
}

template <typename CONTAINER>
void	PmergeMe<CONTAINER>::resetCompareCount() {
	this->compareCount_ = 0;
}

template <typename CONTAINER>
size_t	PmergeMe<CONTAINER>::getJacobsthalNumber(size_t* n) {
	if (*n == 0) {
		return (0);
	}
	if (*n == 1) {
		return (1);
	}

	size_t	twoPrev = 0;
	size_t	onePrev = 1;
	size_t	numN = 0;
	for (size_t i = 2; i <= *n; i++) {
		numN = onePrev + 2 * twoPrev;
		twoPrev = onePrev;
		onePrev = numN;
	}
	*n += 1;
	return (numN);
}

template <typename CONTAINER>
size_t	PmergeMe<CONTAINER>::getDistance(typename CONTAINER::const_iterator begin, typename CONTAINER::const_iterator end) {
	size_t	dist = 0;
	for (; begin != end; begin++) {
		dist += 1;
	}
	return (dist);
}

template <typename CONTAINER>
typename CONTAINER::const_iterator	PmergeMe<CONTAINER>::getBackIterator(typename CONTAINER::const_iterator end) {
	end--;
	return (end);
}

template <typename CONTAINER>
typename CONTAINER::const_iterator	PmergeMe<CONTAINER>::getMiddleIterator(typename CONTAINER::const_iterator left, typename CONTAINER::const_iterator right) {
	try {
		size_t	n = this->getDistance(left, right) / 2;

		for (size_t i = 0; i < n; i++) {
			left++;
		}
		return (left);
	} catch (std::exception& e) {
		throw;
	}
}

template <typename CONTAINER>
std::vector<std::pair<int, int> >	PmergeMe<CONTAINER>::createPairs(CONTAINER container) {
	try {
		std::vector<std::pair<int, int> >	pairs;
		for (typename CONTAINER::iterator it = container.begin(); it != container.end(); it++) {
			typename CONTAINER::iterator nextIt = it;
			nextIt++;
			if (nextIt == container.end()) {
				pairs.push_back(std::make_pair(-1, *it));
				break;
			}
			this->compareCount_ += 1;
			if (*it < *nextIt) {
				pairs.push_back(std::make_pair(*nextIt, *it));
			} else {
				pairs.push_back(std::make_pair(*it, *nextIt));
			}
			it = nextIt;
		}
		return (pairs);
	} catch (std::exception& e) {
		throw;
	}
}

template <typename CONTAINER>
CONTAINER	PmergeMe<CONTAINER>::getLarges(const std::vector<std::pair<int, int> >& pairs) {
	try {
		CONTAINER	larges;
		for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); it++) {
			if (it->first != -1) {
				larges.push_back(it->first);
			}
		}
		return (larges);
	} catch (std::exception& e) {
		throw;
	}
}

template <typename CONTAINER>
CONTAINER	PmergeMe<CONTAINER>::getSmalls(const std::vector<std::pair<int, int> >& pairs, const CONTAINER& sorted) {
	try {
		CONTAINER	smalls;
		for (typename CONTAINER::const_iterator sortedIt = sorted.begin(); sortedIt != sorted.end(); sortedIt++) {
			for (std::vector<std::pair<int, int> >::const_iterator pairsIt = pairs.begin(); pairsIt != pairs.end(); pairsIt++) {
				if (*sortedIt == pairsIt->first) {
					smalls.push_back(pairsIt->second);
					break;
				}
			}
		}
		if (pairs[pairs.size() - 1].first == -1) {
			smalls.push_back(pairs[pairs.size() - 1].second);
		}
		return (smalls);
	} catch (std::exception& e) {
		throw;
	}
}

template <typename CONTAINER>
typename CONTAINER::const_iterator	PmergeMe<CONTAINER>::selectInsertionRange(size_t* n, const CONTAINER& smalls, typename CONTAINER::const_iterator begin) {
	try {
		typename CONTAINER::const_iterator	end = begin;
		end++;
		if (end == smalls.end()) {
			return (end);
		}
		for (; end != this->getBackIterator(smalls.end()); end++) {
			if (this->getDistance(begin, end) == (this->getJacobsthalNumber(n) * 2)) {
				break;
			}
		}
		return (end);
	} catch (std::exception& e) {
		throw;
	}
}

template <typename CONTAINER>
typename CONTAINER::const_iterator	PmergeMe<CONTAINER>::getRightIterator(const std::vector<std::pair<int, int> >& pairs, const CONTAINER& sorted, int target) {
	try {
		typename CONTAINER::const_iterator					right = sorted.end();
		std::vector<std::pair<int, int> >::const_iterator	pairsIt = pairs.begin();
		for (; pairsIt != pairs.end(); pairsIt++) {
			if (pairsIt->second == target) {
				break;
			}
		}
		if (pairsIt == pairs.end()) {
			return (right);
		}
		if (pairsIt->first == -1) {
			return (right);
		}
		for (typename CONTAINER::const_iterator sortedIt = getBackIterator(sorted.end()); sortedIt != sorted.begin(); sortedIt--) {
			right--;
			if (pairsIt->first == (*sortedIt)) {
				break;
			}
		}
		return (right);
	} catch (std::exception& e) {
		throw;
	}
}

template <typename CONTAINER>
typename CONTAINER::const_iterator	PmergeMe<CONTAINER>::getSortPosition(const std::vector<std::pair<int, int> >& pairs, const CONTAINER& sorted, int target) {
	try {
		typename CONTAINER::const_iterator	left = sorted.begin();
		typename CONTAINER::const_iterator	right = this->getRightIterator(pairs, sorted, target);
		while (this->getDistance(left, sorted.end()) > this->getDistance(right, sorted.end())) {
			typename CONTAINER::const_iterator	middle = this->getMiddleIterator(left, right);
			this->compareCount_ += 1;
			if (target < *middle) {
				right = middle;
			} else {
				left = middle;
				left++;
			}
		}
		// this->printRange("binary", left, right);
		return (left);
	} catch (std::exception& e) {
		throw;
	}
}

template <typename CONTAINER>
CONTAINER	PmergeMe<CONTAINER>::mergeInsertionSort(CONTAINER container) {
	try {
		if (container.size() < 2) {
			return (container);
		}
		if (container.size() == 2) {
			this->compareCount_ += 1;
			if (container.front() > container.back()) {
				std::swap(container.front(), container.back());
			}
			return (container);
		}
		std::vector<std::pair<int, int> >	pairs = this->createPairs(container);
		CONTAINER							larges = this->getLarges(pairs);
		// printPairs("pairs", pairs); printContainer("larges", larges); std::cout << std::endl;

		CONTAINER							sorted = this->mergeInsertionSort(larges);
		// std::cout << std::endl; printContainer("sorted", sorted);

		CONTAINER							smalls = this->getSmalls(pairs, sorted);
		// printContainer("smalls", smalls);

		sorted.insert(sorted.begin(), *(smalls.begin()));
		size_t	n = 1;
		typename CONTAINER::const_iterator	end;
		for (typename CONTAINER::const_iterator	begin = smalls.begin(); begin != smalls.end(); begin = end) {
			end = this->selectInsertionRange(&n, smalls, begin);
			if (end == smalls.end()) {
				break;
			}

			typename CONTAINER::const_iterator	target = end;
			// std::cout << "target: " << *target << std::endl;
			while (target != begin) {
				// Binary search
				typename CONTAINER::const_iterator	sortPos = this->getSortPosition(pairs, sorted, *target);
				sorted.insert(sortPos, *target);
				target--;
			}
		}
		// printContainer("sorted", sorted); std::cout << std::endl;
		return (sorted);
	} catch (std::exception& e) {
		throw;
	}
}

template <typename CONTAINER>
void	PmergeMe<CONTAINER>::sort() {
	try {
		std::clock_t	start = std::clock();
		this->after_ = this->mergeInsertionSort(this->before_);
		std::clock_t	finish = std::clock();
		this->msTime_ = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	} catch (std::exception& e) {
		throw;
	}
}

// DEBUG
template <typename CONTAINER>
void	PmergeMe<CONTAINER>::printContainer(const std::string& subject, const CONTAINER& container) const {
	std::cout << subject << ": " << std::flush;
	for (typename CONTAINER::const_iterator it = container.begin(); it != container.end(); it++) {
		std::cout << *it << " " << std::flush;
	}
	std::cout << std::endl;
}

template <typename CONTAINER>
void	PmergeMe<CONTAINER>::printRange(const std::string& subject, typename CONTAINER::const_iterator begin, typename CONTAINER::const_iterator end) const {
	std::cout << subject << ": " << std::flush;
	for (; begin != end; begin++) {
		std::cout << *begin << ", "<< std::flush;
	}
	std::cout << *end << std::endl;
}

// DEBUG
template <typename CONTAINER>
void	PmergeMe<CONTAINER>::printPairs(const std::string& str, const std::vector<std::pair<int, int> >& pairs) const {
	std::cout << str << ": " << std::flush;
	for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); it++) {
		std::cout << "[" << it->first << ", " << it->second << "]" << std::flush;
		if (it != pairs.end()) {
			std::cout << ", " << std::flush;
		}
	}
	std::cout << std::endl;
}

template <typename CONTAINER>
void	PmergeMe<CONTAINER>::printMsTime(const std::string& type) const {
	std::cout << "Time to process a range of " << GREEN << this->before_.size() << END << " elements with " << type << " : " << GREEN << this->msTime_ << END << " ms" << std::endl;
}

template <typename CONTAINER>
void	PmergeMe<CONTAINER>::printResult() const {
	this->printContainer("Before", this->before_);
	this->printContainer("After ", this->after_);
}

template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::list<int> >;

#ifdef DEBUG
#include <deque>
template class PmergeMe<std::deque<int> >;
#endif  // DEBUG
