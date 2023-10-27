/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:33:12 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/26 14:23:37 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>

class Span {
private:
	std::size_t			capacity_;
	std::size_t			size_;
	std::vector<int>	data_;

public:
	// CONSTRUCTOR
	Span();
	Span(unsigned int cap);
	Span(const Span& src);
	// DESTRUCTOR
	~Span();
	// OPERATOR
	Span&	operator=(const Span& rhs);
	// SUB_FUNC
	void	addNumber(int num);
	int		shortestSpan();
	int		longestSpan();
};

#endif
