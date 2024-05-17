/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:13:09 by hnoguchi          #+#    #+#             */
/*   Updated: 2024/05/17 12:10:19 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename T::const_iterator	easyfind(T& container, int val) {
	return (std::find(container.begin(), container.end(), val));
}

#endif
