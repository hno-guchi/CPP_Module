/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:50:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/13 17:42:24 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0

「容量（キャパシティ）」とは
実際に確保されている動的な文字配列の要素数のこと。（バイト数ではない。）
「サイズ」とは
動的な文字配列内に存在する要素数のこと。（バイト数ではない。）

[] 演算子
サイズを超えた値が与えられた場合
非const 版では、未定義。
const 版では、NULL のポインタが返る。

at
サイズを超えた値が与えられた場合、std::out_of_range例外が送出される。

イテレータ（反復子）とは
データ構造に含まれる各要素に対する操作を抽象化する仕組みのこと。
データ構造の種類に関わらず、同じ方法で要素を操作できる。
イテレータは、C言語のポインタに近い感覚の機能になっているが、
ポインタ　＝＝　イテレータ　ではないので注意。

#endif

#include <iostream>
#include <string>

int	main()
{
	std::string	str1("abcde");
	std::string	empty_str;

	// size, capacity
	std::cout << str1 << "\n"
		<< "    size : [" << str1.size() << "]\n"
		<< "capacity : [" << str1.capacity() << "]\n"
		<< std::endl;
	std::cout << empty_str << "\n"
		<< "    size : [" << empty_str.size() << "]\n"
		<< "capacity : [" << empty_str.capacity() << "]\n"
		<< std::endl;

	// assign
	std::string	str2;
	str2.assign(str1);
	std::cout << str2 << std::endl;


	// []
	std::cout << str1[3] << "\n" << std::flush
		<< str1[10] << std::endl;

	// at
	char	c;
	for (std::size_t i = 0; i < (str1.size() + 1); i++) {
		try {
			c = str1.at(i);
		} catch (std::out_of_range) {
			std::cerr << "Access error." << std::endl;
			// return 1;
		}
		std::cout << c << std::endl;
	}

	// iterator
	std::string::iterator	iterator_end = str1.end();
	for (std::string::iterator iter = str1.begin(); iter != iterator_end; iter++) {
		std::cout << *iter << std::endl;
	}
}
