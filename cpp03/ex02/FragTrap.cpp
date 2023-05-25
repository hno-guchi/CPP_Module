/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:58:05 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/25 09:03:00 by hnoguchi         ###   ########.fr       */
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
	debugMessage("FragTrap", DEFAULT_CONSTRUCT);
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

void	FragTrap::attack(const std::string& target)
{
	if (this->getHitPoint() == 0) {
		std::cout << RED << this->getName() << " was died... Not attacks..." << END << std::endl;
	}
	else if (this->getEnergyPoint() == 0) {
		std::cout << RED << this->getName() << " energyPoint is 0... Not attacks..." << END << std::endl;
	}
	else {
		debugMessageAttack("FragTrap", this->getName(), target, this->getAttackPoint());
		this->setEnergyPoint(this->getEnergyPoint() - 1);
	}
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
