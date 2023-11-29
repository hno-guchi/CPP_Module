#include <map>
#include <iostream>

void	add(std::map<int, std::string>& m)
{
	for (int i = 0; i < 10; i++) {
		m[i] = "hello";
	}
}

void	print(std::map<int, std::string>& m)
{
	for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); it++) {
		std::cout << it->first << "[" << &(it->first) << "]" << " " \
			<< it->second << "[" << &(it->second) << "]" << std::endl;
	}
}

int	main()
{
	std::map<int, std::string> m;

	add(m);
	print(m);

	// system("leaks -q a.out");
}
