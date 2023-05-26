/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/26 11:36:54 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	public:
		// CONSTRUCTER
		Cat();
		Cat(const std::string& type);
		Cat(const Cat& src);

		// OPERATOR
		Cat&	operator=(const Cat& rhs);

		// GETTER
		const Brain*		getBrain() const;
		const std::string	getBrainIdea(const unsigned int& index) const;

		// SETTER
		virtual void	setType(const std::string& type);
		void			setBrainIdea(const std::string& idea);

		// SUBJECT FUNC
		virtual void	makeSound() const;

		// DESTRUCTER
		virtual ~Cat();

	private:
		Brain*	brain_;
};

#endif
