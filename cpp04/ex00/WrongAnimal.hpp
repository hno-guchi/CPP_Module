/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/25 18:53:46 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include "debugMessage.hpp"
#include "color.hpp"

class WrongAnimal {
	public:
		// CONSTRUCTER
		WrongAnimal();
		WrongAnimal(const std::string& type);
		WrongAnimal(const WrongAnimal& src);

		// OPERATOR
		WrongAnimal&	operator=(const WrongAnimal& rhs);

		// GETTER
		std::string	getType() const;

		// SETTER
		virtual void	setType(const std::string& type);

		// SUBJECT FUNC
		void	makeSound() const;

		// DESTRUCTER
		virtual ~WrongAnimal();

	protected:
		// SUBJECT ATTRIBUTE
		std::string	type_;
};

#endif
