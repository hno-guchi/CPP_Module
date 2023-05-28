/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/28 15:18:53 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "debugMessage.hpp"

class Ice : public AMateria {
	public:
		// CONSTRUCTER
		Ice();
		Ice(const std::string& type);
		Ice(const Ice& src);

		// OPERATOR
		Ice&	operator=(const Ice& rhs);

		// GETTER

		// SETTER

		// SUBJECT FUNC
		virtual AMateria*	clone() const;
		// "* shoots an ice bolt at <name> *"
		virtual void		use(ICharacter& target);

		// DESTRUCTER
		virtual ~Ice();

	private:
		// SUBJECT ATTRIBUTE
		std::string	type;

		// MY ATTRIBUTE

};

#endif
