/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:25:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/08/02 14:38:22 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// CONSTRUCTER
DiamondTrap::DiamondTrap()
{
	this->setName("");
	this->ClapTrap::setName("");
	this->setHitPoint(FT_DEFAULT_HIT_POINT);
	this->setEnergyPoint(ST_DEFAULT_ENERGY_POINT);
	this->setAttackPoint(FT_DEFAULT_ATTACK_POINT);
	debugMessage("DiamondTrap", DEFAULT_CONSTRUCT);
}

DiamondTrap::DiamondTrap(const std::string& name)
{
	this->setName(name);
	this->setHitPoint(FT_DEFAULT_HIT_POINT);
	this->setEnergyPoint(ST_DEFAULT_ENERGY_POINT);
	this->setAttackPoint(FT_DEFAULT_ATTACK_POINT);
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
	ClapTrap::operator=(rhs);
	this->name_ = rhs.getName();
	debugMessage("DiamondTrap", COPY_OPERATOR);
	return (*this);
}

// GETTER
std::string		DiamondTrap::getName() const
{
	return (this->name_);
}

// SETTER
void	DiamondTrap::setName(const std::string& name)
{
	if (MAX_NAME_SIZE < name.length()) {
		std::cout << RED << "Error: setName: To long name." << END << std::endl;
		return ;
	}
	std::string	clap_name = name + "_clap_name";
	this->name_ = name;
	this->ClapTrap::setName(clap_name);
}

// SUBJECT FUNC
void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap::name_ : [" << this->getName() << "]" << std::endl;
	std::cout << "   ClapTrap::name_ : [" << this->ClapTrap::getName() << "]" << std::endl;
}

// DESTRUCTER
DiamondTrap::~DiamondTrap()
{
	debugMessage("DiamondTrap", DESTRUCT);
}
