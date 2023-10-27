/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:52:26 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/26 14:23:35 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "debugMessage.hpp"
#include "color.hpp"

// CONSTRUCTOR
Span::Span() :
	capacity_(1), size_(1)
{
	debugMessage("Span", DEFAULT_CONSTRUCT);
	this->data_[0] = 0;
}

Span::Span(unsigned int cap) :
	capacity_(cap), size_(0)
{
	debugMessage("Span", HAS_ARG_CONSTRUCT);
	this->data_[0] = 0;
	try {
		for (std::size_t i = 0; i < cap; i++) {
			this->data_.push_back(0);
		}
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
}

Span::Span(const Span& src)
{
	debugMessage("Span", COPY_CONSTRUCT);
}

// DESTRUCTOR
Span::~Span()
{
	debugMessage("Span", DESTRUCT);
}

// OPERATOR
Span&	Span::operator=(const Span& rhs)
{
	debugMessage("Span", COPY_OPERATOR);
}

// SUB_FUNC
void	Span::addNumber(int num)
{
	(void)num;
}

int		Span::shortestSpan()
{
	return (0);
}

int		Span::longestSpan()
{
	return (0);
}

