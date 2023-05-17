#if 0

第１５章 const
https://programming-place.net/ppp/contents/cpp/language/015.html

cont member variable
代入になるので、コンストラクタの本体コードで初期化できない。
メンバライズイニシャライズを使用すること（１）
オブジェクトのコピーを行う際は、operator=() が必要（２）

#endif

class	classA {
	public:
		classA();

	private:
		const int	value;
}

// (1)
classA::classA() :
	value(0)
{
}
