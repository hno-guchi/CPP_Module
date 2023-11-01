/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:52:26 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/01 12:11:24 by hnoguchi         ###   ########.fr       */
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
		for (std::vector<int>::const_iterator it = rhs.getBegin(); it != rhs.getEnd(); it++) {
			this->data_.push_back(*it);
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
std::size_t	Span::getSize() const
{
	return (this->data_.size());
}

std::size_t	Span::getCapacity() const
{
	// return (this->capacity_);
	return (this->data_.capacity());
}

std::vector<int>::iterator	Span::getBegin()
{
	return (this->data_.begin());
}

std::vector<int>::const_iterator	Span::getBegin() const
{
	return (this->data_.begin());
}

std::vector<int>::iterator	Span::getEnd()
{
	return (this->data_.end());
}

std::vector<int>::const_iterator	Span::getEnd() const
{
	return (this->data_.end());
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
	for (std::vector<int>::const_iterator itr = this->getBegin() + 1; (itr + 1) != this->getEnd(); itr++) {
	
		if ((span = calculateSpan(*itr, *(itr + 1))) < shortest) {
			shortest = span;
		}
	}
	return (shortest);
}

std::size_t	Span::longestSpan() const
{
	if (this->getSize() == 0 || this->getSize() == 1) {
		throw Span::NotExistSpan();
	}
	std::size_t	span = 0;
	std::size_t	longest = calculateSpan(this->data_[0], this->data_[1]);
	for (std::vector<int>::const_iterator itr = this->getBegin() + 1; (itr + 1) != this->getEnd(); itr++) {
	
		if ((span = calculateSpan(*itr, *(itr + 1))) > longest) {
			longest = span;
		}
	}
	return (longest);
}

void	Span::fillRandomNumber()
{
	if (this->getCapacity() == this->getSize()) {
		throw Span::OverSize();
	}
	while (this->getSize() < this->getCapacity()) {
		this->addNumber(std::rand() % 10000);
	}
}

// EXCEPTION
Span::OverSize::OverSize(const std::string& msg) : std::overflow_error(msg) {}
Span::NotExistSpan::NotExistSpan(const std::string& msg) : std::logic_error(msg) {}
