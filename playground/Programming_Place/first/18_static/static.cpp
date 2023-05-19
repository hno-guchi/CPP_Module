#if 0

第１８章　static (静的)

https://programming-place.net/ppp/contents/cpp/language/018.html#static_member_variable

static (静的)
基本的に、C言語と使用方法は同じだが、クラス型のオブジェクトで使用する際には、注意が必要

静的ローカル変数
static指定子を付けて、宣言されたローカル変数のこと。
静的記憶期間を持つ。（プログラムの開始から終了まで存在する。）
クラス型の「静的ローカル変数」のデストラクタは、宣言された関数の終了時ではなく、プログラムの終了時に呼ばれる。
処理の流れ
まず、ゼロ初期化される。
次に、定義箇所が初めて実行されるときに、改めて初期化される。
（コンストラクタが呼び出されるのは、この時）

staticメンバ変数
クラスでの宣言と実体となる定義の２つの記述が必要。
ただし「const 整数型」、「const 列挙型」に限り、宣言と同時に初期化子を与えることができる。

staticメンバ関数
staticメンバ関数は、constメンバ関数にできない。
staticメンバ関数と、非staticメンバ関数の関数オーバーロードはできない（staticメンバ関数同士の関数オーバーロードは可能。）
staticメンバ関数は、クラスに属すので、オブジェクトを生成しなくとも実行できる。
また、オブジェクトから呼び出さないので、thisポインタを使用することはできない。
staticメンバ関数から、非staticメンバ関数へのアクセスはできない。逆は可能。


#endif

class classA {
	public:
		static int	getValue();

	private:
		static const int	value1_ = 0;
		static const double	value2_;
};

const double	classA::value2_ = 10.4;

int	classA::getValue()
{
	return this->value1_;
}

int	main()
{
	return (0);
}
