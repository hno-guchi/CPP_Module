/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scope.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:46:29 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/19 14:50:42 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0

Programming Place Plus C++

第８章　関数オーバーロード
https://programming-place.net/ppp/contents/cpp/language/008.html#overload

関数オーバーロードとスコープ
関数オーバーロードは、同一のスコープ内で適用される。
異なるスコープ間で、関数オーバーロードを成立させるには、using 宣言を用いる。

#endif

#include <iostream>

void	print_value(int i)
{
	std::cout << "int    : [" << i << "]" << std::endl;
}

namespace n {
	void	print_value(double d)
	{
		std::cout << "double : [" << d << "]" << std::endl;
	}

	void	func()
	{
		print_value(1);
		print_value(10.5);
	}
}

namespace n2 {
	void	print_value(double d)
	{
		std::cout << "double : [" << d << "]" << std::endl;
	}

	void	func()
	{
		using ::print_value;
		using n2::print_value;

		print_value(1);
		print_value(10.5);
	}
}

int	main()
{
	n::func();
	n2::func();
}
