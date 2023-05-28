/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/28 17:47:10 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include "debugMessage.hpp"

class ICharacter {
	public:
		// CONSTRUCTER
		ICharacter();
		ICharacter(const ICharacter& src);

		// OPERATOR
		// ICharacter&	operator=(const ICharacter& rhs);

		// GETTER

		// SETTER

		// SUBJECT FUNC
		virtual std::string const &	getName() const = 0;
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter& target) = 0;

		// DESTRUCTER
		virtual						~ICharacter() {}

	private:
		// SUBJECT ATTRIBUTE

		// MY ATTRIBUTE

};

#endif