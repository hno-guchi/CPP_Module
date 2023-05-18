/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:53:53 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/18 18:13:04 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

# define END             "\033[0m"

# define RED             "\033[31m"
# define GREEN           "\033[32m"
# define YELLOW          "\033[33m"

# define DEFAULT_CONSTRUCT_MESSAGE "Default constructor called"
# define COPY_CONSTRUCT_MESSAGE "Copy constructor called"
# define DESTRUCT_MESSAGE "Destructor called"
# define COPY_OPERATOR_MESSAGE "Copy assignment operator called"
# define GETRAWBITS_FUNC_MESSAGE "getRawBits member function called"
# define SETRAWBITS_FUNC_MESSAGE "setRawBits member function called"

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed& src);

		Fixed& operator=(const Fixed& rhs);

		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		static const int	numberOfFractionalBits_;
		int					fixedPointNumber_;
};

#endif
