/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:00:25 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/05 12:03:04 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	try
	{
		Zombie	*zombie = new Zombie(name);
		return (zombie);
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << e.what() << std::endl;
		return (NULL);
	}
}
