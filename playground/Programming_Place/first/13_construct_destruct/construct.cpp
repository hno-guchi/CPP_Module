#if 0

第１３章　コンストラクトとデストラクト

https://programming-place.net/ppp/contents/cpp/language/013.html

コンストラクタのオーバーロード
オブジェクトをインスタンス化する際に与える実引数のデータ型に応じて使用するコンストラクタを分けることができる。（１）

#endif

class classA {
	public:
		classA(const int value);
		classA(const float value);
	
	private:
		int	value;
};

classA::classA(const int value) :
	value(value)
{
}

classA::classA(const float value) :
	value(value)
{
}

