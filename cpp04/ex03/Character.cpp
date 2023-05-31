/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/31 18:39:55 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// CONSTRUCTER
Character::Character()
{
	debugMessage("Character", DEFAULT_CONSTRUCT);
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++) {
		this->inventory_[i] = NULL;
	}
	this->name_ = "";
}

Character::Character(const std::string& name)
{
	debugMessage("Character", HAS_ARGS_CONSTRUCT);
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++) {
		this->inventory_[i] = NULL;
	}
	this->name_ = name;
}

Character::Character(const Character& src)
{
	debugMessage("Character", COPY_CONSTRUCT);
	this->operator=(src);
}

// OPERATOR
Character&	Character::operator=(const Character& rhs)
{
	debugMessage("Character", COPY_OPERATOR);
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++) {
	}

	this->name_ = rhs.getName();
	return (*this);
}

// GETTER

// SETTER

// SUBJECT FUNC

// DESTRUCTER
Character::~Character()
{
	debugMessage("Character", DESTRUCT);
}
