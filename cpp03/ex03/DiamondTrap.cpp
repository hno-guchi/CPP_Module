/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:25:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/08/01 10:58:04 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// CONSTRUCTER
DiamondTrap::DiamondTrap()
{
	this->name_ = "";
	this->setHitPoint(FT_DEFAULT_HIT_POINT);
	this->setEnergyPoint(ST_DEFAULT_ENERGY_POINT);
	this->setAttackPoint(FT_DEFAULT_ATTACK_POINT);
	debugMessage("DiamondTrap", DEFAULT_CONSTRUCT);
}

DiamondTrap::DiamondTrap(const std::string& name)
{
	std::string	clap_name = name;

	clap_name += "_clap_name";
	this->name_ = name;
	this->setName(clap_name);
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
	debugMessage("DiamondTrap", COPY_OPERATOR);
	this->name_ = rhs.name_;
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
