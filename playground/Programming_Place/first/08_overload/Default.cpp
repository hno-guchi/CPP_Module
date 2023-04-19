/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Default.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:18:50 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/19 16:13:36 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0

Programming Place Plus C++

第８章　関数オーバーロード
https://programming-place.net/ppp/contents/cpp/language/008.html#overload

default実引数
関数に実引数を渡さなかった場合に、デフォルトの値が指定されたと見なす機能のこと。
デフォルトの値は、基本的に定数を設定すること。（一応、関数の戻り値でもできる）

書き方（関数宣言時に記述すること）
ReturnType	FuncName([Param, ...], Type Name = Value);

デフォルト実引数は、関数オーバーロードで代替できる。（ただし仕組みは異なる。）
関数オーバーロードの場合
関数使用者は、内部で設定された値を意識する必要がないので、
作成者は、自由に内部で設定する値を変更できる。
関数を保存するメモリは、元々の関数と関数オーバーロードした関数の２つ。

デフォルト実引数の場合
関数使用者は、デフォルト実引数の値を見た上で使用していることが想定されるので、
作成者は、デフォルト実引数の値の変更を慎重に行う必要がある。
関数を保存するメモリは、１つ。

仮引数が複数ある場合、
デフォルト実引数を指定した仮引数以降の引数には、デフォルト実引数を指定しなければならない。
ex)
func(int a, int b = 10, int c = 20); // OK
func(int a, int b = 10, int c);      // NG

#endif

#include <iostream>

// int	divide(int a, int b, int *c = NULL)
int	divide(int a, int b, int *c)
{
	if (c != NULL)
	{
		*c = a % b;
	}
	return (a / b);
}

int	divide(int a, int b)
{
	return (divide(a, b, NULL));
}

int	main()
{
	int	a;
	int	c;

	a = divide(10, 3, &c);
	std::cout << a << "..." << c << std::endl;
	a = divide(10, 3);
	std::cout << a << std::endl;
}
