#include <vector>
#include <iostream>

int	main()
{
	std::vector<int>	vec;

	vec.push_back(0); vec.push_back(1); vec.push_back(2);
	std::cout << "vec : capacity [" << vec.capacity() << "] | size [" << vec.size() << "]" << std::endl;

	vec.resize(5);
	std::cout << "vec : capacity [" << vec.capacity() << "] | size [" << vec.size() << "]" << std::endl;
}
