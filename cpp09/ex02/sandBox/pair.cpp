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
	std::vector<int>	nextSort;
	if (vec.size() == 2) {
		if (vec[0] > vec[1]) {
			nextSort.push_back(vec[1]);
			nextSort.push_back(vec[0]);
		} else {
			nextSort.push_back(vec[0]);
			nextSort.push_back(vec[1]);
		}
		return (nextSort);
	}
	std::vector<std::pair<int, int> >	pair;
	for (size_t i = 0; i < vec.size(); i += 2) {
		if ((i + 1) < vec.size()) {
			if (vec[i] > vec[i + 1]) {
				pair.push_back(std::make_pair(vec[i], vec[i + 1]));
			} else {
				pair.push_back(std::make_pair(vec[i + 1], vec[i]));
			}
		} else {
			pair.push_back(std::make_pair(-1, vec[i]));
		}
	}
	for (size_t i = 0; i < pair.size(); i++) {
		if (pair[i].first == -1) {
			break;
		}
		nextSort.push_back(pair[i].first);
	}
	printPair("pair", pair);
	printInt("nextSort", nextSort);
	std::vector<int>	ret = sort(nextSort);
	printInt("ret", ret);
	std::vector<int>	sorted;
	for (size_t i = 0; i < ret.size(); i++) {
		sorted.push_back(ret[i]);
		int	target = -1;
		for (size_t j = 0; j < pair.size(); j++) {
			if (ret[i] == pair[j].first) {
				target = pair[j].second;
				break;
			}
		}
		for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); it++) {
			if (target <= *it) {
				sorted.insert(it, target);
				break;
			}
		}
	}
	if (pair[pair.size() - 1].first == -1) {
		for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); it++) {
				if (pair[pair.size() - 1].second <= *it) {
					sorted.insert(it, pair[pair.size() - 1].second);
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
