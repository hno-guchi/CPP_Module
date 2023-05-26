/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/26 17:47:47 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// CONSTRUCTER
Cat::Cat() :
	Animal()
{
	this->type_ = "Cat";
	debugMessage("Cat", DEFAULT_CONSTRUCT);
}

Cat::Cat(const std::string& type) :
	Animal(type)
{
	this->type_ = "Cat";
	debugMessage("Cat", HAS_ARGS_CONSTRUCT);
}

Cat::Cat(const Cat& src) :
	Animal(src)
{
	debugMessage("Cat", COPY_CONSTRUCT);
}

// OPERATOR
Cat&	Cat::operator=(const Cat& rhs)
{
	Animal::operator=(rhs);
	debugMessage("Cat", COPY_OPERATOR);
	return (*this);
}

// GETTER

// SETTER
void	Cat::setType(const std::string& type)
{
	if (type != "Cat") {
		std::cout << RED << "Error : Wrong type." << END << std::endl;
		return ;
	}
	this->Animal::setType("Cat");
}

// SUBJECT FUNC
void	Cat::makeSound() const
{
	std::cout << this->getType() << ": Wagahai ha Neko de aru." << std::endl;
}

// DESTRUCTER
Cat::~Cat()
{
	debugMessage("Cat", DESTRUCT);
}