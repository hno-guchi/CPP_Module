#include <iostream>
#include <ctime>

int	main() {
	// patern 1
	std::time_t	arg;
	(void)std::time(&arg);
	if (arg == -1) {
		std::cerr << "The time() function failed" << std::endl;
	}
	std::tm*	localTime = std::localtime(&arg);
	if (localTime == NULL) {
		std::cerr << "The localtime() function failed" << std::endl;
	}

	// patern 2
	// std::time_t	currentTime = std::time(NULL);
	// 	if (currentTime == -1) {
	// 	std::cerr << "The time() function failed" << std::endl;
	// }
	// std::tm*	localTime = std::localtime(&currentTime);
	// if (localTime == NULL) {
	// 	std::cerr << "The localtime() function failed" << std::endl;
	// }

	int	year = 1900 + localTime->tm_year;
	int	month = 1 + localTime->tm_mon;
	int	day = localTime->tm_mday;
	int	hour = localTime->tm_hour;
	int	minute = localTime->tm_min;
	int	second = localTime->tm_sec;

	std::cout << "Year: " << year << ", Month: " << month << ", Day: " << day \
		<< ", Hour: " << hour << ", Minute: " << minute << ", Second: " << second << std::endl;
	system("leaks -q a.out");
	return (0);
}
