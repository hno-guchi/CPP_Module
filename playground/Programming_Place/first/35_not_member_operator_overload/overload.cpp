#if 0

第３５章　非メンバの演算子のオーバーロード

https://programming-place.net/ppp/contents/cpp/language/035.html

ユーザー定義型をストリームへ渡す
(1)

#endif

class classA {
	public:
		classA(const int value);
		int	getValue() const;

	private:
		int	value_;
};

classA::classA(const int value) :
	value_(value)
{
}

int	classA::getValue() const
{
	return (this->value_);
}

// (1)
std::ostream&	operator<<(std::ostream& lhs, const classA& rhs)
{
	lhs << rhs.getValue();
	return (lhs);
}

int	main()
{
	classA	a(10);

	std::cout << a << std::endl;
}
