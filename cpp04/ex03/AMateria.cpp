/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/31 12:48:42 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// CONSTRUCTER
AMateria::AMateria() :
	type_("")
{
	debugMessage("AMateria", DEFAULT_CONSTRUCT);
}

AMateria::AMateria(const std::string& type) :
	type_(type)
{
	debugMessage("AMateria", DEFAULT_CONSTRUCT);
}

AMateria::AMateria(const AMateria& src)
{
	debugMessage("AMateria", COPY_CONSTRUCT);
	this->operator=(src);
}

// OPERATOR
AMateria&	AMateria::operator=(const AMateria& rhs)
{
	debugMessage("AMateria", COPY_OPERATOR);
	this->type_ = rhs.type_;
	return (*this);
}

// GETTER
//Returns the materia type
std::string const &	AMateria::getType() const
{
	return (this->type_);
}

// SETTER
void	AMateria::setType(const std::string& type)
{
	this->type_ = type;
}

// SUBJECT FUNC
// AMateria*	AMateria::clone() const = 0;

// TODO:
// void	AMateria::use(ICharacter& target)
void	AMateria::use()
{
	// std::cout << target.getName() << ": " << "Default use() message..." << std::endl;
	std::cout << MAGENTA << "<NAME>" << END << ": " << "Default use() message..." << std::endl;
}

// DESTRUCTER
AMateria::~AMateria()
{
	debugMessage("AMateria", DESTRUCT);
}
