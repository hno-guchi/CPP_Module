/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:58:05 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/24 17:41:37 by hnoguchi         ###   ########.fr       */
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
	debugMessage("ScavTrap", DEFAULT_CONSTRUCT);
}

ScavTrap::ScavTrap(const ScavTrap& src) :
	ClapTrap(src)
{
	debugMessage("ScavTrap", COPY_CONSTRUCT);
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	ClapTrap::operator=(rhs);
	debugMessage("ScavTrap", COPY_OPERATOR);
	return (*this);
}
// std::string		ScavTrap::getName() const
// {
// 	return (ClapTrap::getName());
// }
// 
// unsigned int	ScavTrap::getHitPoint() const
// {
// 	return (ClapTrap::getHitPoint());
// }
// 
// unsigned int	ScavTrap::getEnergyPoint() const
// {
// 	return (ClapTrap::getEnergyPoint());
// }
// 
// unsigned int	ScavTrap::getAttackPoint() const
// {
// 	return (ClapTrap::getAttackPoint());
// }
// 
// unsigned int	ScavTrap::getUpperLimitHitPoint() const
// {
// 	return (ClapTrap::getUpperLimitHitPoint());
// }
// 
// void	ScavTrap::setName(const std::string& name)
// {
// 	ClapTrap::setName(name);
// }
// 
// void	ScavTrap::setHitPoint(const unsigned int& amount)
// {
// 	ClapTrap::setHitPoint(amount);
// }
// 
// void	ScavTrap::setEnergyPoint(const unsigned int& amount)
// {
// 	ClapTrap::setEnergyPoint(amount);
// }
// 
// void	ScavTrap::setAttackPoint(const unsigned int& amount)
// {
// 	ClapTrap::setAttackPoint(amount);
// }

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
		// this->energyPoint_ -= 1;
	}
}

void	ScavTrap::guardGate()
{
	debugMessageGuardGate("ScavTrap");
}

ScavTrap::~ScavTrap()
{
	debugMessage("ScavTrap", DESTRUCT);
}
