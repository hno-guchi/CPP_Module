#include <limits>
#include <iostream>

int	main()
{
	int	result = std::numeric_limits<int>::max() * 10;

	std::cout << result << std::endl;
}
