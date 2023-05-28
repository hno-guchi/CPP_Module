/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/28 15:19:05 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "debugMessage.hpp"

class Cure : public AMateria {
	public:
		// CONSTRUCTER
		Cure();
		Cure(const std::string& type);
		Cure(const Cure& src);

		// OPERATOR
		Cure&	operator=(const Cure& rhs);

		// GETTER

		// SETTER

		// SUBJECT FUNC
		virtual AMateria*	clone() const;
		// "* heals <name>’s wounds *"
		virtual void		use(ICharacter& target);

		// DESTRUCTER
		virtual ~Cure();

	private:
		// SUBJECT ATTRIBUTE
		std::string	type;

		// MY ATTRIBUTE

};

#endif
