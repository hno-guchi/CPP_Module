/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:30:44 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/20 10:05:58 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0

Programming Place Plus C++

第９章　関数テンプレート
https://programming-place.net/ppp/contents/cpp/language/009.html

関数テンプレートとは
１つの関数の実装を、複数の型で使用できるようにする機能のこと。（未知の型でも可能）
関数テンプレートから関数を生成することを「実体化」と呼ぶ。
「実体化」された関数自体を「特殊化」と呼ぶ。

宣言
template <typename テンプレート仮引数名>
ReturnType TempFuncName(temp_args[, ...]);

定義
template <typename テンプレート仮引数名>
ReturnType TempFuncName(temp_args[, ...])
{
	// func
}

<typename テンプレート仮引数名>は「テンプレート仮引数名」を型であることを意味する。
テンプレート仮引数名は、テンプレートパラメータとも呼ぶ。
typename keyword は、class keywordに置き換えられる。
「T」は、慣例的に使用される。
テンプレート仮引数は、複数指定できる。（ただし、必ず１つは必要。）
戻り値にテンプレート仮引数名を指定できる。
「テンプレート仮引数」は「テンプレート実引数」に代わる。

関数テンプレートを使用する際の、関数呼び出しの構文
TempFuncName<テンプレート実引数名の並び>(実引数);

#endif

#include <iostream>

template <typename T>
void	write(T var)
{
	std::cout << var << std::endl;
}

template <typename T, typename U>
void	write(T type, U var)
{
	std::cout << type << ": [" << var << "];" << std::endl;
}

int	main()
{
	write<int>(1);
	write<float>(10.5);
	write<char>('a');
	write<std::string>("abc");

	write<std::string, int>("int         ", 1);
	write<std::string, float>("float       ", 10.5);
	write<std::string, char>("char        ", 'a');
	write<std::string, std::string>("std::string", "abc");
}
