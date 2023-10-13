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

	str = "-2147483648";
	std::cout << "std::stod(" << str << "); => " << std::flush;
	try {
		d = std::stod(str);
		std::cout << d << std::endl;
		std::cout << "INT : " << static_cast<int>(d) << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	str = "-2147483649";
	std::cout << "std::stod(" << str << "); => " << std::flush;
	try {
		d = std::stod(str);
		std::cout << d << std::endl;
		std::cout << "INT : " << static_cast<int>(d) << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	str = "2147483647";
	std::cout << "std::stod(" << str << "); => " << std::flush;
	try {
		d = std::stod(str);
		std::cout << d << std::endl;
		std::cout << "INT : " << static_cast<int>(d) << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	str = "2147483648";
	std::cout << "std::stod(" << str << "); => " << std::flush;
	try {
		d = std::stod(str);
		std::cout << d << std::endl;
		std::cout << "INT : " << static_cast<int>(d) << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	str = "2147483647000000000000";
	std::cout << "std::stod(" << str << "); => " << std::flush;
	try {
		d = std::stod(str);
		std::cout << d << std::endl;
		std::cout << "INT : " << static_cast<int>(d) << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
