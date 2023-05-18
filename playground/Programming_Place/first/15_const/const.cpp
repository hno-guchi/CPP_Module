#if 0

第１５章 const
https://programming-place.net/ppp/contents/cpp/language/015.html

cont member variable
代入になるので、コンストラクタの本体コードで初期化できない。
メンバライズイニシャライズを使用すること（１）
オブジェクトのコピーを行う際は、operator=() が必要（２）

const member function
メンバ関数宣言時に、後ろに const を付ける。
constオブジェクト、constポインタ（参照）は、const member functionのみ呼び出すことができる。(3)
const member function内では、thisポインタは、constポインタになるので、メンバ変数の値の変更ができない。
const member function内で、別のメンバ関数を呼び出す際は、そのメンバ関数もconst member functionである必要がある。
オーバーロードできる。

#endif

class	classA {
	public:
		classA();

		void	funcA() const;
		void	funcB();

	private:
		const int	value;
}

// (1)
classA::classA() :
	value(0)
{
}

int	main()
{
	const classA	a();

	// (3)
	a.funcA(); // [OK]
	a.funcB(); // [NG]
}
