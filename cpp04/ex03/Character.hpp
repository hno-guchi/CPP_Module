/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/28 17:49:40 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "debugMessage.hpp"

class Character : public ICharacter {
	public:
		// CONSTRUCTER
		Character();
		Character(const std::string& type);
		Character(const Character& src);

		// OPERATOR
		Character&	operator=(const Character& rhs);

		// GETTER

		// SETTER

		// SUBJECT FUNC

		// DESTRUCTER
		virtual ~Character();

	private:
		// SUBJECT ATTRIBUTE

		// MY ATTRIBUTE

};

#endif
