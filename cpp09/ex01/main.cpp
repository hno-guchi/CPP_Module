#include "./RPN.hpp"
#include "./color.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << RED << "Please give a single argument." << END << std::endl;
		return (1);
	}
	try {
		RPN::execute(static_cast<std::string>(argv[1]));
	} catch (std::exception& e) {
		std::cout << RED << e.what() << END << std::endl;
	}
#ifdef LEAKS
	system("leaks -q RPN");
#endif
	return (0);
}


// int	main() {
// // static long	multiplication(long a, long b);
// {
// 	std::cout << MAGENTA << "[TEST] multiple ________________________________________" << END << std::endl;
// 	long	a, b;
// 	try { a = 0; b = 0; std::cout << a << " * " << b << " = " << RPN::multiplication(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = 0; b = 42; std::cout << a << " * " << b << " = " << RPN::multiplication(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = 42; b = 0; std::cout << a << " * " << b << " = " << RPN::multiplication(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = std::numeric_limits<int>::min(); b = 1; std::cout << a << " * " << b << " = " << RPN::multiplication(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = std::numeric_limits<int>::max(); b = 1; std::cout << a << " * " << b << " = " << RPN::multiplication(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = 1; b = std::numeric_limits<int>::min(); std::cout << a << " * " << b << " = " << RPN::multiplication(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = 1; b = std::numeric_limits<int>::max(); std::cout << a << " * " << b << " = " << RPN::multiplication(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = std::numeric_limits<int>::min(); b = -1; std::cout << a << " * " << b << " = " << RPN::multiplication(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = -1; b = std::numeric_limits<int>::min(); std::cout << a << " * " << b << " = " << RPN::multiplication(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = std::numeric_limits<int>::min(); b = 2; std::cout << a << " * " << b << " = " << RPN::multiplication(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = std::numeric_limits<int>::max(); b = 2; std::cout << a << " * " << b << " = " << RPN::multiplication(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = 2; b = std::numeric_limits<int>::min(); std::cout << a << " * " << b << " = " << RPN::multiplication(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = 2; b = std::numeric_limits<int>::max(); std::cout << a << " * " << b << " = " << RPN::multiplication(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = std::numeric_limits<int>::min(); b = std::numeric_limits<int>::max(); std::cout << a << " * " << b << " = " << RPN::multiplication(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = std::numeric_limits<int>::max(); b = std::numeric_limits<int>::min(); std::cout << a << " * " << b << " = " << RPN::multiplication(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = std::numeric_limits<int>::max() / 42; b = 43; std::cout << a << " * " << b << " = " << RPN::multiplication(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = std::numeric_limits<int>::max() / 42; b = -43; std::cout << a << " * " << b << " = " << RPN::multiplication(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = std::numeric_limits<int>::min() / 42; b = 43; std::cout << a << " * " << b << " = " << RPN::multiplication(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = std::numeric_limits<int>::min() / 42; b = -43; std::cout << a << " * " << b << " = " << RPN::multiplication(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	std::cout << std::endl;
// }
// 
// // static long	division(long a, long b);
// {
// 	std::cout << MAGENTA << "[TEST] division ________________________________________" << END << std::endl;
// 	long	a, b;
// 	// static long	division(long a, long b);
// 	try { a = 0; b = 0; std::cout << a << " / " << b << " = " << RPN::division(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = 0; b = 42; std::cout << a << " / " << b << " = " << RPN::division(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = 42; b = 0; std::cout << a << " / " << b << " = " << RPN::division(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = std::numeric_limits<int>::min(); b = -1; std::cout << a << " / " << b << " = " << RPN::division(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	std::cout << std::endl;
// 	// std::cout << MAGENTA << "--------------------------------------------------------" << END << std::endl;
// }
// 
// // static long	subtraction(long a, long b);
// {
// 	std::cout << MAGENTA << "[TEST] subtract ________________________________________" << END << std::endl;
// 	long	a, b;
// 	try { a = 0; b = 0; std::cout << a << " - " << b << " = " << RPN::subtraction(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = 0; b = 42; std::cout << a << " - " << b << " = " << RPN::subtraction(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = 42; b = 0; std::cout << a << " - " << b << " = " << RPN::subtraction(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = std::numeric_limits<int>::min() + 1; b = 1; std::cout << a << " - " << b << " = " << RPN::subtraction(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = std::numeric_limits<int>::min(); b = 1; std::cout << a << " - " << b << " = " << RPN::subtraction(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = std::numeric_limits<int>::min(); b = 2; std::cout << a << " - " << b << " = " << RPN::subtraction(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = 1; b = std::numeric_limits<int>::max(); std::cout << a << " - " << b << " = " << RPN::subtraction(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = 2; b = std::numeric_limits<int>::max(); std::cout << a << " - " << b << " = " << RPN::subtraction(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = 1; b = std::numeric_limits<int>::min(); std::cout << a << " - " << b << " = " << RPN::subtraction(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = std::numeric_limits<int>::min(); b = std::numeric_limits<int>::max(); std::cout << a << " - " << b << " = " << RPN::subtraction(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = std::numeric_limits<int>::max(); b = std::numeric_limits<int>::min(); std::cout << a << " - " << b << " = " << RPN::subtraction(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = std::numeric_limits<int>::min(); b = std::numeric_limits<int>::min(); std::cout << a << " - " << b << " = " << RPN::subtraction(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = std::numeric_limits<int>::max(); b = std::numeric_limits<int>::max(); std::cout << a << " - " << b << " = " << RPN::subtraction(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// }
// 
// // static long	addition(long a, long b);
// {
// 	std::cout << MAGENTA << "[TEST] addtion  ________________________________________" << END << std::endl;
// 	long	a, b;
// 	try { a = 0; b = 0; std::cout << a << " + " << b << " = " << RPN::addition(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = 0; b = 42; std::cout << a << " + " << b << " = " << RPN::addition(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = 42; b = 0; std::cout << a << " + " << b << " = " << RPN::addition(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = std::numeric_limits<int>::min() + 1; b = 1; std::cout << a << " + " << b << " = " << RPN::addition(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = std::numeric_limits<int>::min(); b = 1; std::cout << a << " + " << b << " = " << RPN::addition(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = std::numeric_limits<int>::min(); b = -1; std::cout << a << " + " << b << " = " << RPN::addition(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = std::numeric_limits<int>::max() - 1; b = 1; std::cout << a << " + " << b << " = " << RPN::addition(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = std::numeric_limits<int>::max(); b = 1; std::cout << a << " + " << b << " = " << RPN::addition(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = std::numeric_limits<int>::max(); b = -1; std::cout << a << " + " << b << " = " << RPN::addition(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = 1; b = std::numeric_limits<int>::min() + 1; std::cout << a << " + " << b << " = " << RPN::addition(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = 1; b = std::numeric_limits<int>::min(); std::cout << a << " + " << b << " = " << RPN::addition(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = -1; b = std::numeric_limits<int>::min(); std::cout << a << " + " << b << " = " << RPN::addition(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = 1; b = std::numeric_limits<int>::max() - 1; std::cout << a << " + " << b << " = " << RPN::addition(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = 1; b = std::numeric_limits<int>::max(); std::cout << a << " + " << b << " = " << RPN::addition(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = -1; b = std::numeric_limits<int>::max(); std::cout << a << " + " << b << " = " << RPN::addition(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 
// 	try { a = std::numeric_limits<int>::min(); b = std::numeric_limits<int>::min(); std::cout << a << " + " << b << " = " << RPN::addition(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = std::numeric_limits<int>::min(); b = std::numeric_limits<int>::max(); std::cout << a << " + " << b << " = " << RPN::addition(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = std::numeric_limits<int>::max(); b = std::numeric_limits<int>::min(); std::cout << a << " + " << b << " = " << RPN::addition(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// 	try { a = std::numeric_limits<int>::max(); b = std::numeric_limits<int>::max(); std::cout << a << " + " << b << " = " << RPN::addition(a, b) << std::endl; }
// 	catch (std::exception& e) { std::cout << RED << e.what() << END << std::endl; }
// }
// 	system("leaks -q RPN");
// 	return (0);
// }
