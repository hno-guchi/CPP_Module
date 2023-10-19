/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:11:30 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/19 18:22:04 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "debugMessage.hpp"

template <typename T>
Array<T>::Array() :
	capacity_(1), data_(new T[1])
{
	debugMessage("Array", DEFAULT_CONSTRUCT);
}

template <typename T>
Array<T>::~Array()
{
	debugMessage("Array", DESTRUCT);
}
