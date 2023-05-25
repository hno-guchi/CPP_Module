/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/25 12:33:11 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "debugMessage.hpp"
#include "color.hpp"

class Animal {
	public:
		// CONSTRUCTER
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& src);

		// OPERATOR
		Animal&	operator=(const Animal& rhs);

		// GETTER
		std::string	getType() const;

		// SETTER
		virtual void	setType(const std::string& type);

		// SUBJECT FUNC
		virtual void	makeSound() const;

		// DESTRUCTER
		virtual ~Animal();

	protected:
		// SUBJECT ATTRIBUTE
		std::string	type_;
};

#endif
