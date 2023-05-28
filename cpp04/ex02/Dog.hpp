/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/26 11:38:36 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	public:
		// CONSTRUCTER
		Dog();
		Dog(const std::string& type);
		Dog(const Dog& src);

		// OPERATOR
		Dog&				operator=(const Dog& rhs);

		// GETTER
		const Brain*		getBrain() const;
		const std::string	getBrainIdea(const unsigned int& index) const;

		// SETTER
		virtual void		setType(const std::string& type);
		void				setBrain(const Brain& brain);
		void				setBrainIdea(const std::string& idea);

		// SUBJECT FUNC
		virtual void		makeSound() const;

		// DESTRUCTER
		virtual ~Dog();

	private:
		Brain*	brain_;
};

#endif
