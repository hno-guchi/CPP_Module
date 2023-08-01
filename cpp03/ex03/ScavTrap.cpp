/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:58:05 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/08/01 10:24:10 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() :
	ClapTrap()
{
	this->setName("");
	this->setHitPoint(ST_DEFAULT_HIT_POINT);
	this->setEnergyPoint(ST_DEFAULT_ENERGY_POINT);
	this->setAttackPoint(ST_DEFAULT_ATTACK_POINT);
	debugMessage("ScavTrap", DEFAULT_CONSTRUCT);
}

ScavTrap::ScavTrap(const std::string& name) :
	ClapTrap(name)
{
	this->setName(name);
	this->setHitPoint(ST_DEFAULT_HIT_POINT);
	this->setEnergyPoint(ST_DEFAULT_ENERGY_POINT);
	this->setAttackPoint(ST_DEFAULT_ATTACK_POINT);
	debugMessage("ScavTrap", HAS_ARGS_CONSTRUCT);
}

ScavTrap::ScavTrap(const ScavTrap& src) :
	ClapTrap(src)
{
	debugMessage("ScavTrap", COPY_CONSTRUCT);
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	this->ClapTrap::operator=(rhs);
	debugMessage("ScavTrap", COPY_OPERATOR);
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getHitPoint() == 0) {
		std::cout << RED << this->getName() << " was died... Not attacks..." << END << std::endl;
	}
	else if (this->getEnergyPoint() == 0) {
		std::cout << RED << this->getName() << " energyPoint is 0... Not attacks..." << END << std::endl;
	}
	else {
		debugMessageAttack("ScavTrap", this->getName(), target, this->getAttackPoint());
		this->setEnergyPoint(this->getEnergyPoint() - 1);
	}
}

void	ScavTrap::guardGate()
{
	if (this->getHitPoint() == 0) {
		std::cout << RED << this->getName() << " was died... Not guard gate mode..." << END << std::endl;
	}
	else {
		debugMessageGuardGate("ScavTrap", this->getName());
	}
}

ScavTrap::~ScavTrap()
{
	debugMessage("ScavTrap", DESTRUCT);
}
