/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/25 12:33:59 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
	public:
		// CONSTRUCTER
		Cat();
		Cat(const std::string& type);
		Cat(const Cat& src);

		// OPERATOR
		Cat&	operator=(const Cat& rhs);

		// SETTER
		virtual void	setType(const std::string& type);

		// SUBJECT FUNC
		virtual void	makeSound() const;

		// DESTRUCTER
		virtual ~Cat();
};

#endif
