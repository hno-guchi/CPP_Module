#ifndef INT_HPP
# define INT_HPP

#include <iostream>
#include <string>
#include <vector>

class Int {
 private:
	 int		value_;
	 // 比較演算子が呼び出された回数を記録する静的メンバ変数
	 static int	comparisonCount_;

 public:
	 // CONSTRUCTOR & DESTRUCTOR
	 explicit Int(int value = 0);
	 Int(const Int& other);
	 ~Int();

	 // Overload operators
	 Int&	operator=(const Int& other);
	 Int	operator+(const Int& other) const;
	 Int	operator-(const Int& other) const;
	 Int	operator*(const Int& other) const;
	 Int	operator/(const Int& other) const;
	 // Comparison operators
	 bool	operator==(const Int& other) const;
	 bool	operator!=(const Int& other) const;
	 bool	operator>(const Int& other) const;
	 bool	operator<(const Int& other) const;
	 bool	operator>=(const Int& other) const;
	 bool	operator<=(const Int& other) const;
	 // Getter & Setter
	 int	getValue() const;
	 void	setValue(int value);
	 static int		getComparisonCount();
	 static void	resetComparisonCount();
	 static int		convertStringToInt(const std::string& str);
	 template <typename CONTAINER>
	 static bool	isDuplicate(const CONTAINER& container, int num);
	 template <typename CONTAINER>
	 static void	createContainer(CONTAINER* container, int argc, char** argv);
};

std::ostream&	operator<<(std::ostream& os, const Int& obj);
// std::istream&	operator>>(std::istream& is, Int& obj);

#include "./Int.tpp"

#endif  // INT_HPP
