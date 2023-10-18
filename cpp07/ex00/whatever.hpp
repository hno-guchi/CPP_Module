/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:13:09 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/18 16:33:12 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

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

#endif
