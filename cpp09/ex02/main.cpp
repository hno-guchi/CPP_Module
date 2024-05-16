#include <sstream>
#include "./PmergeMe.hpp"
#include "./color.hpp"

static int convertStringToInt(const std::string& str) {
	try {
		std::stringstream	ss(str);
		int					ret;

		ss >> ret;
		if (ss.fail()) {
			throw std::runtime_error("Failed to convertStringToInt();");
		}
		return (ret);
	} catch (const std::exception& e) {
		throw;
	}
}

static bool	isDuplicated(const std::vector<int>& vec, int num) {
	try {
		for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++) {
			if (*it == num) {
				return (true);
				// throw std::invalid_argument("Duplicated number");
			}
		}
		return (false);
	} catch (const std::exception& e) {
		throw;
	}
}

std::vector<int>	createVectorInt(int argc, char** argv) {
	try {
		std::vector<int>	ret;
		for (int i = 1; i < argc; i++) {
			int	num = convertStringToInt(argv[i]);
			if (num < 0) {
				throw std::invalid_argument("Negative number");
			}
			if (isDuplicated(ret, num)) {
				continue;
				// throw std::invalid_argument("Duplicated number");
			}
			ret.push_back(num);
		}
		return (ret);
	} catch (const std::exception& e) {
		throw;
	}
}

#include <algorithm>

int main(int argc, char** argv) {
	try {
		if (argc == 1) {
			fatalError("Error", "No arguments");
		}
		std::vector<int>	before = createVectorInt(argc, argv);
		// printInt("Before", before);
		std::vector<int>	after = mergeInsertionSort(before);
		// printInt("After ", after);
#ifdef DEBUG
		std::sort(before.begin(), before.end());
		// printInt("sort()", before);
		if (before != after) {
			fatalError("Error", "Not sorted");
		} else {
			std::cout << "(" << before.size() << ")[" << GREEN << "OK" << END << "]" << std::flush;
		}
#endif  // DEBUG
	} catch (const std::exception& e) {
		fatalError("Error", e.what());
	}
	return (0);
}
