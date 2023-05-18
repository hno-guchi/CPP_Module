/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:18:05 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/18 11:46:19 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::numberOfFractionalBits = 8;

Fixed::Fixed() :
	fixedPointNumber(0)
{
	std::cout
		<< DEFAULT_CONSTRUCT_MESSAGE
		<< std::endl;
}

Fixed::Fixed(const int number) :
	fixedPointNumber(number)
{
	std::cout
		<< INT_CONSTRUCT_MESSAGE
		<< std::endl;
}

Fixed::Fixed(const float number) :
	fixedPointNumber(static_cast<int>(number))
{
	std::cout
		<< FLOAT_CONSTRUCT_MESSAGE
		<< std::endl;
}

Fixed::Fixed(const Fixed& src) :
	fixedPointNumber(src.fixedPointNumber)
{
	std::cout
		<< COPY_CONSTRUCT_MESSAGE
		<< std::endl;
}

Fixed::~Fixed()
{
	std::cout
		<< DESTRUCT_MESSAGE
		<< std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout
		<< COPY_OPERATOR_MESSAGE
		<< std::endl;
	this->fixedPointNumber = rhs.fixedPointNumber;
	return (*this);
}

// TODO
Fixed& Fixed::operator<<(const Fixed& rhs)
{
	(void)rhs;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout
		<< GETRAWBITS_FUNC_MESSAGE
		<< std::endl;
	return (this->fixedPointNumber);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout
		<< SETRAWBITS_FUNC_MESSAGE
		<< std::endl;
	this->fixedPointNumber = raw;
}

// TODO
// converts the fixed-point value to a floating-point value.
float	Fixed::toFloat(void) const
{
	return (static_cast<float>(fixedPointNumber));
}

// TODO
// converts the fixed-point value to an integer value.
int	Fixed::toInt(void) const
{
	return (fixedPointNumber);
}
