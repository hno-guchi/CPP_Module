/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:19:15 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/05 14:49:09 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie():
	name("")
{
}

void	Zombie::setName(std::string name)
{
	if (name.empty() == true) {
		this->name = "John_Doe";
	}
	else if (20 < name.length()) {
		this->name = name.substr(0, 20);
	}
	else {
		this->name = name;
	}
}

const std::string	&Zombie::getName()
{
	return (this->name);
}

void	Zombie::announce()
{
	std::string	message("BraiiiiiiinnnzzzZ...");
	std::cout << std::right << std::setw(20)
		<< this->getName() << ": " << message
		<< std::endl;
}

Zombie::~Zombie()
{
	std::cout << std::right << std::setw(20)
		<< this->getName() << ": Call Destructor." << std::endl;
}
