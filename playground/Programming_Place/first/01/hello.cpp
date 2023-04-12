/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:10:28 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/12 16:30:21 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#if 0
Programming Place Plus C++
第１章　Hello, World プログラム
https://programming-place.net/ppp/contents/cpp/language/001.html


一般的にC++ では、main(void); のvoid は、省略する。
一般的ではないが、return 0; も省略可能

main 関数は、再帰呼び出し、オーバーロードができない。
C++ には、オペランドによって演算子の意味が変わる機能がある
（演算子のオーバーロードと呼ぶ。）

オペランドとは、
被演算子のこと。[a + b] における[a], [b] のことを指す。
#endif

#include <iostream>

int	main(int argc, char **argv)
{
	// std::cout とは、標準出力ストリームを意味する。
	// std::endl とは、改行と、フラッシュを意味する。
	// よって以下の文は、標準出力ストリームに「文字列」＋「改行」＋「フラッシュ」を送ることを意味している。
	std::cout << "Hello, World!" << std::endl;
	std::cout << std::endl;

	// Practice 1
	std::cout << "Hello," << std::endl;
	std::cout << "World" << std::endl;
	std::cout << std::endl;

	//Practice 2
	for (int i = 1; i < argc; i++)
	{
		std::cout << argv[i] << std::endl;
	}
	return 0;
}
