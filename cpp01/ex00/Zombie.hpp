/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:14:38 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/05 11:38:28 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

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

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
