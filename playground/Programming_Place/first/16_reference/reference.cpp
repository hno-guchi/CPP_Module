
#if 0

第１６章　参照
https://programming-place.net/ppp/contents/cpp/language/016.html

lvalueとrvalue
lvalue（左辺値）とは、関数名や変数名のこと。(ex: std::string var; -> var...)
rvalue（右辺値）とは、lvalue（左辺値）ではない全ての値のこと。（ex: int var = 10; -> 10...）

std::string	str = "Hello, world."; のような文字列リテラルは、lvalue（左辺値）として扱う。
関数の戻り値は、rvalue として扱う。またこれによって関数の呼び出し式も rvalue として扱う。

代入式の位置とは、あまり関係がないので、注意すること。
C++の全ての式は、lvalue とrvalue に分類できる。

参照（リファレンス）
定義式：型名＆ 変数名 = 初期化子;
参照型の変数は、lvalue（左辺値）となる。

[初期化子]は、必ず必要。（→ 未初期化の状態（NULL）でないことを保証する。）（ポインタよりも安全らしい。。。）
[初期化子]は、lvalue（左辺値）を指定すること（非const の場合）。
[型名]と[初期化子]のデータ型は、必ず一致すること。

参照先の変数を扱う際に「＊」は、必要ない。またクラスや構造体のメンバを扱う際は「->（アロー演算子）」ではなく「.」を使用すること。

ポインタにできて、参照でできないこと
ポインタ同士で、差分を取るようなアドレス計算。
「ポインタのポインタ」のような「参照の参照。」（ただしこれは、初期化子に参照型の変数を指定することはできる。）

#endif