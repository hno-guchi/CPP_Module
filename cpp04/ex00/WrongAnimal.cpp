/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/25 18:55:38 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// CONSTRUCTER
WrongAnimal::WrongAnimal() :
	type_("")
{
	debugMessage("WrongAnimal", DEFAULT_CONSTRUCT);
}

WrongAnimal::WrongAnimal(const std::string& type) :
	type_(type)
{
	debugMessage("WrongAnimal", DEFAULT_CONSTRUCT);
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	debugMessage("WrongAnimal", COPY_CONSTRUCT);
	this->operator=(src);
}

// OPERATOR
WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs)
{
	debugMessage("WrongAnimal", COPY_OPERATOR);
	this->type_ = rhs.getType();
	return (*this);
}

// GETTER
std::string	WrongAnimal::getType() const
{
	return (this->type_);
}

// SETTER
void	WrongAnimal::setType(const std::string& type)
{
	this->type_ = type;
}

// SUBJECT FUNC
void	WrongAnimal::makeSound() const
{
	std::cout << this->getType() << ": WrongAnimal Default Sound." << std::endl;
}

// DESTRUCTER
WrongAnimal::~WrongAnimal()
{
	debugMessage("WrongAnimal", DESTRUCT);
}
