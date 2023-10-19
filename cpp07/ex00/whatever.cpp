/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:13:09 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/19 10:57:33 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

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

// template <typename T>
// T	min(T a, T b);
// 
// template <typename T>
// T	max(T a, T b);

