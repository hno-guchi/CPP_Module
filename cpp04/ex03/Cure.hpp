/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/31 12:36:17 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "debugMessage.hpp"
#include "color.hpp"
#include "AMateria.hpp"
// #include "Character.hpp"

// Implement the Materias concrete classes Ice and Cure.
// Use their name in lowercase ("ice" for Ice, "cure" for Cure) to set their types.
// Of course, their member function clone() will return a new instance of the same type (i.e., if you clone an Ice Materia, you will get a new Ice Materia).
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
		// While assigning a Materia to another, copying the type doesn’t make sense.
		virtual AMateria*	clone() const;

		// The use(ICharacter&) member function will display
		// "* heals <name>’s wounds *"
		// <name> is the name of the Character passed as parameter. Don’t print the angle brackets (< and >).
		// virtual void		use(ICharacter& target);
		virtual void		use();

		// DESTRUCTER
		virtual ~Cure();

	private:
		// SUBJECT ATTRIBUTE
		std::string	type;

		// MY ATTRIBUTE

};

#endif
