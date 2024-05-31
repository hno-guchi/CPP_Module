template <typename CONTAINER>
bool	Int::isDuplicate(const CONTAINER& container, int num) {
	try {
		for (typename CONTAINER::const_iterator it = container.begin(); it != container.end(); it++) {
			if (it->getValue() == num) {
				return (true);
				// throw std::invalid_argument("Duplicated number");
			}
		}
		return (false);
	} catch (const std::exception& e) {
		throw;
	}
}

template <typename CONTAINER>
void	Int::setValues(CONTAINER* container, int argc, char** argv) {
	try {
		for (int i = 1; i < argc; i++) {
			Int	num(Int::convertStringToInt(argv[i]));
			if (num.getValue() < 0) {
				throw std::invalid_argument("Negative number");
			}
			if (Int::isDuplicate(*container, num.getValue())) {
				continue;
				// throw std::invalid_argument("Duplicated number");
			}
			container->push_back(num);
		}
	} catch (const std::exception& e) {
		throw;
	}
}


