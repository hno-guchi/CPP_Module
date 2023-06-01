/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/06/01 17:44:34 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// CONSTRUCTER
Character::Character()
{
	debugMessage("Character", DEFAULT_CONSTRUCT);
	this->name_ = "John_Doe";
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++) {
		this->inventory_[i] = NULL;
	}
}

Character::Character(const std::string& name)
{
	debugMessage("Character", HAS_ARGS_CONSTRUCT);
	if (name.empty()) {
		std::cout << RED << "Warning: Wrong argument..." << END << std::endl;
		this->name_ = "John_Doe";
	}
	else if (MAX_NAME_SIZE < name.length()) {
		std::cout << RED << "Warning: Too long name..." << END << std::endl;
		this->name_ = name.substr(0, 20);
	}
	else {
		this->name_ = name;
	}
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++) {
		this->inventory_[i] = NULL;
	}
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
	this->name_ = rhs.getName();
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++) {
		delete this->inventory_[i];
		this->inventory_[i] = NULL;
		if (rhs.inventory_[i] != NULL) {
			this->inventory_[i] = rhs.inventory_[i]->clone();
		}
	}
	return (*this);
}

// GETTER
std::string const &	Character::getName() const
{
	return (this->name_);
}

const AMateria*	Character::getMateria(int index) const
{
	if (index < 0 || MAX_INVENTORY_SIZE <= index) {
		std::cout << RED << "Error: Wrong argument..." << END << std::endl;
		return (NULL);
	}
	else if (this->inventory_[index] == NULL) {
		std::cout << RED << "Error: Not exist data..." << END << std::endl;
		return (NULL);
	}
	return (this->inventory_[index]);
}

// SETTER
void	Character::setName(const std::string& name)
{
	if (name.empty()) {
		std::cout << RED << "Error: Wrong argument..." << END << std::endl;
	}
	else if (MAX_NAME_SIZE < name.length()) {
		std::cout << RED << "Warning: Too long name..." << END << std::endl;
		this->name_ = name.substr(0, 20);
	}
	else {
		this->name_ = name;
	}
}

// SUBJECT FUNC
void	Character::equip(AMateria* m)
{
	if (m == NULL) {
		std::cout << RED << "Error: Wrong argument..." << END << std::endl;
		return ;
	}
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++) {
		if (this->inventory_[i] == NULL) {
			this->inventory_[i] = m;
			return ;
		}
	}
	std::cout << RED << "Error: Inventory capacity is Fill..." << END << std::endl;
	delete m;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || MAX_INVENTORY_SIZE <= idx) {
		std::cout << RED << "Error: Wrong argument..." << END << std::endl;
	}
	else if (this->inventory_[idx] == NULL) {
		std::cout << RED << "Error: Not exist data..." << END << std::endl;
	}
	else {
		this->inventory_[idx] = NULL;
		for (int i = idx; (i + 1) < MAX_INVENTORY_SIZE; i++) {
			if (this->inventory_[i] == NULL) {
				if (this->inventory_[i + 1] != NULL) {
					this->inventory_[i] = this->inventory_[i + 1];
					this->inventory_[i + 1] = NULL;
				}
			}
		}
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || MAX_INVENTORY_SIZE <= idx) {
		std::cout << RED << "Error: Wrong argument..." << END << std::endl;
	}
	else if (this->inventory_[idx] == NULL) {
		std::cout << RED << "Error: Not exist inventory..." << END << std::endl;
	}
	else {
		this->inventory_[idx]->use(target);
	}
}


// DEBUG
void	Character::printData() const
{
	std::cout << "name: [" << MAGENTA << this->getName() << END << "]" << std::endl;
	std::cout << "      inventory_[]___________________________" << std::endl;
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++) {
		std::cout << "      | [" << i << "] | " << std::flush;
		std::cout << "[" << &this->inventory_[i] << "] | " << std::flush;
		if (this->inventory_[i] == NULL) {
		std::cout << "[" << std::setw(8) << " (null) " << "] |" << std::endl;
		}
		else {
			std::cout << "[" << std::setw(8) << this->inventory_[i]->getType() << "] |" << std::endl;
		}

	}
	std::cout << "      ---------------------------------------\n" << std::endl;
}

// DESTRUCTER
Character::~Character()
{
	std::cout << "------------------------------" << std::endl;
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++) {
		delete this->inventory_[i];
	}
	debugMessage("Character", DESTRUCT);
	std::cout << "------------------------------\n" << std::endl;
}
