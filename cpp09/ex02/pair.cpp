#include <iostream>
#include <utility>
#include <vector>

static void	print(std::string str, std::vector<std::pair<int, int> >* list) {
	std::cout << str << ": " << std::flush;
	for (size_t i = 0; i < list->size(); i++) {
		std::cout << "[" << std::flush;
		if ((*list)[i].first < 10) {
			std::cout << " " << std::flush;
		}
		std::cout << (*list)[i].first << ", " << std::flush;
		if ((*list)[i].second < 10) {
			std::cout << " " << std::flush;
		}
		std::cout << (*list)[i].second << "]" << std::flush;
		if (i + 1 < list->size()) {
			std::cout << ", " << std::flush;
		}
	}
	std::cout << std::endl;
}

// std::vector<std::pair<int, int>> sort(std::vector<std::pair<int, int>> list) {
// 	if (list.size() == 2) {
// 		if (list[0] > list[1]) {
// 			int tmp = list[0];
// 			list[0] = list[1];
// 			list[1] = tmp;
// 		}
// 		return (list);
// 	}
// 	std::vector<int>	large;
// 	std::vector<int>	small;
// 	for (size_t i = 0; i < list.size(); i += 2) {
// 		if ((i + 1) < list.size()) {
// 			if (list[i] > list[i + 1]) {
// 				large.push_back(list[i]);
// 				small.push_back(list[i + 1]);
// 			} else {
// 				large.push_back(list[i + 1]);
// 				small.push_back(list[i]);
// 			}
// 		} else {
// 			small.push_back(list[i]);
// 		}
// 	}
// 	sort(large);
// 	print("large", large);
// 	print("small", small);
// 	return (large);
// }

int main() {
	std::vector<std::pair<int, int> >	vec;

	vec.push_back(std::make_pair(3, 17));
	vec.push_back(std::make_pair(8, 14));
	vec.push_back(std::make_pair(4, 11));
	vec.push_back(std::make_pair(15, 1));
	vec.push_back(std::make_pair(16, 5));
	vec.push_back(std::make_pair(18, 20));
	vec.push_back(std::make_pair(12, 9));
	vec.push_back(std::make_pair(10, 2));
	vec.push_back(std::make_pair(6, 19));
	vec.push_back( std::make_pair(7, 13));
	print("vec", &vec);
}
