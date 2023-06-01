/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/06/01 12:26:51 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "debugMessage.hpp"
#include "AMateria.hpp"

class IMateriaSource {
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
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;

		// DESTRUCTER
		virtual	~IMateriaSource() {}

	// private:
		// SUBJECT ATTRIBUTE

		// MY ATTRIBUTE

};

#endif
