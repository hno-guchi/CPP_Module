/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/31 18:25:23 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MateriaSource_HPP
# define MateriaSource_HPP

#include "debugMessage.hpp"
#include "color.hpp"
#include "IMateriaSource.hpp"

# define MAX_INVENTORY_SIZE 4

class MateriaSource : public IMateriaSource {
	public:
		// CONSTRUCTER
		MateriaSource();
		MateriaSource(const std::string& type);
		MateriaSource(const MateriaSource& src);

		// OPERATOR
		MateriaSource&	operator=(const MateriaSource& rhs);

		// GETTER

		// SETTER

		// SUBJECT FUNC
		// Copies the Materia passed as a parameter and store it in memory so it can be cloned later.
		// Like the Character, the MateriaSource can know at most 4 Materias.
		// They are not necessarily unique.
		virtual void		learnMateria(AMateria* materia);

		// Returns a new Materia.
		// The latter is a copy of the Materia previously learned by the MateriaSource whose type equals the one passed as parameter.
		// Returns 0 if the type is unknown.
		virtual AMateria*	createMateria(std::string const & type);

		// DESTRUCTER
		virtual ~MateriaSource();

	private:
		// SUBJECT ATTRIBUTE
		AMateria*	inventory_[MAX_INVENTORY_SIZE];

		// MY ATTRIBUTE
		// int			storedMateriaCount;
		int			oldestIndex;
};

#endif
