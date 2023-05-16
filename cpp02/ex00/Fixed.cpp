/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:18:05 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/16 19:30:32 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout
		<< DEFAULT_CONSTRUCT_MESSAGE
		<< std::endl;
}

Fixed::Fixed(const Fixed& src)
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
