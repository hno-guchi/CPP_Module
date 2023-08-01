/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:25:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/08/01 09:29:28 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// CONSTRUCTER
DiamondTrap::DiamondTrap() :
	ClapTrap()
{
	ScavTrap();
	FragTrap();
	debugMessage("DiamondTrap", DEFAULT_CONSTRUCT);
}

DiamondTrap::DiamondTrap() :
{
	debugMessage("DiamondTrap", HAS_ARGS_CONSTRUCT);
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
{
	debugMessage("DiamondTrap", COPY_CONSTRUCT);
	this->operator=(src);
}

// OPERATOR
DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs)
{
	debugMessage("DiamondTrap", COPY_OPERATOR);
	return (*this);
}

// GETTER

// SETTER

// SUBJECT FUNC

// DESTRUCTER
DiamondTrap::~DiamondTrap()
{
	debugMessage("DiamondTrap", DESTRUCT);
}
