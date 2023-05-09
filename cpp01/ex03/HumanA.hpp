/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:04:46 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/09 17:37:54 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iomanip>

class	HumanA {
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	attack();

	private:
		std::string	name;
		Weapon		&weapon;
};

#endif
