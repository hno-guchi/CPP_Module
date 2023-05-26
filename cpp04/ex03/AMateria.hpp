/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/26 17:33:03 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

class AMateria {
	public:
		// CONSTRUCTER
		AMateria();
		AMateria(const std::string& type);
		AMateria(const AMateria& src);

		// OPERATOR
		AMateria&	operator=(const AMateria& rhs);

		// GETTER
		std::string const&	getType() const; // Returns the materia type

		// SETTER

		// SUBJECT FUNC
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);

		// DESTRUCTER
		virtual ~AMateria();

	protected:
		// SUBJECT ATTRIBUTE

		// MY ATTRIBUTE

};

#endif
