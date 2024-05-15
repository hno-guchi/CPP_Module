#include <iostream>
#include <utility>
#include <vector>

static void	printInt(const std::string& str, const std::vector<int>& vec) {
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

std::vector<int>	sort(std::vector<int> vec) {
	if (vec.size() == 0 || vec.size() == 1) {
		return (vec);
	}
	if (vec.size() == 2) {
		if (vec[0] > vec[1]) {
			std::swap(vec[0], vec[1]);
		}
		return (vec);
	}
	std::vector<std::pair<int, int> >	pair;
	std::vector<int>					large;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it += 2) {
		if ((it + 1) == vec.end()) {
			pair.push_back(std::make_pair(-1, *it));
			break;
		}
		if (*it > *(it + 1)) {
			pair.push_back(std::make_pair(*it, *(it + 1)));
		} else {
			pair.push_back(std::make_pair(*(it + 1), *it));
		}
		large.push_back(pair.back().first);
	}
	printPair("pair ", pair);
	printInt("large", large);
	std::cout << std::endl;

	std::vector<int>	sorted = sort(large);

	std::cout << std::endl;
	printInt("sorted", sorted);
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
	printInt("small", small);
	sorted.insert(sorted.begin(), *(small.begin()));
	int n = 1;
	std::vector<int>::iterator	beginIt = small.begin() + 1;
	while (beginIt != small.end()) {
		// Jacobsthal number
		std::vector<int>::iterator	endIt = beginIt;
		for (; endIt != (small.end() - 1); endIt++) {
			if ((endIt - beginIt) == ((jacobsthalNumber(n) * 2) - 1)) {
				n += 1;
				break;
			}
		}
		std::vector<int>::iterator it = endIt;
		while (1) {
			// Binary search
			std::vector<int>::iterator	left = sorted.begin();
			std::vector<int>::iterator	right = sorted.end();
			if (sorted.size() != 1 && sorted.size() != 2) {
				std::vector<int>::iterator	middle = left + ((right - left) / 2);
				if (*it < *middle) {
					right = middle;
				} else {
					left = middle;
				}
			}
			for (; left != right; left++) {
				if (*it < *left) {
					sorted.insert(left, *it);
					break;
				}
			}
			if (it == beginIt) {
				break;
			}
			it -= 1;
		}
		beginIt = endIt + 1;
	}
	// printInt("sorted", sorted);
	// std::cout << std::endl;
	return (sorted);
}

int main() {
	std::vector<int>	before;
	before.push_back(17);
	before.push_back(3);
	before.push_back(8);
	before.push_back(14);
	before.push_back(4);
	before.push_back(11);
	before.push_back(15);
	before.push_back(1);
	before.push_back(16);
	before.push_back(5);
	before.push_back(18);
	before.push_back(20);
	before.push_back(12);
	before.push_back(9);
	before.push_back(10);
	before.push_back(2);
	before.push_back(6);
	before.push_back(19);
	before.push_back(7);
	before.push_back(13);
	before.push_back(0);

	std::vector<int>	after = sort(before);
	printInt("Before", before);
	printInt("After ", after);
}
