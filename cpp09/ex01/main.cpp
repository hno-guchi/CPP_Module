#include "./RPN.hpp"
#include "./color.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << RED << "Please give a single argument." << END << std::endl;
		return (1);
	}
	try {
		const RPN	rpn;
		rpn.execute(static_cast<std::string>(argv[1]));
	} catch (std::exception& e) {
		std::cout << RED << e.what() << END << std::endl;
	}
#ifdef LEAKS
	system("leaks -q RPN");
#endif
	return (0);
}
