/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/06/01 17:13:10 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "debugMessage.hpp"
#include "color.hpp"

class ICharacter;

class AMateria {
	public:
		// CONSTRUCTER
		AMateria();
		AMateria(const std::string& type);
		AMateria(const AMateria& src);

		// OPERATOR
		AMateria&	operator=(const AMateria& rhs);

		// GETTER
		// SUBJECT FUNC
		std::string const &	getType() const; //Returns the materia type

		// SETTER
		void	setType(const std::string& type);

		// SUBJECT FUNC
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);

		// DESTRUCTER
		virtual ~AMateria();

	protected:
		std::string	type_;
};

#endif
