/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/25 10:44:11 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	public:
		// CONSTRUCTER
		Dog();
		Dog(const std::string& type);
		Dog(const Dog& src);

		// OPERATOR
		Dog&	operator=(const Dog& rhs);

		// SUBJECT FUNC
		virtual void	makeSound() const;

		// DESTRUCTER
		virtual ~Dog();
};

#endif
