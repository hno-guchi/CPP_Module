/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/31 14:17:43 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// CONSTRUCTER
Ice::Ice() :
	AMateria()
{
	debugMessage("Ice", DEFAULT_CONSTRUCT);
	this->type_ = "ice";
}

Ice::Ice(const std::string& type) :
	AMateria(type)
{
	debugMessage("Ice", HAS_ARGS_CONSTRUCT);
	if (type != "ice") {
		std::cout << RED << "Error: Not type ice..." << END << std::endl;
	}
	this->type_ = "ice";
}

Ice::Ice(const Ice& src) :
	AMateria(src)
{
	debugMessage("Ice", COPY_CONSTRUCT);
}

// OPERATOR
Ice&	Ice::operator=(const Ice& rhs)
{
	AMateria::operator=(rhs);
	debugMessage("Ice", COPY_OPERATOR);
	return (*this);
}

// GETTER

// SETTER

// SUBJECT FUNC
AMateria*	Ice::clone() const
{
	Ice*	dup = new Ice();
	
	return (dup);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " \
		<< MAGENTA << target.getName() << END
		<< " *" << std::endl;
}

// DESTRUCTER
Ice::~Ice()
{
	debugMessage("Ice", DESTRUCT);
}
