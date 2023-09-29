#include <iostream>

int	divide(int a, int b)
{
	if (b == 0) {
		throw "Occurred Zero division.";
	}
	return (a / b);
}

// デストラクタと例外
// デストラクタから例外を送出することは避けること。

// コンストラクタと例外
// コンストラクタ内で発生した例外をコンストラクタ内で補足することで、コンストラクタの処理を最後まで実行することができる。
// これによって、デストラクタを呼ぶことができる。
// コンストラクタが最後まで処理を実行しなかった場合、オブジェクトは生成されず、デストラクタを呼ぶことが出来なくなる。
// class MyClass {
// public:
// 	MyClass::MyClass()
// 		: value_(new int())
// 	{
// 		try {
// 			*value_ = divide(10, 0);
// 		}
// 		catch (const char*) {
// 			std::cerr << "Failed initialize member variable(value_)." << std::endl;
// 		}
// 	}
// 	MyClass::~MyClass()
// 	{
// 		delete value_;
// 	}
// private:
// 	int*	value_;
// };

// 関数tryブロック
// classのメンバ変数の初期化で発生した例外や、基底クラスのコンストラクタ発生した例外でキャッチする方法。
// class MyClass : public BaseClass {
// public:
// 	MyClass()
// 	try
// 	 : BaseClass(100), other_(200)
// 	 {
// 	 }
// 	catch {
// 	}
// private:
// 	OtherClass	other_;
// };

// 再送出
// 同じ例外をさらに上の処理に送出すること。
// 例外が補足されていない状態で「throw;」とした場合、std::terminate関数が呼び出され、プログラムが異常終了する。
// try {} catch (const std::exception& e) { throw; }


// 補足する型
// 例外クラスを補足する場合、catchブロックには、const 基底クラスの型の参照を指定すること。
// class MyClass : public std::exception {};
// try {} catch (const std::exception& e) { throw e; }

// 全ての例外オブジェクトを補足する場合の書き方
// try {} catch (...) {}

// version.2
// 「例外安全」とは、
// 例外が送出されてもメモリの解放抜け（メモリリーク）などの問題が発生しないようにすること。
class Integer {
public:
	Integer() : value_(new int()) {}
	~Integer() { delete value_; }
	void	Set(int value) { *value_ = value; }
	int		Get() { return (*value_); }
private:
	int	*value_;
};

int	main()
{
	try {
		Integer	result;
		result.Set(divide(10, 0));
		std::cout << result.Get() << std::endl;
	}
	catch (const char *s) {
		std::cerr << s << std::endl;
	}
	std::cout << "Finish." << std::endl;
}

// version.1
// int	main()
// {
// 	try {
// 		int	*result = new int();
// 		*result = divide(10, 0); // ---> ここで例外が発生されると、以下の文は実行されない。
// 								 //      deleteなどの処理を実行したい場合は、クラスのコンストラクタとデストラクタで行うようにする。(version.2参照)
// 		std::cout << result << std::endl;
// 		delete result;
// 	}
// 	catch (const char *s) {
// 		std::cerr << s << std::endl;
// 	}
// 	std::cout << "Finish." << std::endl;
// }
