/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:22:55 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/05 14:51:12 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "color.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << GREEN << "== [STACK] ===============================" << END << std::endl;

	Zombie	stack_zombie_0;
	stack_zombie_0.setName("stack_zombie");
	stack_zombie_0.announce();

	// Zombie	stack_zombie_1;
	// stack_zombie_1();
	// stack_zombie_1.announce();

	Zombie	stack_zombie_2;
	stack_zombie_2.setName("");
	stack_zombie_2.announce();

	Zombie	stack_zombie_3;
	stack_zombie_3.setName("aaaaaaaaaaaaaaaaaaaa");
	stack_zombie_3.announce();

	Zombie	stack_zombie_4;
	stack_zombie_4.setName("bbbbbbbbbbbbbbbbbbbbb");
	stack_zombie_4.announce();

	std::cout << GREEN << "==========================================" << END << std::endl;

	std::cout << std::endl;
	std::cout << RED << "== [HEAP]  ===============================" << END << std::endl;
	Zombie	*heap_zombie_0 = newZombie("heap_zombie");
	Zombie	*point = heap_zombie_0;
	// Zombie	*heap_zombie_1 = newZombie();
	Zombie	*heap_zombie_2 = newZombie("");
	Zombie	*heap_zombie_3 = newZombie("cccccccccccccccccccc");
	Zombie	*heap_zombie_4 = newZombie("ddddddddddddddddddddd");
	if (heap_zombie_0 == NULL || heap_zombie_2 == NULL || heap_zombie_3 == NULL || heap_zombie_4 == NULL) {
		delete heap_zombie_4;
		delete heap_zombie_3;
		delete heap_zombie_2;
		delete heap_zombie_0;
		return (1);
	}

	heap_zombie_0->announce();
	point->announce();
	// heap_zombie_1->announce();
	heap_zombie_2->announce();
	heap_zombie_3->announce();
	heap_zombie_4->announce();
	std::cout << RED << "==========================================" << END << std::endl;

	std::cout << std::endl;
	std::cout << YELLOW << "== [RANDOM] ==============================" << END << std::endl;
	randomChump("randomChump");
	std::cout << YELLOW << "==========================================" << END << std::endl;

	std::cout << std::endl;
	std::cout << WHITE << "== [DELETE] ==============================" << END << std::endl;
	delete heap_zombie_4;
	delete heap_zombie_3;
	delete heap_zombie_2;
	// delete heap_zombie_1;
	delete heap_zombie_0;
	std::cout << WHITE << "==========================================" << END << std::endl;

	std::cout << std::endl;
#ifdef LEAKS
	system("leaks -q ex00");
#endif
}
