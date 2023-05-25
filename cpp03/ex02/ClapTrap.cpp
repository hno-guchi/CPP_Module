/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:09:31 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/25 09:25:13 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	name_(""), hitPoint_(CT_DEFAULT_HIT_POINT), energyPoint_(CT_DEFAULT_ENERGY_POINT), attackPoint_(CT_DEFAULT_ATTACK_POINT), upperLimitHitPoint_(CT_DEFAULT_HIT_POINT)
{
	debugMessage("ClapTrap", DEFAULT_CONSTRUCT);
}

ClapTrap::ClapTrap(const std::string& name) :
	name_(name), hitPoint_(CT_DEFAULT_HIT_POINT), energyPoint_(CT_DEFAULT_ENERGY_POINT), attackPoint_(CT_DEFAULT_ATTACK_POINT), upperLimitHitPoint_(CT_DEFAULT_HIT_POINT)
{
	debugMessage("ClapTrap", DEFAULT_CONSTRUCT);
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	debugMessage("ClapTrap", COPY_CONSTRUCT);
	this->operator=(src);
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	debugMessage("ClapTrap", COPY_OPERATOR);
	this->name_ = rhs.getName();
	this->hitPoint_ = rhs.getHitPoint();
	this->energyPoint_ = rhs.getEnergyPoint();
	this->attackPoint_ = rhs.getAttackPoint();
	this->upperLimitHitPoint_ = rhs.getUpperLimitHitPoint();
	return (*this);
}

std::string	ClapTrap::getName() const
{
	return (this->name_);
}

unsigned int	ClapTrap::getHitPoint() const
{
	return (this->hitPoint_);
}

unsigned int	ClapTrap::getEnergyPoint() const
{
	return (this->energyPoint_);
}

unsigned int	ClapTrap::getAttackPoint() const
{
	return (this->attackPoint_);
}

unsigned int	ClapTrap::getUpperLimitHitPoint() const
{
	return (this->upperLimitHitPoint_);
}

void	ClapTrap::setName(const std::string& name)
{
	if (MAX_NAME_SIZE < name.length()) {
		std::cout << RED << "Error: setName: To long name." << END << std::endl;
		return ;
	}
	this->name_ = name;
}

void	ClapTrap::setHitPoint(const unsigned int& amount)
{
	if (amount < 1 || MAX_HIT_POINT < amount) {
		std::cout << RED << "Error: setHitPoint: Wrong amount." << END << std::endl;
		return ;
	}
	this->hitPoint_ = amount;
	this->upperLimitHitPoint_ = amount;
}

void	ClapTrap::setEnergyPoint(const unsigned int& amount)
{
	if (amount < 1 || MAX_ENERGY_POINT < amount) {
		std::cout << RED << "Error: setEnergyPoint: Wrong amount. " << END << std::endl;
		return ;
	}
	this->energyPoint_ = amount;
}

void	ClapTrap::setAttackPoint(const unsigned int& amount)
{
	if (amount < 1 || MAX_ATTACK_POINT < amount) {
		std::cout << RED << "Error: setAttackPoint: Wrong amount." << END << std::endl;
		return ;
	}
	this->attackPoint_ = amount;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hitPoint_ == 0) {
		std::cout << RED << this->name_ << " was died... Not attacks..." << END << std::endl;
	}
	else if (this->energyPoint_ == 0) {
		std::cout << RED << this->name_ << " energyPoint is 0... Not attacks..." << END << std::endl;
	}
	else {
		debugMessageAttack("ClapTrap", this->name_, target, this->attackPoint_);
		this->energyPoint_ -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint_ == 0) {
		std::cout << RED << this->name_ << " was died... Not take damage..." << END << std::endl;
	}
	else if (MAX_ATTACK_POINT < amount) {
		std::cout << RED << "Error: takeDamege: Wrong amount." << END << std::endl;
	}
	else {
		debugMessageTakeDamage("ClapTrap", this->name_, amount);
		if (this->hitPoint_ < amount) {
			amount = this->hitPoint_;
		}
		this->hitPoint_ -= amount;
		if (this->hitPoint_ == 0) {
			std::cout << RED << this->name_ << " is died... " << END << std::endl;
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoint_ == 0) {
		std::cout << RED << this->name_ << " was died... Not be repaired..." << END << std::endl;
	}
	else if (this->energyPoint_ == 0) {
		std::cout << RED << this->name_ << " energyPoint is 0... Not be repaired..." << END << std::endl;
	}
	else {
		if ((this->upperLimitHitPoint_ - this->hitPoint_) < amount) {
			amount = this->upperLimitHitPoint_ - this->hitPoint_;
		}
		debugMessageBeRepaired("ClapTrap", this->name_, amount);
		this->hitPoint_ += amount;
		this->energyPoint_ -= 1;
	}
}

ClapTrap::~ClapTrap()
{
	debugMessage("ClapTrap", DESTRUCT);
}
