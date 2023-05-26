/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/26 17:48:04 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// CONSTRUCTER
Dog::Dog() :
	Animal()
{
	this->type_ = "Dog";
	debugMessage("Dog", DEFAULT_CONSTRUCT);
}

Dog::Dog(const std::string& type) :
	Animal(type)
{
	this->type_ = "Dog";
	debugMessage("Dog", HAS_ARGS_CONSTRUCT);
}

Dog::Dog(const Dog& src) :
	Animal(src)
{
	debugMessage("Dog", COPY_CONSTRUCT);
}

// OPERATOR
Dog&	Dog::operator=(const Dog& rhs)
{
	Animal::operator=(rhs);
	debugMessage("Dog", COPY_OPERATOR);
	return (*this);
}

// GETTER

// SETTER
void	Dog::setType(const std::string& type)
{
	if (type != "Dog") {
		std::cout << RED << "Error : Wrong type." << END << std::endl;
		return ;
	}
	this->Animal::setType("Dog");
}

// SUBJECT FUNC
void	Dog::makeSound() const
{
	std::cout << this->getType() << ": Wan Wan Wa Wa Wa--n Wan Wan Wa Wa Wa--n." << std::endl;
}

// DESTRUCTER
Dog::~Dog()
{
	debugMessage("Dog", DESTRUCT);
}
