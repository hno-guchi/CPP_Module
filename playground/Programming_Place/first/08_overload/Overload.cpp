/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Overload.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:36:25 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/19 14:39:07 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0

Programming Place Plus C++

第８章　関数オーバーロード
https://programming-place.net/ppp/contents/cpp/language/008.html#overload

関数オーバーロード（オーバーロード、多重定義）とは
仮引数の型や個数が異なれば、同一名称の関数を定義できる機能のこと。
（戻り値が異なるだけだとコンパイルエラーが起きる。）
オーバーロードを行う際は、目的を統一すること。

オーバーロードの解決とは
実引数で呼び出すべき関数を判別すること。コンパイル時に行われる。

#endif

#include <cstdio>

void	write(int i)
{
	std::printf("int    : [%d]\n", i);
}

void	write(double d)
{
	std::printf("double : [%f]\n", d);
}

void	write(char c)
{
	std::printf("char   : [%c]\n", c);
}

void	write(const char *str)
{
	std::printf("str    : [%s]\n", str);
}

int	main()
{
	write(1);
	write(10.2);
	write('a');
	write("Hello, world");
}
