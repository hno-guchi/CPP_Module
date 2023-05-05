/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:22:55 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/05 11:45:11 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "color.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << GREEN << "== [STACK] ===============================" << END << std::endl;
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
	std::cout << GREEN << "==========================================" << END << std::endl;

	std::cout << std::endl;
	std::cout << RED << "== [HEAP]  ===============================" << END << std::endl;
	Zombie	*heap_zombie_0 = newZombie("heap_zombie");
	if (heap_zombie_0 == NULL) {
		return (1);
	}

	// Zombie	*heap_zombie_1 = newZombie();

	Zombie	*heap_zombie_2 = newZombie("");
	if (heap_zombie_2 == NULL) {
		delete heap_zombie_0;
		return (1);
	}

	Zombie	*heap_zombie_3 = newZombie("cccccccccccccccccccc");
	if (heap_zombie_3 == NULL) {
		delete heap_zombie_0;
		delete heap_zombie_2;
		return (1);
	}
	Zombie	*heap_zombie_4 = newZombie("ddddddddddddddddddddd");
	if (heap_zombie_4 == NULL) {
		delete heap_zombie_0;
		delete heap_zombie_2;
		delete heap_zombie_3;
		return (1);
	}

	Zombie	*point;
	heap_zombie_0->announce();
	point = heap_zombie_0;
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
	std::cout << WHITE << "== [DESTRUCT] ============================" << END << std::endl;
	delete heap_zombie_0;
	// delete heap_zombie_1;
	delete heap_zombie_2;
	delete heap_zombie_3;
	delete heap_zombie_4;
	std::cout << WHITE << "==========================================" << END << std::endl;

	std::cout << std::endl;
#ifdef LEAKS
	system("leaks -q ex00");
#endif
}
