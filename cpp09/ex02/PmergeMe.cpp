#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <list>
#include "./PmergeMe.hpp"
#include "./color.hpp"

void	fatalError(const std::string& prefix, const std::string& message) {
	std::cout << RED << prefix << ": " << message << END << std::endl;
	exit(1);
}

void	printInt(const std::string& str, const std::vector<int>& vec) {
	std::cout << str << ": " << std::flush;
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << std::flush;
		if ((it + 1) != vec.end()) {
			std::cout << ", " << std::flush;
		}
	}
	std::cout << std::endl;
}

void	printPair(const std::string& str, const std::vector<std::pair<int, int> >& vec) {
	std::cout << str << ": " << std::flush;
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << "[" << std::flush;
		if (vec[i].first < 10) {
			std::cout << " " << std::flush;
		}
		std::cout << vec[i].first << ", " << std::flush;
		if (vec[i].second < 10) {
			std::cout << " " << std::flush;
		}
		std::cout << vec[i].second << "]" << std::flush;
		if (i + 1 < vec.size()) {
			std::cout << ", " << std::flush;
		}
	}
	std::cout << std::endl;
}

void	printRange(const std::string& prefix, std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
	std::cout << prefix << ": " << std::flush;
	for (; begin != end; begin++) {
		std::cout << *begin << ", "<< std::flush;
	}
	std::cout << *end << std::endl;
	// std::cout << std::endl;
}

size_t	jacobsthalNumber(size_t n) {
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

template <typename ITERATOR>
size_t	getDistance(ITERATOR begin, ITERATOR end) {
	size_t	dist = 0;
	for (; begin != end; begin++) {
		dist += 1;
	}
	return (dist);
}

template <typename ITERATOR>
ITERATOR	getBackIterator(ITERATOR end) {
	end--;
	return (end);
}

template <typename ITERATOR>
ITERATOR	getMiddleIterator(ITERATOR left, ITERATOR right) {
	try {
		size_t	n = getDistance(left, right) / 2;

		for (size_t i = 0; i < n; i++) {
			left++;
		}
		return (left);
	} catch (std::exception& e) {
		throw;
	}
}

template <typename CONTAINER>
CONTAINER	mergeInsertionSort(CONTAINER container) {
	if (container.size() < 2) {
		return (container);
	}
	if (container.size() == 2) {
		CntRecvCompare += 1;
		// if (container[0] > container[1]) {
		if (container.front() > container.back()) {
			// std::swap(container[0], container[1]);
			std::swap(container.front(), container.back());
		}
		return (container);
	}
	std::vector<std::pair<int, int> >	pair;
	CONTAINER							large;
	for (typename CONTAINER::iterator it = container.begin(); it != container.end(); it++) {
		typename CONTAINER::iterator nextIt = it;
		nextIt++;
		if (nextIt == container.end()) {
			pair.push_back(std::make_pair(-1, *it));
			break;
		}
		CntPairCompare += 1;
		if (*it < *nextIt) {
			pair.push_back(std::make_pair(*nextIt, *it));
		} else {
			pair.push_back(std::make_pair(*it, *nextIt));
		}
		large.push_back(pair.back().first);
		it = nextIt;
	}
	// printPair("pair ", pair);
	// printInt("large", large);
	// std::cout << std::endl;

	CONTAINER	sorted = mergeInsertionSort(large);

	// std::cout << std::endl;
	// printInt("sorted", sorted);
	// smallの作成
	CONTAINER	small;
	for (typename CONTAINER::iterator it = sorted.begin(); it != sorted.end(); it++) {
		for (std::vector<std::pair<int, int> >::iterator pIt = pair.begin(); pIt != pair.end(); pIt++) {
			if (*it == pIt->first) {
				small.push_back(pIt->second);
				break;
			}
		}
	}
	if (pair[pair.size() - 1].first == -1) {
		small.push_back(pair[pair.size() - 1].second);
	}
	// printInt("small ", small);
	// Insert sortの開始
	// 最初の要素を挿入
	sorted.insert(sorted.begin(), *(small.begin()));
	size_t	n = 1;
	typename CONTAINER::iterator	beginIt = small.begin();
	while (beginIt != small.end()) {
		// Jacobsthal number
		// 挿入要素の範囲を指定(small)
		typename CONTAINER::iterator	endIt = beginIt;
		endIt++;
		if (endIt == small.end()) {
			break;
		}
		// TODO(hnoguchi): あとでチェック
		for (; endIt != getBackIterator(small.end()); endIt++) {
			if (getDistance(beginIt, endIt) == (jacobsthalNumber(n) * 2)) {
				break;
			}
		}
		n += 1;
		// printRange("target", beginIt, endIt);
		// Binary search
		typename CONTAINER::iterator	it = endIt;
		// std::cout << "it: " << *it << std::endl;
		while (it != beginIt) {
			typename CONTAINER::iterator leftIt = sorted.begin();
			typename CONTAINER::iterator rightIt = sorted.end();
			for (std::vector<std::pair<int, int> >::iterator pIt = pair.begin(); pIt != pair.end(); pIt++) {
				if (pIt->second != *it) {
					continue;
				}
				if (pIt->first == -1) {
					break;
				}
				// for (typename CONTAINER::iterator rit = sorted.end() - 1; rit != sorted.begin(); rit--) {
				for (typename CONTAINER::iterator rit = getBackIterator(sorted.end()); rit != sorted.begin(); rit--) {
					rightIt--;
					if (pIt->first == (*rit)) {
						break;
					}
				}
				break;
			}
			// while (leftIt < rightIt) {
			while (getDistance(leftIt, sorted.end()) > getDistance(rightIt, sorted.end())) {
				// typename CONTAINER::iterator	midIt = leftIt + ((rightIt - leftIt) / 2);
				typename CONTAINER::iterator	midIt = getMiddleIterator(leftIt, rightIt);
				CntBinaryInsertCompare += 1;
				if (*it < *midIt) {
					rightIt = midIt;
				} else {
					leftIt = midIt;
					leftIt++;
				}
			}
			sorted.insert(leftIt, *it);
			// printRange("binary", left, right);
			// it -= 1;
			it--;
		}
		beginIt = endIt;
	}
	// printInt("sorted", sorted);
	// std::cout << std::endl;
	return (sorted);
}

template std::vector<int> mergeInsertionSort(std::vector<int> container);
template std::deque<int> mergeInsertionSort(std::deque<int> container);
template std::list<int> mergeInsertionSort(std::list<int> container);
