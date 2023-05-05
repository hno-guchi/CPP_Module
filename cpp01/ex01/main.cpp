/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:23:44 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/05 15:00:46 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "color.hpp"

int	main()
{
	int		zombie_count = 10;
	Zombie	*zombies = zombieHorde(zombie_count, "hnoguchi");
	if (zombies == NULL) {
		return (1);
	}

	std::cout << std::endl;;
	std::cout << GREEN << "== [HEAP] ================================" << END << std::endl;
	for (int i = 0; i < zombie_count; i++) {
		std::cout << GREEN << "[" << i << "]: " << END << std::flush;
		zombies[i].announce();
	}
	std::cout << GREEN << "==========================================" << END << std::endl;

	std::cout << std::endl;
	std::cout << WHITE << "== [DELETE] ==============================" << END << std::endl;
	delete[] zombies;
	std::cout << WHITE << "==========================================" << END << std::endl;

	std::cout << std::endl;
#ifdef LEAKS
	system("leaks -q ex01");
#endif
}
