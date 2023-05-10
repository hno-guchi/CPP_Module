/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:03:06 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/10 11:07:16 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon	clubA = Weapon("crude spiked clubA");
	HumanA	bob("Bob", clubA);
	bob.attack();

	clubA.setType("some other type of clubA");
	bob.attack();

	// Compile error
	// HumanB	B1();
	// Segmentation fault
	// HumanB	jim(NULL);

	Weapon	clubB = Weapon("crude spiked clubB");
	HumanB	jim("Jim");
	jim.setWeapon(clubB);
	jim.attack();

	clubB.setType("some other type of clubB");
	jim.attack();
#ifdef LEAKS
	system("leaks -q ex03");
#endif // LEAKS
	return (0);
}
