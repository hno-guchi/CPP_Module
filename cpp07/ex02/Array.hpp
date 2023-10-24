/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:05:13 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/24 19:14:52 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>
#include <stdexcept>
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
	T	operator[](const unsigned int index) const;
	T&	operator[](const unsigned int index);
	// GETTER
	// SETTER
	// SUB FUNC
	std::size_t	size() const;
	// EXCEPTION
	class OutOfRange : public std::out_of_range {
	public:
		OutOfRange(const std::string& msg = "index is out of range.");
	};
};

#include "Array.tpp"

#endif
