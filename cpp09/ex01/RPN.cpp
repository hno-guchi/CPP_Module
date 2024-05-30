#include "./RPN.hpp"

const std::string	RPN::operations_ = "+-/*";

long	RPN::multiplication(long a, long b) {
	try {
		if (a == 0 || b == 0) {
			return (0);
		}
		if (a > 0) {
			if (b > 0) {
				if (a > std::numeric_limits<int>::max() / b) {
					throw std::out_of_range("Over Int.");
				}
			} else {
				if (b < std::numeric_limits<int>::min() / a) {
					throw std::out_of_range("Over Int.");
				}
			}
		} else {
			if (b > 0) {
				if (a < std::numeric_limits<int>::min() / b) {
					throw std::out_of_range("Over Int.");
				}
			} else {
				if (a != 0 && b < std::numeric_limits<int>::max() / a) {
					throw std::out_of_range("Over Int.");
				}
			}
        }
		long	result = a * b;
		if (result < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < result) {
			throw std::out_of_range("Over Int.");
		}
		return (result);
	} catch (const std::exception& e) {
		throw;
	}
}

long	RPN::division(long a, long b) {
	try {
		if (b == 0) {
			throw std::invalid_argument("Occurs Zero division.");
		}
		if (a == std::numeric_limits<int>::min() && b == -1) {
			throw std::out_of_range("Over Int.");
		}
		long	result = a / b;
		if (result < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < result) {
			throw std::out_of_range("Over Int.");
		}
		return (result);
	} catch (const std::exception& e) {
		throw;
	}
}

long	RPN::subtraction(long a, long b) {
	try {
		if (b > 0) {
			if (a < std::numeric_limits<int>::min() + b) {
				throw std::out_of_range("Over Int.");
			}
		} else {
			if (a > std::numeric_limits<int>::max() + b) {
				throw std::out_of_range("Over Int.");
			}
    	}
		long	result = a - b;
		if (result < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < result) {
			throw std::out_of_range("Over Int.");
		}
		return (result);
	} catch (const std::exception& e) {
		throw;
	}
}

long	RPN::addition(long a, long b) {
	try {
		if (b > 0) {
			if (a > std::numeric_limits<int>::max() - b) {
				throw std::out_of_range("Over Int.");
			}
		} else {
			if (a < std::numeric_limits<int>::min() - b) {
				throw std::out_of_range("Over Int.");
			}
		}
		long	result = a + b;
		if (result < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < result) {
			throw std::out_of_range("Over Int.");
		}
		return (result);
	} catch (const std::exception& e) {
		throw;
	}
}

long	RPN::getNumber(std::deque<long>* buf) {
	try {
		long num = buf->front();
		buf->pop_front();
		if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max()) {
			throw std::out_of_range("Over Int.");
		}
		return (num);
	} catch (const std::exception& e) {
		throw;
	}
}

void	RPN::calculate(const char operation, std::deque<long>* buf) {
	if (buf->size() < 2) {
		throw std::invalid_argument("Not enough numbers.");
	}
	try {
		long b = RPN::getNumber(buf);
		long a = RPN::getNumber(buf);
		long result(0);
		switch (operation) {
			case '+':
				result = RPN::addition(a, b);
				break;
			case '-':
				result = RPN::subtraction(a, b);
				break;
			case '/':
				result = RPN::division(a, b);
				break;
			case '*':
				result = RPN::multiplication(a, b);
				break;
			default:
				throw std::invalid_argument("Wrong operation.");
		}
		buf->push_front(result);
	}
	catch(const std::exception& e) {
		throw;
	}
}

char	RPN::getToken(const std::string& str, std::string::const_iterator& it, const std::locale l) {
	try {
		std::string	token;

		for (; !std::isspace(*it, l); it++) {
			token += static_cast<char>(*it);
			if ((it + 1) == str.end()) {
				break;
			}
		}
		if (token.size() != 1) {
			throw std::invalid_argument("Only use 0 ~ 9 or +, -, *, /.");
		}
		return (static_cast<char>(token[0]));
	} catch (const std::exception& e) {
		throw;
	}
}

// SUBJECT FUNC
void	RPN::execute(const std::string& str) {
	if (str.empty()) {
		throw std::invalid_argument("Empty argument.");
	}

	std::deque<long>	buf;
	std::locale			l = std::locale::classic();
	try {
		for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
			if (std::isspace(*it, l)) {
				continue;
			}

			char	token = RPN::getToken(str, it, l);

			if (std::isdigit(token, l)) {
				buf.push_front(token - '0');
			} else if (RPN::operations_.find(token) != RPN::operations_.npos) {
				RPN::calculate(token, &buf);
			} else {
				throw std::invalid_argument("Non digit or operations(+-*/).");
			}
		}
		if (buf.size() != 1) {
			throw std::invalid_argument("Wrong format.");
		}
	}
	catch (const std::exception& e) {
		throw;
	}
	// printBuff(buf);
	std::cout << buf.front() << std::endl;
}

// DEBUG
void	RPN::printBuff(const std::deque<long>& buf) {
	if (buf.empty()) {
		return;
	}
	long	i = 0;
	for (std::deque<long>::const_iterator itr = buf.begin(); itr != buf.end(); itr++) {
		std::cout << "[" << i << "]" << std::flush;
		if ((itr + 1) != buf.end()) {
			std::cout << " -> " << std::flush;
		}
		i += 1;
	}
	std:: cout << std::endl;
	for (std::deque<long>::const_iterator itr = buf.begin(); itr != buf.end(); itr++) {
		std::cout << "[" << *itr << "]" << std::flush;
		if ((itr + 1) != buf.end()) {
			std::cout << " -> " << std::flush;
		}
	}
	std:: cout << std::endl;
}
