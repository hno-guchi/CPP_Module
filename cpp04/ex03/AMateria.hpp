/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/28 14:56:58 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "debugMessage.hpp"

class AMateria {
	protected:
		// SUBJECT ATTRIBUTE

		// MY ATTRIBUTE

	public:
		// CONSTRUCTER
		AMateria();
		AMateria(const std::string& type);
		AMateria(const AMateria& src);

		// OPERATOR
		AMateria&	operator=(const AMateria& rhs);

		// GETTER

		// SETTER

		// SUBJECT FUNC
		std::string const &	getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);

		// DESTRUCTER
		virtual ~AMateria();
};

#endif
