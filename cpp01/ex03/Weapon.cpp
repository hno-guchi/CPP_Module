/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:10:58 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/09 19:19:13 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	if (type.empty() == true) {
		this->type = "Default_Weapon";
	}
	else if (100 < type.length()) {
		this->type = type.substr(0, 100);
	}
	else
	{
		this->type = type;
	}
}

Weapon::~Weapon()
{
	std::cout << "Weapon: Call Destructor." << std::endl;
}

const std::string	&Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	if (type.empty() == true) {
		std::cout
			<< RED << "Weapon: Not type." << END
			<< std::endl;
		return ;
	}
	else if (100 < type.length()) {
		this->type = type.substr(0, 100);
	}
	else
	{
		this->type = type;
	}
}

#ifdef WEAPON
int	main()
{
	Weapon	weapon("");

	std::cout << weapon.getType() << std::endl;

	weapon.setType("");
	std::cout << weapon.getType() << std::endl;

	weapon.setType("crude spiked club");
	std::cout << weapon.getType() << std::endl;

	weapon.setType("some other type of club");
	std::cout << weapon.getType() << std::endl;
#ifdef LEAKS
	system("leaks -q weapon");
#endif //LEAKS
}
#endif //WEAPON
