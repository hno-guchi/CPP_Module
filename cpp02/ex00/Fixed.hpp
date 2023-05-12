/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:53:53 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/12 11:24:53 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed& src);
		~Fixed();

		Fixed& operator=(const Fixed& rhs);



	private:
};

#endif
