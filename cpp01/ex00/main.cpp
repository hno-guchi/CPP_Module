/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:22:55 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/04 18:46:48 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "\n===== [STACK] ======" << std::endl;
	Zombie	stack_zombie_0("stack_zombie");
	// Zombie	stack_zombie_1();
	Zombie	stack_zombie_2("");
	Zombie	stack_zombie_3("aaaaaaaaaaaaaaaaaaaa");
	Zombie	stack_zombie_4("bbbbbbbbbbbbbbbbbbbbb");

	stack_zombie_0.announce();
	// stack_zombie_1.announce();
	stack_zombie_2.announce();
	stack_zombie_3.announce();
	stack_zombie_4.announce();
	std::cout << "====================" << std::endl;

	std::cout << "\n===== [HEAP]  ======" << std::endl;
	Zombie	*heap_zombie_0 = newZombie("heap_zombie");
	// Zombie	*heap_zombie_1 = newZombie();
	Zombie	*heap_zombie_2 = newZombie("");
	Zombie	*heap_zombie_3 = newZombie("cccccccccccccccccccc");
	Zombie	*heap_zombie_4 = newZombie("ddddddddddddddddddddd");

	Zombie	*point;
	heap_zombie_0->announce();
	point = heap_zombie_0;
	point->announce();

	// heap_zombie_1->announce();
	heap_zombie_2->announce();
	heap_zombie_3->announce();
	heap_zombie_4->announce();
	std::cout << "====================" << std::endl;

	// randomChump("randomChump");

	delete heap_zombie_0;
	// delete heap_zombie_1;
	delete heap_zombie_2;
	delete heap_zombie_3;
	delete heap_zombie_4;
}
