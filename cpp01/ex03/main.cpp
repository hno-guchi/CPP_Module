/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:03:06 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/09 10:10:47 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

int main()
{
	Weapon	club = Weapon("crude spiked club");
	const std::string	type = club.getType();
	std::cout << type << std::endl;
	// {
	// 	Weapon	club = Weapon("crude spiked club");
	// 	HumanA	bob("Bob", club);

	// 	bob.attack();
	// 	club.setType("some other type of club");
	// 	bob.attack();
	// }
	// {
	// 	Weapon	club = Weapon("crude spiked club");
	// 	HumanB	jim("Jim");

	// 	jim.setWeapon(club);
	// 	jim.attack();
	// 	club.setType("some other type of club");
	// 	jim.attack();
	// }
	return (0);
}
