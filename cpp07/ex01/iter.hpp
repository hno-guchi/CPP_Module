/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:08:01 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/19 16:04:41 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T1, typename T2, typename T3>
void	iter(T1* addr, T2 size, T3 (*func)(T1*))
{
	if (addr == NULL || func == NULL) {
		return ;
	}
	for (std::size_t i = 0; i < static_cast<size_t>(size); i++) {
		func(&(addr[i]));
	}
}

#endif
