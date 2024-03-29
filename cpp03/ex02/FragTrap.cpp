/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:58:05 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/08/01 10:13:23 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() :
	ClapTrap()
{
	this->setName("");
	this->setHitPoint(FT_DEFAULT_HIT_POINT);
	this->setEnergyPoint(FT_DEFAULT_ENERGY_POINT);
	this->setAttackPoint(FT_DEFAULT_ATTACK_POINT);
	debugMessage("FragTrap", DEFAULT_CONSTRUCT);
}

FragTrap::FragTrap(const std::string& name) :
	ClapTrap(name)
{
	this->setName(name);
	this->setHitPoint(FT_DEFAULT_HIT_POINT);
	this->setEnergyPoint(FT_DEFAULT_ENERGY_POINT);
	this->setAttackPoint(FT_DEFAULT_ATTACK_POINT);
	debugMessage("FragTrap", HAS_ARGS_CONSTRUCT);
}

FragTrap::FragTrap(const FragTrap& src) :
	ClapTrap(src)
{
	debugMessage("FragTrap", COPY_CONSTRUCT);
}

FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	ClapTrap::operator=(rhs);
	debugMessage("FragTrap", COPY_OPERATOR);
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	if (this->getHitPoint() == 0) {
		std::cout << RED << this->getName() << " was died... Do not high five..." << END << std::endl;
	}
	else {
		debugMessageHighFivesGuys("FragTrap", this->getName());
	}
}

FragTrap::~FragTrap()
{
	debugMessage("FragTrap", DESTRUCT);
}
