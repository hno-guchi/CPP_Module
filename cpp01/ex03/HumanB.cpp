/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:52:43 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/09 19:20:15 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	if (name.empty() == true) {
		this->name = "John_Doe";
	}
	else if (10 < name.length()) {
		this->name = name.substr(0, 10);
	}
	else
	{
		this->name = name;
	}
	this->weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon weapon)
{
	std::string	&typeRef = const_cast<std::string&>(weapon.getType());
	// std::string	type = typeRef;
	// std::string	type = const_cast<std::string>(weapon.getType());
	std::cout << typeRef << std::endl;
	// this->weapon = new Weapon();
}

void	HumanB::attack()
{
	std::cout
		<< std::right << std::setw(10) << BLUE
		<< this->name << END
		<< std::flush;
	std::cout
		<< ": attacks with their "
		<< std::flush;
	if (this->weapon == NULL) {
		std::cout << RED << "has not weapon." << END
			<< std::endl;
	} else {
		std::cout
			<< YELLOW << this->weapon->getType() << END
			<< "."
			<< std::endl;
	}
}
