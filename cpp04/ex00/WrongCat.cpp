/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/26 17:48:49 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// CONSTRUCTER
WrongCat::WrongCat() :
	WrongAnimal()
{
	this->type_ = "Cat";
	debugMessage("WrongCat", DEFAULT_CONSTRUCT);
}

WrongCat::WrongCat(const std::string& type) :
	WrongAnimal(type)
{
	this->type_ = "Cat";
	debugMessage("WrongCat", HAS_ARGS_CONSTRUCT);
}

WrongCat::WrongCat(const WrongCat& src) :
	WrongAnimal(src)
{
	debugMessage("WrongCat", COPY_CONSTRUCT);
}

// OPERATOR
WrongCat&	WrongCat::operator=(const WrongCat& rhs)
{
	WrongAnimal::operator=(rhs);
	debugMessage("WrongCat", COPY_OPERATOR);
	return (*this);
}

// GETTER

// SETTER
void	WrongCat::setType(const std::string& type)
{
	if (type != "Cat") {
		std::cout << RED << "Error : Wrong type." << END << std::endl;
		return ;
	}
	this->WrongAnimal::setType("WrongCat");
}

// SUBJECT FUNC
void	WrongCat::makeSound() const
{
	std::cout << this->getType() << ": Wagahai ha Warui Neko de aru." << std::endl;
}

// DESTRUCTER
WrongCat::~WrongCat()
{
	debugMessage("WrongCat", DESTRUCT);
}
