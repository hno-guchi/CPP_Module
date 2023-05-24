/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:18:05 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/24 16:57:46 by hnoguchi         ###   ########.fr       */
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

Fixed::Fixed(const Fixed& src) :
	fixedPointNumber_(src.fixedPointNumber_)
{
	writeMessage(COPY_CONSTRUCT_MESSAGE);
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	writeMessage(COPY_OPERATOR_MESSAGE);
	this->fixedPointNumber_ = rhs.fixedPointNumber_;
	return (*this);
}

Fixed::~Fixed()
{
	writeMessage(DESTRUCT_MESSAGE);
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
	return (static_cast<float>(this->fixedPointNumber_) / (1 << 8));
}

int	Fixed::toInt(void) const
{
	return (this->fixedPointNumber_ / (1 << 8));
}

std::ostream&	operator<<(std::ostream& lhs, const Fixed& rhs)
{
	lhs << rhs.toFloat();
	return (lhs);
}
