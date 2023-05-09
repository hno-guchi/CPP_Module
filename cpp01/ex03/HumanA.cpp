/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:52:43 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/09 17:56:17 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :
	name(name), weapon(weapon)
{
	if (name.empty() == true) {
		this->name = "John_Doe";
	}
	else if (10 < name.length()) {
		this->name = name.substr(0, 10);
	}
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::cout
		<< std::right << std::setw(10) << GREEN
		<< this->name << END
		<< std::flush;
	std::cout
		<< ": attacks with their "
		<< std::flush;
	std::cout
		<< RED << this->weapon.getType() << END
		<< "."
		<< std::endl;
}
