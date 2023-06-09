/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:18:05 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/25 11:26:53 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::numberOfFractionalBits_ = 8;

static void	writeMessage(std::string message)
{
	std::cout << message << std::endl;
}

Fixed::Fixed() :
	fixedPointNumber_(0)
{
	writeMessage(DEFAULT_CONSTRUCT_MESSAGE);
}

Fixed::Fixed(const int number) :
	fixedPointNumber_(number * (1 << this->numberOfFractionalBits_))
{
	writeMessage(INT_CONSTRUCT_MESSAGE);
}

Fixed::Fixed(const float number) :
	fixedPointNumber_(static_cast<int>(number * (1 << this->numberOfFractionalBits_)))
{
	writeMessage(FLOAT_CONSTRUCT_MESSAGE);
}

Fixed::Fixed(const Fixed& src)
{
	writeMessage(COPY_CONSTRUCT_MESSAGE);
	this->operator=(src);
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	writeMessage(COPY_OPERATOR_MESSAGE);
	this->fixedPointNumber_ = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return (this->fixedPointNumber_ == rhs.fixedPointNumber_);
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return (!(*this == rhs));
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return (this->fixedPointNumber_ < rhs.fixedPointNumber_);
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return (!(*this < rhs));
}

bool	Fixed::operator>(const Fixed& rhs) const
{
	return (this->fixedPointNumber_ > rhs.fixedPointNumber_);
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return (!(*this > rhs));
}

const Fixed	Fixed::operator+(const Fixed& rhs) const
{
	Fixed	temp;

	temp.fixedPointNumber_ = this->fixedPointNumber_ + rhs.fixedPointNumber_;
	return (temp);
}

const Fixed	Fixed::operator-(const Fixed& rhs) const
{
	Fixed	temp;

	temp.fixedPointNumber_ = this->fixedPointNumber_ - rhs.fixedPointNumber_;
	return (temp);
}

const Fixed	Fixed::operator*(const Fixed& rhs) const
{
	Fixed	temp;

	temp.fixedPointNumber_ = this->fixedPointNumber_ * rhs.fixedPointNumber_;
	temp.fixedPointNumber_ = temp.fixedPointNumber_ / (1 << this->numberOfFractionalBits_);
	return (temp);
}

const Fixed	Fixed::operator/(const Fixed& rhs) const
{
	Fixed	temp;

	temp.fixedPointNumber_ = this->fixedPointNumber_ / rhs.fixedPointNumber_;
	temp.fixedPointNumber_ = temp.fixedPointNumber_ * (1 << this->numberOfFractionalBits_);
	return (temp);
}

Fixed&	Fixed::operator++()
{
	++this->fixedPointNumber_;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	const Fixed	old(*this);

	++(*this);
	return (old);
}

Fixed&	Fixed::operator--()
{
	--this->fixedPointNumber_;
	return (*this);
}

const Fixed	Fixed::operator--(int)
{
	const Fixed	old(*this);

	--(*this);
	return (old);
}

Fixed::~Fixed()
{
	writeMessage(DESTRUCT_MESSAGE);
}


Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (b.getRawBits() < a.getRawBits()) {
		return (b);
	}
	return (a);
}

Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (b.getRawBits() < a.getRawBits()) {
		return (const_cast<Fixed&>(b));
	}
	return (const_cast<Fixed&>(a));
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits()) {
		return (b);
	}
	return (a);
}

Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits()) {
		return (const_cast<Fixed&>(b));
	}
	return (const_cast<Fixed&>(a));
}

int	Fixed::getRawBits(void) const
{
	writeMessage(GETRAWBITS_FUNC_MESSAGE);
	return (this->fixedPointNumber_);
}

void	Fixed::setRawBits(int const raw)
{
	writeMessage(SETRAWBITS_FUNC_MESSAGE);
	this->fixedPointNumber_ = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->fixedPointNumber_) / (1 << this->numberOfFractionalBits_));
}

int	Fixed::toInt(void) const
{
	return (this->fixedPointNumber_ / (1 << this->numberOfFractionalBits_));
}

std::ostream&	operator<<(std::ostream& lhs, const Fixed& rhs)
{
	lhs << rhs.toFloat();
	return (lhs);
}
