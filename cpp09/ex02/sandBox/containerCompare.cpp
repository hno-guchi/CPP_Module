#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
#include <deque>
#include <list>

# define END             "\033[0m"
# define GREEN           "\033[32m"
# define MAGENTA         "\033[35m"

int	main() {
	std::srand(std::time(NULL));
	std::clock_t	start, finish;
	double			time;

	int nums[1000000];
	for (int i = 0; i < 1000000; i++) { nums[i] = std::rand() % 1000000; }

{
	std::vector<int>	vec;
	std::deque<int>		deq;
	std::list<int>		lst;

	// push_back test
	std::cout << " [" << MAGENTA << "PUSH BACK TEST" << END << "] _______________________________________________________" << std::endl;
	start = std::clock();
	for (int i = 0; i < 1000000; i++) { vec.push_back(nums[i]); }
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::vector<int>   vec;            push_back(); * 1,000,000 : " << GREEN << time << END << " ms | " << std::endl;

	start = std::clock();
	for (int i = 0; i < 1000000; i++) { deq.push_back(nums[i]); }
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::deque<int>    deq;            push_back(); * 1,000,000 : " << GREEN << time << END << " ms | " << std::endl;

	start = std::clock();
	for (int i = 0; i < 1000000; i++) { lst.push_back(nums[i]); }
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::list<int>     lst;            push_back(); * 1,000,000 : " << GREEN << time << END << " ms | " << std::endl;
	std::cout << std::endl;

{
		// random access test
		std::cout << " [" << MAGENTA << "RANDOM ACCESS TEST" << END << "] ____________________________________________________" << std::endl;
		start = std::clock();
		for (int i = 0; i < 1000000; i++) { vec[nums[i]] = nums[i]; }
		finish = std::clock();
		time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
		std::cout << "std::vector<int>   vec; vec[nums[i]] = nums[i]; * 1,000,000 : " << GREEN << time << END << "   ms | " << std::endl;

		start = std::clock();
		for (int i = 0; i < 1000000; i++) { deq[nums[i]] = nums[i]; }
		finish = std::clock();
		time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
		std::cout << "std::deque<int>    deq; deq[nums[i]] = nums[i]; * 1,000,000 : " << GREEN << time << END << "   ms | " << std::endl;

		std::list<int>::iterator	beginIt = lst.begin();
		std::list<int>::iterator	endIt = lst.end();
		int							lstSize = lst.size();
		int							middleIndex = lstSize / 2;
		start = std::clock();
		for (int i = 0; i < 1000; i++) {
			if (nums[i] < middleIndex) {
				std::advance(beginIt, nums[i]);
				*beginIt = nums[i];
				beginIt = lst.begin();
			} else {
				std::advance(endIt, nums[i] - lstSize);
				*endIt = nums[i];
				endIt = lst.end();
			}
		}
		finish = std::clock();
		time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
		std::cout << "std::list<int>     lst; lst[nums[i]] = nums[i]; *     1,000 : " << GREEN << time << END << " ms | " << std::endl;
		std::cout << std::endl;
}

{
		// random access insert test
		std::cout << " [" << MAGENTA << "RANDOM ACCESS INSERT TEST" << END << "] _____________________________________________" << std::endl;
		std::vector<int>::iterator	vecBeginIt, vecEndIt;
		int							vecSize = vec.size();
		int							vecMiddleIndex = vecSize / 2;
		start = std::clock();
		for (int i = 0; i < 1000; i++) {
			if (nums[i] < vecMiddleIndex) {
				vecBeginIt = vec.begin();
				std::advance(vecBeginIt, nums[i]);
				vec.insert(vecBeginIt, nums[i]);
			} else {
				vecEndIt = vec.end();
				std::advance(vecEndIt, nums[i] - vecSize);
				vec.insert(vecEndIt, nums[i]);
			}
			vecSize = vec.size();
			vecMiddleIndex = vecSize / 2;
		}
		finish = std::clock();
		time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
		std::cout << "std::vector<int>   vec;               insert(); *     1,000 : " << GREEN << time << END << "  ms | " << std::endl;

		std::deque<int>::iterator	deqBeginIt, deqEndIt;
		int							deqSize = deq.size();
		int							deqMiddleIndex = deqSize / 2;
		start = std::clock();
		for (int i = 0; i < 1000; i++) {
			if (nums[i] < deqMiddleIndex) {
				deqBeginIt = deq.begin();
				std::advance(deqBeginIt, nums[i]);
				deq.insert(deqBeginIt, nums[i]);
			} else {
				deqEndIt = deq.end();
				std::advance(deqEndIt, nums[i] - deqSize);
				deq.insert(deqEndIt, nums[i]);
			}
			deqSize = deq.size();
			deqMiddleIndex = deqSize / 2;
		}
		finish = std::clock();
		time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
		std::cout << "std::deque<int>    deq;               insert(); *     1,000 : " << GREEN << time << END << "  ms | " << std::endl;

		std::list<int>::iterator	lstBeginIt, lstEndIt;
		int							lstSize = lst.size();
		int							lstMiddleIndex = lstSize / 2;
		start = std::clock();
		for (int i = 0; i < 1000; i++) {
			if (nums[i] < lstMiddleIndex) {
				lstBeginIt = lst.begin();
				std::advance(lstBeginIt, nums[i]);
				lst.insert(lstBeginIt, nums[i]);
			} else {
				lstEndIt = lst.end();
				std::advance(lstEndIt, nums[i] - lstSize);
				lst.insert(lstEndIt, nums[i]);
			}
			lstSize = lst.size();
			lstMiddleIndex = lstSize / 2;
		}
		finish = std::clock();
		time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
		std::cout << "std::list<int>     lst;               insert(); *     1,000 : " << GREEN << time << END << " ms | " << std::endl;
		std::cout << std::endl;
}
}
{
	// push_front test
	std::vector<int>	vec;
	std::deque<int>		deq;
	std::list<int>		lst;

	std::cout << " [" << MAGENTA << "PUSH FRONT TEST" << END << "] _______________________________________________________" << std::endl;
	start = std::clock();
	for (int i = 0; i < 100000; i++) { vec.insert(vec.begin(), nums[i]); }
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::vector<int>   vec;   insert(begin(), num); *   100,000 : " << std::fixed << std::setprecision(3) << std::setw(10) << std::setfill(' ') << std::left << GREEN << time << END << " ms | " << std::endl;

	start = std::clock();
	for (int i = 0; i < 100000; i++) { deq.push_front(nums[i]); }
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::deque<int>    deq;           push_front(); *   100,000 : " << std::fixed << std::setprecision(3) << std::setw(10) << std::setfill(' ') << std::left << GREEN << time << END << " ms | " << std::endl;

	start = std::clock();
	for (int i = 0; i < 100000; i++) { lst.push_front(nums[i]); }
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::list<int>     lst;           push_front(); *   100,000 : " << std::flush;
	std::cout << std::fixed << std::setprecision(3) << std::setw(10) << std::setfill(' ') << std::right << GREEN << time << END << " ms | " << std::endl;
	std::cout << std::endl;
}
}
