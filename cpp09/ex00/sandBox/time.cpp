#include <iostream>

int main() {
	time_t		time = std::time(NULL);
	struct tm	*tm = std::localtime(&time);
	char		buf[20] = {0};

	tm->tm_hour = 0;
	tm->tm_min = 0;
	tm->tm_sec = 0;
	tm->tm_isdst = -1;
	if (strftime(buf, sizeof(buf)/sizeof(buf[0]), "%Y-%m-%d %H:%M:%S", tm) == 0) {
		std::cerr << "strftime returned 0" << std::endl;
		return (1);
	}
	std::cout << time << " : " << buf << std::endl;

	time = 0;
	std::memset(tm, 0, sizeof(struct tm));
	tm = std::localtime(&time);
	// tm->tm_hour = 0;
	// tm->tm_min = 0;
	// tm->tm_sec = 0;
	// tm->tm_isdst = -1;
	std::memset(buf, 0, sizeof(buf)/sizeof(buf[0]));
	if (strftime(buf, sizeof(buf)/sizeof(buf[0]), "%Y-%m-%d %H:%M:%S", tm) == 0) {
		std::cerr << "strftime returned 0" << std::endl;
		return (1);
	}
	std::cout << time << " : " << buf << std::endl;

	time = -1;
	std::memset(tm, 0, sizeof(struct tm));
	tm = std::localtime(&time);
	// tm->tm_hour = 0;
	// tm->tm_min = 0;
	// tm->tm_sec = 0;
	// tm->tm_isdst = -1;
	std::memset(buf, 0, sizeof(buf)/sizeof(buf[0]));
	if (strftime(buf, sizeof(buf)/sizeof(buf[0]), "%Y-%m-%d %H:%M:%S", tm) == 0) {
		std::cerr << "strftime returned 0" << std::endl;
		return (1);
	}
	std::cout << time << " : " << buf << std::endl;

	std::memset(tm, 0, sizeof(struct tm));
	if (strptime("1970-01-01 09:00:00", "%Y-%m-%d %H:%M:%S", tm) == NULL) {
		std::cerr << "strptime returned NULL" << std::endl;
		return (1);
	}
	// tm->tm_hour = 0;
	// tm->tm_min = 0;
	// tm->tm_sec = 0;
	// tm->tm_isdst = -1;
	std::cout << "mktime(); " << mktime(tm) << std::endl;
}
