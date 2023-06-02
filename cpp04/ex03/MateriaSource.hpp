/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/06/02 16:13:14 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MateriaSource_HPP
# define MateriaSource_HPP

#include <iomanip>
#include "debugMessage.hpp"
#include "color.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

# define MAX_LEARNED_LIST_SIZE 4

class MateriaSource : public IMateriaSource {
	public:
		// CONSTRUCTER
		MateriaSource();
		MateriaSource(const std::string& type);
		MateriaSource(const MateriaSource& src);

		// OPERATOR
		MateriaSource&		operator=(const MateriaSource& rhs);

		// GETTER

		// SETTER

		// SUBJECT FUNC
		virtual void		learnMateria(AMateria* materia);
		virtual AMateria*	createMateria(std::string const & type);

		// DEBUG
		void				printLearnedList();

		// DESTRUCTER
		virtual ~MateriaSource();

	private:
		// SUBJECT ATTRIBUTE
		AMateria*	learnedList_[MAX_LEARNED_LIST_SIZE];

		// MY ATTRIBUTE
};

#endif
