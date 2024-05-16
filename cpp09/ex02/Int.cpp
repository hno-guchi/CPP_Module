#include <iostream>
#include <sstream>
#include "./Int.hpp"

int	Int::comparisonCount_ = 0;

// CONSTRUCTOR & DESTRUCTOR
Int::Int(int value) : value_(value) {}
Int::Int(const Int& other) : value_(other.getValue()) {}
Int::~Int() {}

// Overload operators
Int&	Int::operator=(const Int& other) {
	if (this != &other) {
		this->value_ = other.getValue();
	}
	return (*this);
}

Int	Int::operator+(const Int& other) const {
	return (Int(this->value_ + other.getValue()));
}

Int	Int::operator-(const Int& other) const {
	return (Int(this->value_ - other.getValue()));
}

Int	Int::operator*(const Int& other) const {
	return (Int(this->value_ * other.getValue()));
}

Int	Int::operator/(const Int& other) const {
	if (other.getValue() == 0) {
		throw std::runtime_error("Division by zero");
	}
	return (Int(this->value_ / other.getValue()));
}

// Comparison operators
bool	Int::operator==(const Int& other) const {
	this->comparisonCount_ += 1;
	return (this->value_ == other.getValue());
}

bool	Int::operator!=(const Int& other) const {
	this->comparisonCount_ += 1;
	return (this->value_ != other.getValue());
}

bool	Int::operator>(const Int& other) const {
	this->comparisonCount_ += 1;
	return (this->value_ > other.getValue());
}

bool	Int::operator<(const Int& other) const {
	this->comparisonCount_ += 1;
	return (this->value_ < other.getValue());
}

bool	Int::operator>=(const Int& other) const {
	this->comparisonCount_ += 1;
	return (this->value_ >= other.getValue());
}

bool	Int::operator<=(const Int& other) const {
	this->comparisonCount_ += 1;
	return (this->value_ <= other.getValue());
}

// Getter & Setter
int	Int::getValue() const {
	return (this->value_);
}

void Int::setValue(int value) {
	this->value_ = value;
}

int	Int::getComparisonCount() {
	return (Int::comparisonCount_);
}

void	Int::resetComparisonCount() {
	Int::comparisonCount_ = 0;
}

std::ostream&	operator<<(std::ostream& os, const Int& obj) {
	os << obj.getValue();
	return (os);
}

// std::istream&	operator>>(std::istream& is, Int& obj) {
// 	is >> obj.value_;
// 	return (is);
// }

int Int::convertStringToInt(const std::string& str) {
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

bool	Int::isDuplicated(const std::vector<Int>& vec, int num) {
	try {
		for (std::vector<Int>::const_iterator it = vec.begin(); it != vec.end(); it++) {
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

std::vector<Int>	Int::createVectorInt(int argc, char** argv) {
	try {
		std::vector<Int>	ret;
		for (int i = 1; i < argc; i++) {
			Int	num(Int::convertStringToInt(argv[i]));
			if (num.getValue() < 0) {
				throw std::invalid_argument("Negative number");
			}
			if (isDuplicated(ret, num.getValue())) {
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

// #include <algorithm>
//
// int main(int argc, char** argv) {
// 	try {
// 		if (argc == 1) {
// 			return (1);
// 		}
// 		std::vector<Int>	before = Int::createVectorInt(argc, argv);
// 		// printInt("Before", before);
// 		std::sort(before.begin(), before.end());
// 		std::cout << "std::sort():" << Int::getComparisonCount() << std::endl;
// 	} catch (const std::exception& e) {
// 			return (1);
// 	}
// 	return (0);
// }
