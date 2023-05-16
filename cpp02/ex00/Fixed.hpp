/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:53:53 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/16 19:26:18 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

# define DEFAULT_CONSTRUCT_MESSAGE "Default constructor called"
# define COPY_CONSTRUCT_MESSAGE "Copy constructor called"
# define COPY_OPERATOR_MESSAGE "Copy assignment operator called"
# define GETRAWBITS_FUNC_MESSAGE "getRawBits member function called"
# define SETRAWBITS_FUNC_MESSAGE "setRawBits member function called"
# define DESTRUCT_MESSAGE "Destructor called"

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed& src);
		~Fixed();

		Fixed& operator=(const Fixed& rhs);

	private:
};

#endif
