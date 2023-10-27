/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:52:26 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/27 18:10:29 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "debugMessage.hpp"
#include "color.hpp"

// CONSTRUCTOR
Span::Span() :
	capacity_(0)
{
	debugMessage("Span", DEFAULT_CONSTRUCT);
}

Span::Span(unsigned int cap) :
	capacity_(cap)
{
	debugMessage("Span", HAS_ARG_CONSTRUCT);
	try {
		this->data_.reserve(cap);
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
		this->capacity_ = 0;
	}
}

Span::Span(const Span& src)
{
	debugMessage("Span", COPY_CONSTRUCT);
	this->operator=(src);
}

// DESTRUCTOR
Span::~Span()
{
	debugMessage("Span", DESTRUCT);
}

// OPERATOR
Span&	Span::operator=(const Span& rhs)
{
	if (this == &rhs) {
		return (*this);
	}
	debugMessage("Span", COPY_OPERATOR);
	std::vector<int>().swap(this->data_);
	try {
		this->data_.reserve(rhs.getCapacity());
		for (std::size_t i = 0; i < rhs.getSize(); i++) {
			this->data_.push_back(rhs.getData()[i]);
		}
		this->capacity_ = rhs.getCapacity();
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
		this->capacity_ = 0;
	}
	return (*this);
}

// GETTER
const std::vector<int>&	Span::getData() const
{
	return (this->data_);
}

std::size_t	Span::getSize() const
{
	return (this->data_.size());
}

std::size_t	Span::getCapacity() const
{
	return (this->capacity_);
}

// SUB_FUNC
void	Span::addNumber(int num)
{
	if (this->getCapacity() == this->getSize()) {
		throw Span::OverSize();
	}
	this->data_.push_back(num);
}

// int		Span::shortestSpan()
// {
// 	return (0);
// }

// int		Span::longestSpan()
// {
// 	return (0);
// }

Span::OverSize::OverSize(const std::string& msg) : std::overflow_error(msg) {}
