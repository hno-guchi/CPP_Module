/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:05:13 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/24 18:43:19 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>
#include "color.hpp"

template <typename T>
class Array {
private:
	std::size_t	size_;
	T*			data_;
public:
	// CONSTRUCTOR
	Array();
	Array(const unsigned int n);
	Array(const Array& src);
	// DESTRUCTOR
	~Array();
	// OPERATOR
	Array&	operator=(const Array<T>& rhs);
	T	operator[](std::size_t index) const;
	T&	operator[](std::size_t index);
	// GETTER
	// SETTER
	// SUB FUNC
	std::size_t	size() const;
};

#include "Array.tpp"

#endif
