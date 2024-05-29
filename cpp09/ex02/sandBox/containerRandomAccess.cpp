#include <iostream>
#include <vector>
#include <deque>
#include <list>

# define END             "\033[0m"
# define GREEN           "\033[32m"

int	main() {
	std::srand(std::time(NULL));
	std::clock_t	start, finish;
	double			time;

	int nums[1000000];
	for (int i = 0; i < 1000000; i++) { nums[i] = std::rand() % 1000000; }

	std::vector<int>	vec;
	std::deque<int>		deq;
	std::list<int>		lst;

	// push_back test
	start = std::clock();
	for (int i = 0; i < 1000000; i++) { vec.push_back(nums[i]); }
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::vector<int>   vec; push_back(); * 1,000,000 : " << GREEN << time << END << " ms | " << std::flush;
	std::cout << std::endl;

	start = std::clock();
	for (int i = 0; i < 1000000; i++) { deq.push_back(nums[i]); }
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::deque<int>    deq; push_back(); * 1,000,000 : " << GREEN << time << END << " ms | " << std::flush;
	std::cout << std::endl;

	start = std::clock();
	for (int i = 0; i < 1000000; i++) { lst.push_back(nums[i]); }
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::list<int>     lst; push_back(); * 1,000,000 : " << GREEN << time << END << " ms | " << std::flush;
	std::cout << std::endl;

	// random access test
	start = std::clock();
	for (int i = 0; i < 1000000; i++) { vec[nums[i]] = nums[i]; }
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::vector<int>   vec; vec[nums[i]] = nums[i]; * 1,000,000 : " << GREEN << time << END << " ms | " << std::flush;
	std::cout << std::endl;

	start = std::clock();
	for (int i = 0; i < 1000000; i++) { deq[nums[i]] = nums[i]; }
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::deque<int>    deq; deq[nums[i]] = nums[i]; * 1,000,000 : " << GREEN << time << END << " ms | " << std::flush;
	std::cout << std::endl;

	start = std::clock();
	for (int i = 0; i < 1000; i++) {
		std::list<int>::iterator it = lst.begin();
		for (int j = 0; j < nums[i]; j++) {
			it++;
		}
		*it = nums[i];
	}
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::list<int>     lst; lst[nums[i]] = nums[i]; * 1,000,000 : " << GREEN << time << END << " ms | " << std::flush;
	std::cout << std::endl;

	// random insert test
	// push_front test
}
