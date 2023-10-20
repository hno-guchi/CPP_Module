/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:08:01 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/20 14:56:18 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T* addr, const std::size_t size, void (*func)(T&))
{
	if (addr == NULL || func == NULL) {
		return ;
	}
	for (std::size_t i = 0; i < size; i++) {
		func(addr[i]);
	}
}

template <typename T>
void	iter(const T* addr, const std::size_t size, void (*func)(const T*))
{
	if (addr == NULL || func == NULL) {
		return ;
	}
	for (std::size_t i = 0; i < size; i++) {
		func(&(addr[i]));
	}
}

template <typename T>
void	PrintAryData(T* ary, std::size_t size)
{
	std::cout << "value : " << std::flush;
	for (std::size_t i = 0; i < size; i++) {
		std::cout << " ["<< ary[i] << "] " << std::flush;
	}
	std::cout << std::endl;
}

#endif
