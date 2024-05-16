#ifndef INT_HPP
# define INT_HPP

#include <iostream>

// 静的メンバ変数の定義
int Int::comparisonCount = 0;

class Int {
 private:
	 int		value;
	 static int	comparisonCount;  // 比較演算子が呼び出された回数を記録する静的メンバ変数

 public:
	 // CONSTRUCTOR & DESTRUCTOR
	 Int(int val = 0) : value(val) {}
	 Int(const Int& other) : value(other.value) {}
	 ~Int() {}

	 // Overload operators
	 Int& operator=(const Int& other) {
		 if (this != &other) {
			 value = other.value;
		 }
		 return *this;
	 }
	 Int operator+(const Int& other) const {
		 return Int(value + other.value);
	 }
	Int operator-(const Int& other) const {
		return Int(value - other.value);
	}
	Int operator*(const Int& other) const {
		return Int(value * other.value);
	}
	Int operator/(const Int& other) const {
		if (other.value == 0) {
			throw std::runtime_error("Division by zero");
		}
		return Int(value / other.value);
	}
	// Comparison operators
	bool operator==(const Int& other) const {
		comparisonCount++;
		return value == other.value;
	}
	bool operator!=(const Int& other) const {
		comparisonCount++;
		return value != other.value;
	}
	bool operator>(const Int& other) const {
		comparisonCount++;
		return value > other.value;
	}
	bool operator<(const Int& other) const {
		comparisonCount++;
		return value < other.value;
	}
	bool operator>=(const Int& other) const {
		comparisonCount++;
		return value >= other.value;
	}
	bool operator<=(const Int& other) const {
		comparisonCount++;
		return value <= other.value;
	}
	friend std::ostream& operator<<(std::ostream& os, const Int& obj) {
		os << obj.value;
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Int& obj) {
		is >> obj.value;
		return is;
	}

	// Getter & Setter
	int	getValue() const {
		return value;
	}
	void setValue(int val) {
		value = val;
	}
	static int getComparisonCount() {
		return comparisonCount;
	}
	static void resetComparisonCount() {
		comparisonCount = 0;
	}
};

#endif  // INT_HPP
