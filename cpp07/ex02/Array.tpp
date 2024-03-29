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

#include "debugMessage.hpp"

// CONSTRUCTOR
template <typename T>
Array<T>::Array() :
	size_(1), data_(NULL)
{
	debugMessage("Array", DEFAULT_CONSTRUCT);
	try {
		this->data_ = new T[1]();
	}
	catch (std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
		this->size_ = 0;
	}
}

template <typename T>
Array<T>::Array(const unsigned int n) :
	size_(n), data_(NULL)
{
	debugMessage("Array", HAS_ARG_CONSTRUCT);
	if (n == 0) {
		throw Array::InvalidArgs();
	}
	try {
		this->data_ = new T[n]();
	}
	catch (std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
		this->size_ = 0;
	}
}

template <typename T>
Array<T>::Array(const Array& src) :
	size_(src.size()), data_(NULL)
{
	debugMessage("Array", COPY_CONSTRUCT);
	this->operator=(src);
}

// OPERATOR
template <typename T>
Array<T>&	Array<T>::operator=(const Array& rhs)
{
	// debugMessage("Array", COPY_OPERATOR);
	if (this == &rhs) {
		return (*this);
	}
	try {
		delete [] this->data_;
		this->data_ = new T[rhs.size()]();
		for (std::size_t i = 0; i < rhs.size(); i++) {
			this->data_[i] = rhs.data_[i];
		}
		this->size_ = rhs.size();
	}
	catch (std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
		this->size_ = 0;
	}
	return (*this);
}

template <typename T>
T	Array<T>::operator[](const unsigned int index) const
{
	// debugMessage("Array", GET_INDEX_OPERATOR);
	if (this->size() <= index) {
		throw Array::OutOfRange();
	}
	return (this->data_[index]);
}

template <typename T>
T&	Array<T>::operator[](const unsigned int index)
{
	// debugMessage("Array", SET_INDEX_OPERATOR);
	if (this->size() <= index) {
		throw Array::OutOfRange();
	}
	return (this->data_[index]);
}

template <typename T>
Array<T>::~Array()
{
	debugMessage("Array", DESTRUCT);
	delete[] this->data_;
}

// SUB_FUNC
template <typename T>
std::size_t	Array<T>::size() const
{
	return (this->size_);
}

// EXCEPTION
template <typename T>
Array<T>::OutOfRange::OutOfRange(const std::string& msg) : std::out_of_range(msg) {}

template <typename T>
Array<T>::InvalidArgs::InvalidArgs(const std::string& msg) : std::invalid_argument(msg) {}
