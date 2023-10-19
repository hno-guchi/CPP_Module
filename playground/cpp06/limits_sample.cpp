#include <iostream>
#include <limits>

int	main()
{
	std::cout << "  <char>::min(); [" << std::numeric_limits<char>::min() << "]" << std::endl;
	std::cout << "  <char>::max(); [" << -(std::numeric_limits<char>::max()) << "]" << std::endl;
	std::cout << std::endl;

	std::cout << "   <int>::min(); [" << std::numeric_limits<int>::min() << "]" << std::endl;
	std::cout << "   <int>::max(); [" << -(std::numeric_limits<int>::max()) << "]" << std::endl;
	std::cout << std::endl;

	std::cout << " <float>::min(); [" << std::numeric_limits<float>::min() << "]" << std::endl;
	std::cout << " <float>::max(); [" << -(std::numeric_limits<float>::max()) << "]" << std::endl;
	std::cout << std::endl;

	std::cout << "<double>::min(); [" << std::numeric_limits<double>::min() << "]" << std::endl;
	std::cout << "<double>::max(); [" << -(std::numeric_limits<double>::max()) << "]" << std::endl;
	std::cout << std::endl;
}
