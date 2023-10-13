#include <string>
#include <iostream>

int	main()
{
	std::string	str;
	double		d;
   
	str = "inf";
	std::cout << "std::stod(" << str << "); => " << std::flush;
	try {
		d = std::stod(str);
		std::cout << d << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	str = "infinity";
	std::cout << "std::stod(" << str << "); => " << std::flush;
	try {
		d = std::stod(str);
		std::cout << d << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	str = "-inf";
	std::cout << "std::stod(" << str << "); => " << std::flush;
	try {
		d = std::stod(str);
		std::cout << d << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	str = "-infinity";
	std::cout << "std::stod(" << str << "); => " << std::flush;
	try {
		d = std::stod(str);
		std::cout << d << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	str = "NaN";
	std::cout << "std::stod(" << str << "); => " << std::flush;
	try {
		d = std::stod(str);
		std::cout << d << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	str = "nan";
	std::cout << "std::stod(" << str << "); => " << std::flush;
	try {
		d = std::stod(str);
		std::cout << d << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	str = "-nan";
	std::cout << "std::stod(" << str << "); => " << std::flush;
	try {
		d = std::stod(str);
		std::cout << d << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	str = "1e9999";
	std::cout << "std::stod(" << str << "); => " << std::flush;
	try {
		d = std::stod(str);
		std::cout << d << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	str = "-1e9999";
	std::cout << "std::stod(" << str << "); => " << std::flush;
	try {
		d = std::stod(str);
		std::cout << d << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
