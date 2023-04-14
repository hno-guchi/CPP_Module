/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdio_stream.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:00:12 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/14 10:23:03 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0
第５章　標準入出力ストリームの基礎
https://programming-place.net/ppp/contents/cpp/language/005.html

標準出力ストリーム（std::cout）
printf();のように、指定子が必要ない。
作成した任意の型を出力する拡張性がある。

標準入力ストリーム（std::cin）
char の配列で受け取る際、
配列の要素数以上の文字列を受け取ると、オーバーフローを起こすので、
std::string で受け取ること。
空白文字を読み飛ばす。
std::setw() で、受け取る文字列の数を指定できる。

標準エラーストリーム（std::cerr, std::clog）
std::cerr は、バッファリングされない。
std::clog は、バッファリングされる。

マニピュレータとは
入出力方法を制御する仕組みのこと
std::setw(), std::endl, std::flush, std::hex, std::oct, std::dec
std::setw() のような引数を伴うマニピュレータを扱うには、#include <iomanip>

#endif

#include <iostream>
#include <ios>
#include <iomanip>

int	main()
{
	char	str[8];
	// int		num;
	// double	d;

	// Standard output
	std::cout << "std::cin" << std::endl;
	// std::cin >> str;
	// std::cin >> num;
	// std::cin >> d;
	// std::cin >> str >> num >> d;
	// std::cout << str << num << d << std::endl;

	// Standard input
	std::cin >> std::setw(sizeof(str)) >> str;
	std::cout << str << std::endl;
	
	// Standard error
	std::cerr << "std::cerr" << std::endl;
	std::clog << "std::clog" << std::endl;

	// Practice
	int	number = 128;
	std::cout.setf(std::ios::showbase);
	std::cout.setf(std::ios::dec, std::ios::basefield);
	std::cout << "dec [" << number << "]" << std::endl;
	std::cout.setf(std::ios::oct, std::ios::basefield);
	std::cout << "oct [" << number << "]" << std::endl;
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout << "hex [" << number << "]" << std::endl;

	std::cout.unsetf(std::ios::showbase);
	std::cout.setf(std::ios::dec, std::ios::basefield);
	std::cout << "dec [" << number << "]" << std::endl;
	std::cout.setf(std::ios::oct, std::ios::basefield);
	std::cout << "oct [" << number << "]" << std::endl;
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout << "hex [" << number << "]" << std::endl;
}
