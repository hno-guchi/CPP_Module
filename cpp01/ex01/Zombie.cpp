/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:19:15 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/04 18:28:58 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name):
	name(name)
{
	if (name.empty() == true) {
		this->name = "John_Doe";
	}
	if (20 < name.length()) {
		this->name = name.substr(0, 20);
	}
}

void	Zombie::announce()
{
	std::string	message("BraiiiiiiinnnzzzZ...");
	std::cout << std::right << std::setw(20)
		<< this->name << ": " << message
		<< std::endl;
}

Zombie::~Zombie()
{
	std::cout << std::right << std::setw(20)
		<< this->name << ": Call Destructor." << std::endl;
}
