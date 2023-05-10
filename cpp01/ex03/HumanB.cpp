/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:52:43 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/10 10:59:38 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) :
	name(name)
{
	if (name.empty() == true) {
		this->name = "John_Doe";
	}
	else if (10 < name.length()) {
		this->name = name.substr(0, 10);
	}
	else {
		this->name = name;
	}
	this->weapon = NULL;
}

HumanB::~HumanB()
{
	delete this->weapon;
	std::cout
		<< std::right << std::setw(10) << UNDERLINE
		<< this->name << END
		<< std::flush;
	std::cout
		<< ": Call Destructor." << std::endl;
}

void	HumanB::setWeapon(Weapon weapon)
{
	// std::string	&typeRef = const_cast<std::string&>(weapon.getType());
	// std::string	type = typeRef;
	try {
		this->weapon = new Weapon(const_cast<std::string&>(weapon.getType()));
	}
	catch (const std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
	}
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
		std::cout << "has not weapon." << std::endl;
	}
	else {
		std::cout
			<< RED << this->weapon->getType() << END
			<< "."
			<< std::endl;
	}
}
