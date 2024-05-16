// level: 1
// 隣要素同士を比較して、大きい値をlarge、小さい値をsmallに入れる処理を実装する。
// 要素数が、2になるまで再帰的に繰り返す。
// 再帰的な処理が終了したら、配列の要素を表示する。

// level: 2
// std::pair<int, int>を要素に持つベクタを実装する。
// 再帰的に処理を繰り返す中で、ペアとなった要素のソートが連動するように実装する。
#include <iostream>
#include <vector>

static void	print(std::string str, std::vector<int> vec) {
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

std::vector<int> sort(std::vector<int> vec) {
	if (vec.size() == 2) {
		if (vec[0] > vec[1]) {
			int tmp = vec[0];
			vec[0] = vec[1];
			vec[1] = tmp;
		}
		return (vec);
	}
	std::vector<int>	large;
	std::vector<int>	small;
	for (size_t i = 0; i < vec.size(); i += 2) {
		if ((i + 1) < vec.size()) {
			if (vec[i] > vec[i + 1]) {
				large.push_back(vec[i]);
				small.push_back(vec[i + 1]);
			} else {
				large.push_back(vec[i + 1]);
				small.push_back(vec[i]);
			}
		} else {
			small.push_back(vec[i]);
		}
	}
	sort(large);
	print("large", large);
	print("small", small);
	return (large);
}

int	main() {
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
	print("vec", vec);
	sort(vec);
	// std::vector<int> result = sort(vec);
	// print("result", result);
	return (0);
}
