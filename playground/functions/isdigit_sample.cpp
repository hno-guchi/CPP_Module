#include <iostream>
#include <locale>

int	main(void)
{
	std::string	str = "1";
	std::locale	l = std::locale::classic();

	if (std::isdigit(str[0], l) == true) {
		std::cout << "True" << std::endl;
	}
	else {
		std::cout << "False" << std::endl;
	}
}
