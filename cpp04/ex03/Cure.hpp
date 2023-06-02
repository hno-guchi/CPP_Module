/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/06/02 16:06:59 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "debugMessage.hpp"
#include "color.hpp"
#include "AMateria.hpp"
#include "Character.hpp"

class Cure : public AMateria {
	public:
		// CONSTRUCTER
		Cure();
		Cure(const std::string& type);
		Cure(const Cure& src);

		// OPERATOR
		Cure&				operator=(const Cure& rhs);

		// GETTER

		// SETTER

		// SUBJECT FUNC
		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);

		// DESTRUCTER
		virtual ~Cure();

	private:
		// SUBJECT ATTRIBUTE
		std::string	type;

		// MY ATTRIBUTE
};

#endif
