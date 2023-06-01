/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/06/01 18:35:21 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "debugMessage.hpp"
#include "color.hpp"
#include "AMateria.hpp"
#include "Character.hpp"

class Ice : public AMateria {
	public:
		// CONSTRUCTER
		Ice();
		Ice(const std::string& type);
		Ice(const Ice& src);

		// OPERATOR
		Ice&				operator=(const Ice& rhs);

		// GETTER

		// SETTER

		// SUBJECT FUNC
		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);

		// DESTRUCTER
		virtual ~Ice();

	private:
		// SUBJECT ATTRIBUTE
		std::string	type;

		// MY ATTRIBUTE
};

#endif
