/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:57:03 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/12 18:01:50 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0
1. 変数の宣言を行う際は、その変数を使用する直前に宣言すべき。
   変数定義部分を実行する際、多くの処理がなされるため。（コンストラクタ）

2. 文字列リテラルは、char 型。
  （関数のオーバーロードに対応するため。）

3. struct, enum, union キーワードは、省略できる。

4. void ポインタ型を任意のポインタ型に変換する際は、明示的なキャストが必要。
   任意のポインタ型からvoid ポインタ型に変換する際は、暗黙の型変換が発生する。

5. NULL は、必ず整数型の定数に置換される。
  （関数オーバーロードの機能を使用した際に発生する問題は、第８章で説明）

6. 列挙型について
   int型の値をenum の変数に代入する際は、明示的なキャストが必要。
   逆に、enum の変数の値を、int型の変数に代入する際は、暗黙の型変換が発生する。
#endif

#include <iostream>
#include <cstring>
#include <cstdlib>

struct	Point2D {
	int	x;
	int	y;
};

enum	Color {
	RED,
	BLUE,
	YELLOW,
};

// int	f(int n)
// {
// 	return (n + 10);
// }

int	main()
{
	// 1.
	const char* str = "Hello, World.";
	std::cout << str << std::endl;

	std::size_t len = std::strlen(str);
	std::cout << len << std::endl;
	std::cout << std::endl;

	//2.
	char c = 'A';
	std::cout << sizeof('A') << "\n"
		<< sizeof(c) << std::endl;
	std::cout << std::endl;

	// 3.
	Point2D	point;
	point.x = 40;
	point.y = 100;
	std::cout << "point.x [" << point.x << "];" << "\n"
		<< "point.y [" << point.y << "];" << std::endl;
	std::cout << std::endl;

	// 4.
	// C++では、malloc(); の代わりに、new 演算子が用いられる。
	int*	p = (int*)std::malloc(sizeof(int));
	*p = 100;
	std::cout << *p << std::endl;
	std::cout << std::endl;
	std::free(p);

	// 5.
	// (void)f(NULL);

	// 6.
	Color	color = (Color)1;
	int		v = BLUE;
	std::cout << "color is [" << color << "]\n"
		<< "v     is [" << v << "]"
		<< std::endl;
	std::cout << std::endl;

	// practice 1
	// Ansewer print A
	std::cout << 'A' << std::endl;

	// practice 2
	Color	colors = (Color)0;
	colors = (Color)(colors + 1);
	std::cout << colors << std::endl;

	return (0);
}
