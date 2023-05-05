/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:23:44 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/05 12:40:28 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int		zombie_count = 10;
	Zombie	*zombies = zombieHorde(zombie_count, "hnoguchi");
	if (zombies == NULL) {
		return (1);
	}
	for (int i = 0; i < zombie_count; i++) {
		std::cout << BLUE << "[" << i << "]: " << END << std::flush;
		zombies[i].announce();
	}
	delete[] zombies;
}
