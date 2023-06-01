/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/06/01 15:03:02 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
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
	debugMessage("AMateria", HAS_ARGS_CONSTRUCT);
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

void	AMateria::use(ICharacter& target)
{
	std::cout << MAGENTA << target.getName() << END << ": Default use() message..." << std::endl;
}

// DESTRUCTER
AMateria::~AMateria()
{
	debugMessage("AMateria", DESTRUCT);
}
