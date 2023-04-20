/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Estimate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:18:29 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/20 10:20:16 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0

Programming Place Plus C++

第９章　関数テンプレート
https://programming-place.net/ppp/contents/cpp/language/009.html

テンプレート実引数の推定
コンパイラがテンプレート実引数を自動で判別する機能のこと。
関数テンプレートを呼び出す際に、指定する実引数をもとに判別する。
積極的な使用が推奨されている。

文字列リテラルは、const char[]; として扱われる。
std::string にしたい場合は、明示的に指定すること。

テンプレート仮引数が複数個ある場合、末尾のみ推定とする書き方もある。
戻り値のテンプレート仮引数は、推定できない。
よって、戻り値にテンプレート仮引数を使用する場合は、初めに指定すると良い。

#endif

#include <iostream>

template <typename T>
void	write(T var)
{
	std::cout << var << std::endl;
}

template <typename T1, typename T2>
void	write_max(T1 var_1, T2 var_2)
{
	std::cout << ((var_1 <= var_2) ? (var_1) : (var_2)) << std::endl;
}

template <typename RET, typename T1, typename T2>
RET	Add(T1 a, T2 b)
{
	return (a + b);
}


int	main()
{
	write(1);     // int
	write(10.5);  // double
	write('a');   // char
	write("abc"); // const char[]
	
	write_max(10, 10.5);
	write_max<int>(10, 10.5);
	write_max<int, double>(10, 10.5);

	// write(Add(10, 10.5)); // Compile Error
	write(Add<double>(10, 10.5));
}
