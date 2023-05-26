/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/26 17:13:20 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// CONSTRUCTER
Animal::Animal() :
	type_("")
{
	debugMessage("Animal", DEFAULT_CONSTRUCT);
}

Animal::Animal(const std::string& type) :
	type_(type)
{
	debugMessage("Animal", DEFAULT_CONSTRUCT);
}

Animal::Animal(const Animal& src)
{
	debugMessage("Animal", COPY_CONSTRUCT);
	this->operator=(src);
}

// OPERATOR
Animal&	Animal::operator=(const Animal& rhs)
{
	debugMessage("Animal", COPY_OPERATOR);
	this->type_ = rhs.getType();
	return (*this);
}

// GETTER
std::string	Animal::getType() const
{
	return (this->type_);
}

// SETTER
void	Animal::setType(const std::string& type)
{
	this->type_ = type;
}

// SUBJECT FUNC
// void	Animal::makeSound() const = 0;

// DESTRUCTER
Animal::~Animal()
{
	debugMessage("Animal", DESTRUCT);
}
