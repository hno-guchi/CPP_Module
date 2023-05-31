/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/31 12:57:25 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// CONSTRUCTER
Cure::Cure() :
	AMateria()
{
	debugMessage("Cure", DEFAULT_CONSTRUCT);
	this->setType("cure");

}

Cure::Cure(const std::string& type) :
	AMateria(type)
{
	debugMessage("Cure", DEFAULT_CONSTRUCT);
	if (type != "cure") {
		std::cout << RED << "Error: Not type cure..." << END << std::endl;
	}
	this->setType("cure");
}

Cure::Cure(const Cure& src)
{
	debugMessage("Cure", COPY_CONSTRUCT);
	this->operator=(src);
}

// OPERATOR
Cure&	Cure::operator=(const Cure& rhs)
{
	AMateria::operator=(rhs);
	debugMessage("Cure", COPY_OPERATOR);
	return (*this);
}

// GETTER

// SETTER

// SUBJECT FUNC
AMateria*	Cure::clone() const
{
	Cure*	dup = new Cure();
	
	return (dup);
}

// TODO:
// void	Cure::use(ICharacter& target)
void	Cure::use()
{
	std::cout << "* heals " \
		<< MAGENTA << "<name>" << END \
		<< "’s wounds *" << std::endl;
}

// DESTRUCTER
Cure::~Cure()
{
	debugMessage("Cure", DESTRUCT);
}
