#include "./RPN.hpp"

// debug
// static void	printBuff(const std::deque<long>& buf);

// CONSTRUCTER & DESTRUCTER
RPN::RPN() : operations_("+-/*") {}
RPN::~RPN() {}

long	RPN::multiplication(long a, long b) const {
	try {
		long	result = a * b;
		if (result < INT_MIN || INT_MAX < result) {
			throw RPN::OverInt();
		}
		return (result);
	} catch (const std::exception& e) {
		throw;
	}
}

long	RPN::division(long a, long b) const {
	try {
		if (b == 0) {
			throw RPN::InvalidArg("Occurs Zero division.");
		}
		long	result = a / b;
		if (result < INT_MIN || INT_MAX < result) {
			throw RPN::OverInt();
		}
		return (result);
	} catch (const std::exception& e) {
		throw;
	}
}

long	RPN::subtraction(long a, long b) const {
	try {
		long	result = a - b;
		if (result < INT_MIN || INT_MAX < result) {
			throw RPN::OverInt();
		}
		return (result);
	} catch (const std::exception& e) {
		throw;
	}
}

long	RPN::addition(long a, long b) const {
	try {
		long	result = a + b;
		if (result < INT_MIN || INT_MAX < result) {
			throw RPN::OverInt();
		}
		return (result);
	} catch (const std::exception& e) {
		throw;
	}
}

long	RPN::getNumber(std::deque<long>* buf) const {
	try {
		long num = buf->front();
		buf->pop_front();
		return (num);
	} catch (const std::exception& e) {
		throw;
	}
}

void	RPN::calculate(const char operation, std::deque<long>* buf) const {
	if (buf->size() < 2) {
		throw RPN::InvalidArg("Not enough numbers.");
	}
	try {
		long b = this->getNumber(buf);
		long a = this->getNumber(buf);
		long result(0);
		switch (operation) {
			case '+':
				result = this->addition(a, b);
				break;
			case '-':
				result = this->subtraction(a, b);
				break;
			case '/':
				result = this->division(a, b);
				break;
			case '*':
				result = this->multiplication(a, b);
				break;
			default:
				throw RPN::InvalidArg("Wrong operation.");
		}
		buf->push_front(result);
	}
	catch(const std::exception& e) {
		throw;
	}
}

char	RPN::getToken(const std::string& str, std::string::const_iterator& it, const std::locale l) const {
	try {
		std::string	token;

		for (; !std::isspace(*it, l); it++) {
			token += static_cast<char>(*it);
			if ((it + 1) == str.end()) {
				break;
			}
		}
		if (token.size() != 1) {
			throw RPN::InvalidArg("Only use 0 ~ 9 or +, -, *, /.");
		}
		return (static_cast<char>(token[0]));
	} catch (const std::exception& e) {
		throw;
	}
}

// SUBJECT FUNC
void	RPN::execute(const std::string& str) const {
	if (str.empty()) {
		throw RPN::InvalidArg("Empty argument.");
	}

	std::deque<long>	buf;
	std::locale			l = std::locale::classic();
	try {
		for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
			if (std::isspace(*it, l)) {
				continue;
			}

			char	token = this->getToken(str, it, l);

			if (std::isdigit(token, l)) {
				buf.push_front(token - '0');
			} else if (this->operations_.find(token) != this->operations_.npos) {
				this->calculate(token, &buf);
			} else {
				throw RPN::InvalidArg("Non digit or operations(+-*/).");
			}
		}
		if (buf.size() != 1) {
			throw RPN::InvalidArg("Wrong format.");
		}
	}
	catch (const std::exception& e) {
		throw;
	}
	// printBuff(buf);
	std::cout << buf.front() << std::endl;
}

// EXCEPTION
RPN::InvalidArg::InvalidArg(const std::string& msg) : std::invalid_argument(msg) {}
RPN::OverInt::OverInt(const std::string& msg) : std::out_of_range(msg) {}

// debug
// static void	printBuff(const std::deque<long>& buf)
// {
// 	if (buf.empty()) {
// 		return ;
// 	}
// 	long	i = 0;
// 	for (std::deque<long>::const_iterator itr = buf.begin(); itr != buf.end(); itr++) {
// 		std::cout << "[" << i << "]" << std::flush;
// 		if ((itr + 1) != buf.end()) {
// 			std::cout << " -> " << std::flush;
// 		}
// 		i += 1;
// 	}
// 	std:: cout << std::endl;
// 	for (std::deque<long>::const_iterator itr = buf.begin(); itr != buf.end(); itr++) {
// 		std::cout << "[" << *itr << "]" << std::flush;
// 		if ((itr + 1) != buf.end()) {
// 			std::cout << " -> " << std::flush;
// 		}
// 	}
// 	std:: cout << std::endl;
// }
