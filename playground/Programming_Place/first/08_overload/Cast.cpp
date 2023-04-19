/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cast.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:58:00 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/19 15:19:54 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0

Programming Place Plus C++

第８章　関数オーバーロード
https://programming-place.net/ppp/contents/cpp/language/008.html#overload

曖昧な呼び出し
「呼び出し可能な最適関数」が１つに定まらない場合、引数をキャストして渡す必要がある。
仮引数を整数型とポインタ型で、オーバーロードする関数は、相性がよくない。
例）
func(float f); func(double d); に、１を渡した時。
func(int i); func(void *p); に、０やNULLを渡した時。

#endif

#include <iostream>

void	print_value(float f)
{
	std::cout << "float  : [" << f << "]" << std::endl;
}

void	print_value(double d)
{
	std::cout << "double : [" << d << "]" << std::endl;
}

// 新しく作成する
void	print_value(int i)
{
	std::cout << "int    : [" << i << "]" << std::endl;
}

void	func(int i)
{
	std::cout << "int    : [" << i << "]" << std::endl;
}

void	func(void *p)
{
	std::cout << "void*  : [" << p << "]" << std::endl;
}

int	main()
{
	print_value(10.5f);
	print_value(10.5);
	// print_value(1); // Complile error
	print_value(static_cast<float>(1));

	func(0);
	func(NULL); // Compile error
	func(static_cast<void *>(NULL));
}
