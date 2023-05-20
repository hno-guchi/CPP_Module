/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:09:31 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/20 18:39:12 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static void	writeMessage(std::string message)
{
	std::cout << message << std::endl;
}

ClapTrap::ClapTrap() : name_(""), hitPoint_(DEFAULT_HIT_POINT), energyPoint_(DEFAULT_ENERGY_POINT), attackPoint_(0)
{
	writeMessage(DEFAULT_CONSTRUCT_MESSAGE);
}

ClapTrap::ClapTrap(const std::string& name) : name_(name), hitPoint_(DEFAULT_HIT_POINT), energyPoint_(DEFAULT_ENERGY_POINT), attackPoint_(0)
{
	writeMessage(DEFAULT_CONSTRUCT_MESSAGE);
}

ClapTrap::ClapTrap(const ClapTrap& src) : name_(src.name_), hitPoint_(src.hitPoint_), energyPoint_(src.energyPoint_), attackPoint_(src.attackPoint_)
{
	writeMessage(COPY_CONSTRUCT_MESSAGE);
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	writeMessage(COPY_OPERATOR_MESSAGE);
	this->name_ = rhs.name_;
	this->hitPoint_ = rhs.hitPoint_;
	this->energyPoint_ = rhs.energyPoint_;
	this->attackPoint_ = rhs.attackPoint_;
	return (*this);
}

std::string	ClapTrap::getName()
{
	return (this->name_);
}

int	ClapTrap::getHitPoint()
{
	return (this->hitPoint_);
}

int	ClapTrap::getEnergyPoint()
{
	return (this->energyPoint_);
}

int	ClapTrap::getAttackPoint()
{
	return (this->attackPoint_);
}

void	ClapTrap::setName(const std::string& name)
{
	if (MAX_NAME_SIZE < name.length()) {
		std::cout << RED << "Error: To long name.(under 20 characters)" << END << std::endl;
		return ;
	}
	this->name_ = name;
}

void	ClapTrap::setHitPoint(const int& amount)
{
	if (amount < 1 || DEFAULT_HIT_POINT < amount) {
		std::cout << RED << "Error: Wrong amount.(Over 0 and under 10)" << END << std::endl;
		return ;
	}
	this->hitPoint_ = amount;
}

void	ClapTrap::setEnergyPoint(const int& amount)
{
	if (amount < 1 || DEFAULT_ENERGY_POINT < amount) {
		std::cout << RED << "Error: Wrong amount.(Over 0 and under 10)" << END << std::endl;
		return ;
	}
	this->energyPoint_ = amount;
}

void	ClapTrap::setAttackPoint(const int& amount)
{
	if (amount < 1 || MAX_ATTACK_POINT < amount) {
		std::cout << RED << "Error: Wrong amount.(Over 0 and under 10)" << END << std::endl;
		return ;
	}
	this->attackPoint_ = amount;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hitPoint_ == 0) {
		std::cout << RED << this->name_ << " was died... Not attacks..." << END << std::endl;
		return ;
	}
	if (this->energyPoint_ == 0) {
		std::cout << RED << this->name_ << " energyPoint is 0... Not attacks..." << END << std::endl;
		return ;
	}
	std::cout << this->name_ << " attacks " << target << ", causing " << this->attackPoint_ << " points of damage!" << std::endl;
	this->energyPoint_ -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint_ == 0) {
		std::cout << RED << this->name_ << " was died..." << END << std::endl;
		return ;
	}
	if (MAX_ATTACK_POINT < amount) {
		std::cout << RED << "Error: Wrong amount.(under 10)" << END << std::endl;
		return ;
	}
	std::cout << this->name_ << " is attacked, causing " << amount << " points of damage!" << std::endl;
	this->hitPoint_ -= static_cast<int>(amount);
	if (this->hitPoint_ < 1) {
		this->hitPoint_ = 0;
		std::cout << RED << this->name_ << " is died... " << END << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoint_ == 0) {
		std::cout << RED << this->name_ << " was died..." << END << std::endl;
		return ;
	}
	if ((DEFAULT_HIT_POINT - this->hitPoint_) < static_cast<int>(amount)) {
		amount = DEFAULT_HIT_POINT - this->hitPoint_;
	}
	std::cout << this->name_ << " is repaired, causing " << amount << " points of repaire!" << std::endl;
	this->hitPoint_ += amount;
}

ClapTrap::~ClapTrap()
{
	writeMessage(DESTRUCT_MESSAGE);
}
