/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/25 17:19:36 by hnoguchi         ###   ########.fr       */
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
	debugMessage("Dog", DEFAULT_CONSTRUCT);
}

Dog::Dog(const Dog& src)
{
	debugMessage("Dog", COPY_CONSTRUCT);
	this->operator=(src);
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

// SUBJECT FUNC

// DESTRUCTER
Dog::~Dog()
{
	debugMessage("Dog", DESTRUCT);
}
