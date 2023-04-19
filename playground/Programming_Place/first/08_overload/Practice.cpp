/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Practice.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:56:30 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/19 16:10:03 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	equal(int a, int b)
{
	if (a == b)
	{
		std::cout << a << " == " << b << std::endl;
	}
	else
	{
		std::cout << a << " != " << b << std::endl;
	}
}

/*
void	equal(std::string a, std::string b)
{
	if (a == b)
	{
		std::cout << a << " == " << b << std::endl;
	}
	else
	{
		std::cout << a << " != " << b << std::endl;
	}
}
*/

void	equal(const char *a, const char *b)
{
	if (std::strcmp(a, b) == 0)
	{
		std::cout << a << " == " << b << std::endl;
	}
	else
	{
		std::cout << a << " != " << b << std::endl;
	}
}

int	main()
{
	equal(1, 1);
	equal(3, 1);
	equal("abc", "abc");
	equal("abc", "xyz");
}
