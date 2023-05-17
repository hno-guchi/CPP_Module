/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:18:05 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/17 12:07:15 by hnoguchi         ###   ########.fr       */
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

// Fixed::Fixed(const float number)
// {
// 	std::cout
// 		<< FLOAT_CONSTRUCT_MESSAGE
// 		<< std::endl;
// }

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
