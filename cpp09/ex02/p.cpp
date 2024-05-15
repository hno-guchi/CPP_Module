#include <iostream>

int main() {
	int i;

	unsigned int p = reinterpret_cast<unsigned long>(&i);
	std::cout << &i << std::endl;
	std::cout.setf(std::ios::showbase);
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout << p << std::endl;
}
