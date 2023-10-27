/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:52:26 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/27 22:27:41 by hnoguchi         ###   ########.fr       */
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

static std::size_t	size_tabs(const long num)
{
	return (num < 0 ? -(num) : num);
}

static std::size_t	calculateSpan(const long left, const long right)
{
	return (size_tabs(left - right));
}

std::size_t	Span::shortestSpan() const
{
	if (this->getSize() == 0 || this->getSize() == 1) {
		throw Span::NotExistSpan();
	}
	std::size_t	span = 0;
	std::size_t	shortest = calculateSpan(this->data_[0], this->data_[1]);
	for (std::size_t i = 1; i < (this->getSize() - 1); i++) {
		if ((span = calculateSpan(this->data_[i], this->data_[i + 1])) < shortest) {
			shortest = span;
		}
	}
	return (shortest);
}

// std::size_t		Span::longestSpan()
// {
// 	if (this->getSize() == 0 || this->getSize() == 1) {
// 		throw Span::NotExistSpan();
// 	}
// 	return (0);
// }

// EXCEPTION
Span::OverSize::OverSize(const std::string& msg) : std::overflow_error(msg) {}
Span::NotExistSpan::NotExistSpan(const std::string& msg) : std::logic_error(msg) {}
