#include <iostream>

int	divide(int a, int b)
{
	if (b == 0) {
		throw "Occurred Zero division.";
	}
	return (a / b);
}

int	main()
{
	try {
		int	result = divide(10, 0);
		std::cout << result << std::endl;
	}
	catch (const char *s) {
		std::cerr << s << std::endl;
	}
	std::cout << "Finish." << std::endl;
}
