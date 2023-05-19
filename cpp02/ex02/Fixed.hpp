/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:53:53 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/19 14:53:34 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <limits>
#include <cmath>

# define END	"\033[0m"

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"

# define DEFAULT_CONSTRUCT_MESSAGE "Default constructor called"
# define INT_CONSTRUCT_MESSAGE "Int constructor called"
# define FLOAT_CONSTRUCT_MESSAGE "Float constructor called"
# define COPY_CONSTRUCT_MESSAGE "Copy constructor called"
# define DESTRUCT_MESSAGE "Destructor called"
# define COPY_OPERATOR_MESSAGE "Copy assignment operator called"
# define GETRAWBITS_FUNC_MESSAGE "getRawBits member function called"
# define SETRAWBITS_FUNC_MESSAGE "setRawBits member function called"

class Fixed {
	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed& src);

		Fixed&		operator=(const Fixed& rhs);
		bool		operator==(const Fixed& rhs) const;
		bool		operator!=(const Fixed& rhs) const;
		bool		operator<(const Fixed& rhs) const;
		bool		operator>=(const Fixed& rhs) const;
		bool		operator>(const Fixed& rhs) const;
		bool		operator<=(const Fixed& rhs) const;
		const Fixed	operator+(const Fixed& rhs) const;
		const Fixed	operator-(const Fixed& rhs) const;
		const Fixed	operator*(const Fixed& rhs) const;
		const Fixed	operator/(const Fixed& rhs) const;
		Fixed&		operator++();
		const Fixed	operator++(int);
		Fixed&		operator--();
		const Fixed	operator--(int);

		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		static const int	numberOfFractionalBits_;
		int					fixedPointNumber_;
};

enum eColor {
	green,
	yellow,
	red,
	NOT
};

#endif
