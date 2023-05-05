
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

#endif
