/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/31 17:08:41 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "debugMessage.hpp"
#include "ICharacter.hpp"

# define MAX_INVENTORY_SIZE 4

class Character : public ICharacter {
	public:
		// CONSTRUCTER
		// The inventory is empty at construction.
		// Your Character must have a constructor taking its name as a parameter.
		Character();
		Character(const std::string& name);
		Character(const Character& src);

		// OPERATOR
		// Any copy (using copy constructor or copy assignment operator) of a Character must be deep.
		Character&	operator=(const Character& rhs);

		// GETTER
		virtual std::string const &	getName() const;

		// SETTER

		// SUBJECT FUNC
		// They equip the Materias in the first empty slot they find.
		// This means, in this order: from slot 0 to slot 3.
		// In case they try to add a Materia to a full inventory,
		// or use/unequip an unexisting Materia, don’t do anything (but still, bugs are forbidden).
		virtual void				equip(AMateria* m);

		// The unequip() member function must NOT delete the Materia!
		// Handle the Materias your character left on the floor as you like.
		// Save the addresses before calling unequip(), or anything else, but don’t forget that you have to avoid memory leaks.
		virtual void				unequip(int idx);

		// The use(int, ICharacter&) member function will have to use the Materia at the slot[idx],
		// and pass the target parameter to the AMateria::use function.
		virtual void				use(int idx, ICharacter& target);

		// DESTRUCTER
		// Of course, the Materias must be deleted when a Character is destroyed.
		virtual ~Character();

	private:
		// SUBJECT ATTRIBUTE
		// The Character possesses an inventory of 4 slots, which means 4 Materias at most.
		AMateria*	inventory_[MAX_INVENTORY_SIZE];

		// MY ATTRIBUTE
		std::string	name_;

};

#endif
