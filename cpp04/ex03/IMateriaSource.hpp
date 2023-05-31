/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/31 11:23:19 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "debugMessage.hpp"

// In a nutshell, your MateriaSource must be able to learn "templates" of Materias to create them when needed.
// Then, you will be able to generate a new Materia using just a string that identifies its type.
class ImateriaSource {
	public:
		// CONSTRUCTER
		// ImateriaSource();
		// ImateriaSource(const std::string& type);
		// ImateriaSource(const ImateriaSource& src);

		// OPERATOR
		// ImateriaSource&	operator=(const ImateriaSource& rhs);

		// GETTER

		// SETTER

		// SUBJECT FUNC
		// Copies the Materia passed as a parameter and store it in memory so it can be cloned later.
		// Like the Character, the MateriaSource can know at most 4 Materias.
		// They are not necessarily unique.
		virtual void		learnMateria(AMateria*) = 0;


		// Returns a new Materia.
		// The latter is a copy of the Materia previously learned by the MateriaSource whose type equals the one passed as parameter.
		// Returns 0 if the type is unknown.
		virtual AMateria*	createMateria(std::string const & type) = 0;

		// DESTRUCTER
		virtual	~IMateriaSource() {}

	// private:
		// SUBJECT ATTRIBUTE

		// MY ATTRIBUTE

};

#endif
