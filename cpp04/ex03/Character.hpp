/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/06/01 18:33:40 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iomanip>
#include "debugMessage.hpp"
#include "ICharacter.hpp"

# define MAX_INVENTORY_SIZE 4
# define MAX_NAME_SIZE 20

class Character : public ICharacter {
	public:
		// CONSTRUCTER
		Character();
		Character(const std::string& name);
		Character(const Character& src);

		// OPERATOR
		Character&					operator=(const Character& rhs);

		// GETTER
		virtual std::string const &	getName() const;
		const AMateria*				getMateria(int index) const;

		// SETTER
		void						setName(const std::string& name);

		// SUBJECT FUNC
		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);

		// DEBUG
		void	printData() const;

		// DESTRUCTER
		virtual ~Character();

	private:
		// SUBJECT ATTRIBUTE
		std::string	name_;
		AMateria*	inventory_[MAX_INVENTORY_SIZE];

		// MY ATTRIBUTE
};

#endif
