/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:14:38 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/05 12:31:44 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include "color.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <new>

class	Zombie
{
public:
	Zombie(std::string name);
	void	announce();
	~Zombie();

private:
	std::string	name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
