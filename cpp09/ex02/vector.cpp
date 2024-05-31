#include <iostream>
#include <iomanip>
#include <sstream>
#include <utility>
#include <vector>
#include <list>
#include "./PmergeMe.hpp"
#include "./color.hpp"

std::vector<int>::const_iterator	PmergeMe::getMiddleIterator(std::vector<int>::const_iterator left, std::vector<int>::const_iterator right) {
	try {
		std::advance(left, std::distance(left, right) / 2);
		return (left);
	} catch (std::exception& e) {
		throw;
	}
}

std::vector<std::pair<int, int> >	PmergeMe::createPairs(std::vector<int> container) {
	try {
		std::vector<std::pair<int, int> >	pairs;
		for (std::vector<int>::iterator it = container.begin(); it != container.end(); it++) {
			std::vector<int>::iterator nextIt = it;
			nextIt++;
			if (nextIt == container.end()) {
				pairs.push_back(std::make_pair(-1, *it));
				break;
			}
			this->vecCompareCount_ += 1;
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

std::vector<int>	PmergeMe::getLarges(const std::vector<std::pair<int, int> >& pairs) {
	try {
		std::vector<int>	larges;
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

std::vector<int>	PmergeMe::getSmalls(const std::vector<std::pair<int, int> >& pairs, const std::vector<int>& sorted) {
	try {
		std::vector<int>	smalls;
		for (std::vector<int>::const_iterator sortedIt = sorted.begin(); sortedIt != sorted.end(); sortedIt++) {
			for (std::vector<std::pair<int, int> >::const_iterator pairsIt = pairs.begin(); pairsIt != pairs.end(); pairsIt++) {
				if (*sortedIt == pairsIt->first) {
					smalls.push_back(pairsIt->second);
					break;
				}
			}
		}
		if (pairs.back().first == -1) {
			smalls.push_back(pairs.back().second);
		}
		return (smalls);
	} catch (std::exception& e) {
		throw;
	}
}

std::vector<int>::const_iterator	PmergeMe::selectInsertionRange(size_t n, const std::vector<int>& smalls, std::vector<int>::const_iterator begin) {
	try {
		std::vector<int>::const_iterator	end = begin;
		end++;
		if (end == smalls.end()) {
			return (end);
		}
		std::vector<int>::const_iterator	lastIt = smalls.end();
		for (lastIt--; end != lastIt; end++) {
			if (static_cast<size_t>(std::distance(begin, end)) == (this->getJacobsthalNumber(n) * 2)) {
				break;
			}
		}
		return (end);
	} catch (std::exception& e) {
		throw;
	}
}

std::vector<int>::const_iterator	PmergeMe::getRightIterator(const std::vector<std::pair<int, int> >& pairs, const std::vector<int>& sorted, int target) {
	try {
		std::vector<std::pair<int, int> >::const_iterator	pairsIt = pairs.begin();
		for (; pairsIt != pairs.end(); pairsIt++) {
			if (pairsIt->second == target) {
				break;
			}
		}
		if (pairsIt == pairs.end()) {
			return (sorted.end());
		}
		if (pairsIt->first == -1) {
			return (sorted.end());
		}
		std::vector<int>::const_iterator	sortedIt = sorted.end();
		std::vector<int>::const_iterator	right = sorted.end();
		for (sortedIt--; sortedIt != sorted.begin(); sortedIt--) {
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

std::vector<int>::const_iterator	PmergeMe::getSortPosition(const std::vector<std::pair<int, int> >& pairs, const std::vector<int>& sorted, int target) {
	try {
		std::vector<int>::const_iterator	left = sorted.begin();
		std::vector<int>::const_iterator	right = this->getRightIterator(pairs, sorted, target);
		if (std::distance(left, right) < 3) {
			while (left != right) {
				this->vecCompareCount_ += 1;
				if (target < *left) {
					return (left);
				}
				left++;
			}
			return (left);
		} else {
			while (std::distance(left, sorted.end()) > std::distance(right, sorted.end())) {
				std::vector<int>::const_iterator	middle = this->getMiddleIterator(left, right);
				this->vecCompareCount_ += 1;
				if (target < *middle) {
					right = middle;
				} else {
					left = middle;
					left++;
				}
			}
			// this->printRange("binary", left, right);
		}
		return (left);
	} catch (std::exception& e) {
		throw;
	}
}

std::vector<int>	PmergeMe::mergeInsertionSort(std::vector<int> container) {
	try {
		if (container.size() < 2) {
			return (container);
		}
		if (container.size() == 2) {
			this->vecCompareCount_ += 1;
			if (container.front() > container.back()) {
				std::swap(container.front(), container.back());
			}
			return (container);
		}
		std::vector<std::pair<int, int> >	pairs = this->createPairs(container);
		std::vector<int>					larges = this->getLarges(pairs);
		// printPairs("pairs", pairs); printContainer("larges", larges); std::cout << std::endl;

		std::vector<int>					sorted = this->mergeInsertionSort(larges);
		// std::cout << std::endl; printContainer("sorted", sorted);

		std::vector<int>					smalls = this->getSmalls(pairs, sorted);
		// printContainer("smalls", smalls);

		sorted.insert(sorted.begin(), *(smalls.begin()));
		size_t	n = 1;
		std::vector<int>::const_iterator	end;
		for (std::vector<int>::const_iterator	begin = smalls.begin(); begin != smalls.end(); begin = end) {
			end = this->selectInsertionRange(n, smalls, begin);
			n++;
			if (end == smalls.end()) {
				break;
			}

			std::vector<int>::const_iterator	target = end;
			// std::cout << "target: " << *target << std::endl;
			while (target != begin) {
				// Binary search
				std::vector<int>::const_iterator	sortPos = this->getSortPosition(pairs, sorted, *target);
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
