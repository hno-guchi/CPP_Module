#include <iostream>
#include <utility>
#include <vector>

static void	printInt(const std::string& str, const std::vector<int>& vec) {
	std::cout << str << ": " << std::flush;
	for (size_t i = 0; i < vec.size(); i++) {
		if (vec[i] < 10) {
			std::cout << " " << std::flush;
		}
		std::cout << vec[i] << std::flush;
		if (i + 1 < vec.size()) {
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

std::vector<int>	sort(std::vector<int> vec) {
	std::vector<int>	sorted;
	if (vec.size() == 2) {
		if (vec[0] > vec[1]) {
			sorted.push_back(vec[1]);
			sorted.push_back(vec[0]);
		} else {
			sorted.push_back(vec[0]);
			sorted.push_back(vec[1]);
		}
		return (sorted);
	}
	std::vector<std::pair<int, int> >	pair;
	std::vector<int>					large;
	std::vector<int>					small;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it += 2) {
		if ((it + 1) == vec.end()) {
			pair.push_back(std::make_pair(-1, *it));
			small.push_back(pair.back().second);
			break;
		}
		if (*it > *(it + 1)) {
			pair.push_back(std::make_pair(*it, *(it + 1)));
		} else {
			pair.push_back(std::make_pair(*(it + 1), *it));
		}
		large.push_back(pair.back().first);
		small.push_back(pair.back().second);
	}
	printPair("pair ", pair);
	printInt("large", large);
	printInt("small", small);
	std::cout << std::endl;

	sorted = sort(large);

	std::cout << std::endl;
	printInt("sorted", sorted);
	std::vector<int>	rSmall;
	for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); it++) {
		for (std::vector<std::pair<int, int> >::iterator pIt = pair.begin(); pIt != pair.end(); pIt++) {
			if (*it == pIt->first) {
				rSmall.push_back(pIt->second);
				break;
			}
		}
	}
	if (pair[pair.size() - 1].first == -1) {
		rSmall.push_back(pair[pair.size() - 1].second);
	}
	printInt("rSmall", rSmall);
	sorted.insert(sorted.begin(), *(rSmall.begin()));
	// Jacobsthal number
	for (std::vector<int>::iterator it = rSmall.end() - 1; it != rSmall.begin(); it--) {
		// Binary search
		for (std::vector<int>::iterator sIt = sorted.begin(); sIt != sorted.end(); sIt++) {
			if (*sIt >= *it) {
				sorted.insert(sIt, *it);
				break;
			}
		}
	}
	printInt("sorted", sorted);
	std::cout << std::endl;
	return (sorted);
}

int main() {
	std::vector<int>	vec;
	vec.push_back(3);
	vec.push_back(17);
	vec.push_back(8);
	vec.push_back(14);
	vec.push_back(4);
	vec.push_back(11);
	vec.push_back(15);
	vec.push_back(1);
	vec.push_back(16);
	vec.push_back(5);
	vec.push_back(18);
	vec.push_back(20);
	vec.push_back(12);
	vec.push_back(9);
	vec.push_back(10);
	vec.push_back(2);
	vec.push_back(6);
	vec.push_back(19);
	vec.push_back(7);
	vec.push_back(13);
	vec.push_back(0);

	printInt("vec", vec);
	std::cout << "----------------" << std::endl;
	std::vector<int>	result = sort(vec);
	std::cout << "----------------" << std::endl;
	printInt("result", result);
}
