#include <vector>
#include <iostream>

# define END             "\033[0m"
# define GREEN           "\033[32m"

int main() {
	std::srand(std::time(NULL));
	std::clock_t	start, finish;
	double			time;

	std::vector<int>	v1;
	std::vector<int*>	v2;
	std::vector<int>*	v3 = new std::vector<int>();
	std::vector<int*>*	v4 = new std::vector<int*>();

	int nums[1000000];
	for (int i = 0; i < 1000000; i++) { nums[i] = std::rand() % 1000000; }

	start = std::clock();
	for (int i = 0; i < 1000000; i++) { v1.push_back(nums[i]); }
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::vector<int>   v1; push_back(); * 1,000,000 : " << GREEN << time << END << " ms | " << std::flush;
	start = std::clock();
	std::sort(v1.begin(), v1.end());
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::sort(); : " << GREEN << time << END << " ms" << std::endl;

	start = std::clock();
	for (int i = 0; i < 1000000; i++) { v2.push_back(new int(nums[i])); }
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::vector<int*>  v2; push_back(); * 1,000,000 : " << GREEN << time << END << " ms | " << std::flush;
	start = std::clock();
	std::sort(v2.begin(), v2.end());
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::sort(); : " << GREEN << time << END << " ms" << std::endl;


	start = std::clock();
	for (int i = 0; i < 1000000; i++) { v3->push_back(nums[i]); }
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::vector<int>  *v3; push_back(); * 1,000,000 : " << GREEN << time << END << " ms | " << std::flush;
	start = std::clock();
	std::sort(v3->begin(), v3->end());
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::sort(); : " << GREEN << time << END << " ms" << std::endl;



	start = std::clock();
	for (int i = 0; i < 1000000; i++) { v4->push_back(new int(nums[i])); }
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::vector<int*> *v4; push_back(); * 1,000,000 : " << GREEN << time << END << " ms | " << std::flush;
	start = std::clock();
	std::sort(v4->begin(), v4->end());
	finish = std::clock();
	time = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "std::sort(); : " << GREEN << time << END << " ms" << std::endl;
}
