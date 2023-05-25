/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/25 19:01:29 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		// CONSTRUCTER
		WrongCat();
		WrongCat(const std::string& type);
		WrongCat(const WrongCat& src);

		// OPERATOR
		WrongCat&	operator=(const WrongCat& rhs);

		// SETTER
		virtual void	setType(const std::string& type);

		// SUBJECT FUNC
		void	makeSound() const;

		// DESTRUCTER
		virtual ~WrongCat();
};

#endif
