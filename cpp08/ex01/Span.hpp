/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:33:12 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/27 17:19:02 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
private:
	std::vector<int>	data_;
	std::size_t			capacity_;
public:
	// CONSTRUCTOR
	Span();
	Span(unsigned int cap);
	// Span(const Span& src);
	// DESTRUCTOR
	~Span();
	// OPERATOR
	Span&	operator=(const Span& rhs);
	// GETTER
	const std::vector<int>&	getData() const;
	std::size_t	getSize() const;
	std::size_t	getCapacity() const;
	// SUB_FUNC
	void	addNumber(int num);
	// int		shortestSpan();
	// int		longestSpan();
	// EXCEPTION
	class OverSize : public std::overflow_error {
	public:
		OverSize(const std::string& msg = "Over size.");
	};

};

#endif
