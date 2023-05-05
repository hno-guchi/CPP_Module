/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:00:25 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/05 14:53:29 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0) {
		std::cerr << "Wrong argument N." << std::endl;
		return (NULL);
	}
	try
	{
		Zombie	*zombies = new Zombie[N];

		for (int i = 0; i < N; i++) {
			zombies[i].setName(name);
		}
		return (zombies);
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << e.what() << std::endl;
		return (NULL);
	}
}
