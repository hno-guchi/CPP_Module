/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:11:30 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/20 17:49:23 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Array.hpp"
#include "debugMessage.hpp"

// CONSTRUCTOR
template <typename T>
Array<T>::Array() :
	capacity_(1)
{
	debugMessage("Array", DEFAULT_CONSTRUCT);
	try {
		this->data_ = new T();
		this->data_[0] = 0;
	}
	catch (std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
}

// template <typename T>
// Array<T>::Array(const unsigned int n)
// {
// 	debugMessage("Array", HAS_ARG_CONSTRUCT);
// 	(void)n;
// }
// 
// template <typename T>
// Array<T>::Array(const Array& src)
// {
// 	debugMessage("Array", COPY_CONSTRUCT);
// 	(void)src;
// }
// 
// // OPERATOR
// template <typename T>
// Array<T>&	Array<T>::operator=(const Array& rhs)
// {
// 	debugMessage("Array", COPY_OPERATOR);
// 	(void)rhs;
// }
// 
// template <typename T>
// T	Array<T>::operator[](std::size_t index) const
// {
// 	debugMessage("Array", GET_INDEX_OPERATOR);
// 	return (this->data_[index]);
// }
// 
// template <typename T>
// T&	Array<T>::operator[](std::size_t index)
// {
// 	debugMessage("Array", SET_INDEX_OPERATOR);
// 	return (this->data_[index]);
// }
 
template <typename T>
Array<T>::~Array()
{
	debugMessage("Array", DESTRUCT);
	delete[] this->data_;
}
 
// template <typename T>
// std::size_t	Array<T>::size() const
// {
// 	return (this->capacity_);
// }
