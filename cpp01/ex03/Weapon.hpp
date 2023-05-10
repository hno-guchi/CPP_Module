/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:57:26 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/10 11:01:48 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <iomanip>

# define END             "\033[0m"

# define RED             "\033[31m"
# define GREEN           "\033[32m"
# define YELLOW          "\033[33m"
# define BLUE            "\033[34m"
# define UNDERLINE       "\033[4m"

class	Weapon {
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string	&getType();
		void				setType(std::string type);

	private:
		std::string	type;
};

#endif
