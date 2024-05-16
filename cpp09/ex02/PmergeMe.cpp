#include <iostream>
#include <utility>
#include <vector>
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

static void	printPair(const std::string& str, const std::vector<std::pair<int, int> >& vec) {
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

int	jacobsthalNumber(int n) {
	if (n == 0) {
		return (0);
	}
	if (n == 1) {
		return (1);
	}

	int	twoPrev = 0;
	int	onePrev = 1;
	int	numN = 0;
	for (int i = 2; i <= n; i++) {
		numN = onePrev + 2 * twoPrev;
		twoPrev = onePrev;
		onePrev = numN;
	}
	return (numN);
}

std::vector<int>	mergeInsertionSort(std::vector<int> vec) {
	if (vec.size() < 2) {
		return (vec);
	}
	if (vec.size() == 2) {
		CntRecvCompare += 1;
		if (vec[0] > vec[1]) {
			std::swap(vec[0], vec[1]);
		}
		return (vec);
	}
	std::vector<std::pair<int, int> >	pair;
	std::vector<int>					large;
	for (std::vector<int>::iterator		it = vec.begin(); it != vec.end(); it += 2) {
		if ((it + 1) == vec.end()) {
			pair.push_back(std::make_pair(-1, *it));
			break;
		}
		CntPairCompare += 1;
		if (*it < *(it + 1)) {
			pair.push_back(std::make_pair(*(it + 1), *it));
		} else {
			pair.push_back(std::make_pair(*it, *(it + 1)));
		}
		large.push_back(pair.back().first);
	}
	// printPair("pair ", pair);
	// printInt("large", large);
	// std::cout << std::endl;

	std::vector<int>	sorted = mergeInsertionSort(large);

	// std::cout << std::endl;
	// printInt("sorted", sorted);
	// smallの作成
	std::vector<int>	small;
	for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); it++) {
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
	int n = 1;
	std::vector<int>::iterator	beginIt = small.begin();
	while (beginIt != small.end()) {
		// Jacobsthal number
		// 挿入要素の範囲を指定(small)
		std::vector<int>::iterator	endIt = beginIt + 1;
		if (endIt == small.end()) {
			break;
		}
		for (; endIt != (small.end() - 1); endIt++) {
			if ((endIt - beginIt) == (jacobsthalNumber(n) * 2)) {
				break;
			}
		}
		n += 1;
		// printRange("target", beginIt, endIt);
		// Binary search
		std::vector<int>::iterator	it = endIt;
		// std::cout << "it: " << *it << std::endl;
		while (it != beginIt) {
			std::vector<int>::iterator leftIt = sorted.begin();
			std::vector<int>::iterator rightIt = sorted.end();
			for (std::vector<std::pair<int, int> >::iterator pIt = pair.begin(); pIt != pair.end(); pIt++) {
				if (pIt->second != *it) {
					continue;
				}
				if (pIt->first == -1) {
					break;
				}
				for (std::vector<int>::iterator rit = sorted.end() - 1; rit != sorted.begin(); rit--) {
					// right += 1;
					rightIt -= 1;
					if (pIt->first == (*rit)) {
						break;
					}
				}
				break;
			}
			while (leftIt < rightIt) {
				std::vector<int>::iterator	midIt = leftIt + ((rightIt - leftIt) / 2);
				CntBinaryInsertCompare += 1;
				if (*it < *midIt) {
					rightIt = midIt;
				} else {
					leftIt = midIt + 1;
				}
			}
			sorted.insert(leftIt, *it);
			// printRange("binary", left, right);
			it -= 1;
		}
		beginIt = endIt;
	}
	// printInt("sorted", sorted);
	// std::cout << std::endl;
	return (sorted);
}
