// level: 1
// 隣要素同士を比較して、大きい値をlarge、小さい値をsmallに入れる処理を実装する。
// 要素数が、2になるまで再帰的に繰り返す。
// 再帰的な処理が終了したら、配列の要素を表示する。

#include <iostream>
#include <vector>

static void	print(std::string str, std::vector<int> list) {
	std::cout << str << ": " << std::flush;
	for (size_t i = 0; i < list.size(); i++) {
		if (list[i] < 10) {
			std::cout << " " << std::flush;
		}
		std::cout << list[i] << std::flush;
		if (i + 1 < list.size()) {
			std::cout << ", " << std::flush;
		}
	}
	std::cout << std::endl;
}

std::vector<int> sort(std::vector<int> list) {
	if (list.size() == 2) {
		if (list[0] > list[1]) {
			int tmp = list[0];
			list[0] = list[1];
			list[1] = tmp;
		}
		return (list);
	}
	std::vector<int>	large;
	std::vector<int>	small;
	for (size_t i = 0; i < list.size(); i += 2) {
		if ((i + 1) < list.size()) {
			if (list[i] > list[i + 1]) {
				large.push_back(list[i]);
				small.push_back(list[i + 1]);
			} else {
				large.push_back(list[i + 1]);
				small.push_back(list[i]);
			}
		} else {
			small.push_back(list[i]);
		}
	}
	sort(large);
	print("large", large);
	print("small", small);
	return (large);
}

int	main() {
	std::vector<int>	list;
	list.push_back(3);
	list.push_back(17);
	list.push_back(8);
	list.push_back(14);
	list.push_back(4);
	list.push_back(11);
	list.push_back(15);
	list.push_back(1);
	list.push_back(16);
	list.push_back(5);
	list.push_back(18);
	list.push_back(20);
	list.push_back(12);
	list.push_back(9);
	list.push_back(10);
	list.push_back(2);
	list.push_back(6);
	list.push_back(19);
	list.push_back(7);
	list.push_back(13);
	list.push_back(0);
	print("list", list);
	sort(list);
	// std::vector<int> result = sort(list);
	// print("result", result);
	return (0);
}
