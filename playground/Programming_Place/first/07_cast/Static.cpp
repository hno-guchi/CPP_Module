/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Static.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:34:45 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/18 11:53:28 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0

C++のキャストの特徴
意図を明確にする。
意図に合わないキャスト構文を使用した場合、コンパイルエラーが発生する。
ただし、dynamic_cast の場合は、実行時にエラーが発生する。

キャストの名称<キャスト後の型>(式);

static_cast
一番最初に試すと良いキャスト。
// ポインタや参照から、const, volatile を除くようなキャストはエラーとなる。
// 暗黙の型変換の際、コンパイラが出す警告を無視することができる。
// 整数型から列挙型への変換ができる。（列挙型から整数型は、暗黙の型変換）
// void pointer から、それ以外の型のポインタへの変換。
   そのポインタが保持するメモリアドレスは、変化しない。
  （様々な型のポインタからvoid pointer への変換は、暗黙の型変換）
// void pointer 以外の型同士で、型変換はできない。

// 派生クラスへのダウンキャスト。
#endif

#include <iostream>

int	main()
{
	// static_cast
	int				num_1 = 100;

	// ポインタや参照から、const, volatile を除くようなキャストはエラーとなる。
	// const int		*cp_1 = &num_1;
	// volatile int	*vp_1 = &num_1;
	// int	*p_1;
	// p_1 = static_cast<int *>(cp_1); // compile error
	// p_1 = static_cast<int *>(vp_1); // compile error

	// 暗黙の型変換の際、コンパイラが出す警告を無視することができる。
	signed char sc = static_cast<signed char>(num_1);
	float		f = static_cast<float>(num_1);
	std::cout << sc << "\n"
		<< f << std::endl;

	// 整数型から列挙型への変換ができる。（列挙型から整数型は、暗黙の型変換）
	enum Color {
		RED,
		GREEN,
		BLUE,
	};
	Color	color = static_cast<Color>(1);
	std::cout << color << std::endl;

	// void pointer から、それ以外の型のポインタへの変換。
	void	*vp = &num_1;
	int		*ip = static_cast<int *>(vp);
	std::cout << ip << "\n"
		<< *ip << std::endl;
}
