/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:43:00 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/31 19:11:03 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"


template <typename T>
typename std::deque<T>::iterator	MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename std::deque<T>::const_iterator	MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename std::deque<T>::iterator	MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename std::deque<T>::const_iterator	MutantStack<T>::end() const
{
	return (this->c.end());
}
