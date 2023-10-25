/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:13:09 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/25 18:06:52 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <assert.h>
#include "color.hpp"
#include <algorithm>

template <typename T>
typename T::const_iterator	easyfind(T& container, int val)
{
	// typedef typename T::value_type	value_type;
	// static_assert(std::is_same<value_type, int>::value, "Container must have int elements");
	return (std::find(container.begin(), container.end(), val));
}

#endif
