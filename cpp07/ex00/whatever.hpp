/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:13:09 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/20 16:33:11 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include "color.hpp"
#include <iostream>

template <typename T>
void	swap(T& a, T& b)
{
	if (&a == &b) {
		return ;
	}
	T	temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T&	min(const T& a, const T& b)
{
	return ((a < b) ? a : b);
}

template <typename T>
const T&	max(const T& a, const T& b)
{
	return ((a <= b) ? b : a);
}

template <typename T>
void	executeTest(T a, T b)
{
	std::cout << GREEN << "+++++++++ swap() test +++++++++++" << END << std::endl;
	std::cout << "Before : a = [" << a << "] " << "b = [" << b << "]" << std::endl;
	swap(a, b);
	std::cout << "After  : a = [" << a << "] " << "b = [" << b << "]" << std::endl;
	std::cout << std::endl;

	swap(a, b);
	std::cout << GREEN << "+++++++++ min() test +++++++++++" << END << std::endl;
	std::cout << " value : a = [" << a << "] " << "b = [" << b << "]" << std::endl;
	T resultMin = min(a, b);
	std::cout << "result : [" << resultMin << "]" << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "+++++++++ max() test +++++++++++" << END << std::endl;
	std::cout << " value : a = [" << a << "] " << "b = [" << b << "]" << std::endl;
	T resultMax = max(a, b);
	std::cout << "result : [" << resultMax << "]" << std::endl;
	std::cout << std::endl;
}

#endif
