#include <iostream>
#include <iomanip>

int	main()
{
	long	num = INT_MIN;
	num -= INT_MAX;
	std::cout << "sizeof(int)         : [" << sizeof(int) << "] | " << std::flush;
	std::cout << "MAX [" << std::right << std::setw(20) << INT_MAX << "] | " << std::flush;
	std::cout << "MIN [" << std::right << std::setw(20) << INT_MIN << "] | " << std::flush;
	std::cout << "INT_MAX - INT_MIN = [" << std::right << std::setw(20) << num << "]" << std::endl;

	std::cout << "sizeof(std::size_t) : [" << sizeof(std::size_t) << "] | MAX [" << std::flush;
	std::cout << std::right << std::setw(20) << SIZE_MAX << "] | MIN [" << std::flush;
	std::cout << std::right << std::setw(20) << "0" << "]" << std::endl;

	std::cout << "sizeof(long)        : [" << sizeof(long) << "] | MAX [" << std::flush;
	std::cout << std::right << std::setw(20) << LONG_MAX << "] | MIN [" << std::flush;
	std::cout << std::right << std::setw(20) << LONG_MIN << "]" << std::endl;

	std::cout << "sizeof(long long)   : [" << sizeof(long long) << "] | MAX [" << std::flush;
	std::cout << std::right << std::setw(20) << LLONG_MAX << "] | MIN [" << std::flush;
	std::cout << std::right << std::setw(20) << LLONG_MIN << "]" << std::endl;
}
