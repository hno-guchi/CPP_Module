/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/26 17:53:19 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// CONSTRUCTER
Cat::Cat() :
	Animal()
{
	this->brain_ = new Brain();
	debugMessage("Cat", DEFAULT_CONSTRUCT);
	this->type_ = "Cat";
}

Cat::Cat(const std::string& type) :
	Animal(type)
{
	this->brain_ = new Brain();
	debugMessage("Cat", HAS_ARGS_CONSTRUCT);
	this->type_ = "Cat";
}

Cat::Cat(const Cat& src) :
	Animal(src)
{
	this->brain_ = new Brain();
	debugMessage("Cat", COPY_CONSTRUCT);
}

// OPERATOR
Cat&	Cat::operator=(const Cat& rhs)
{
	Animal::operator=(rhs);

	Brain*	newBrain = new Brain();

	*newBrain = *rhs.brain_;
	delete this->brain_;
	this->brain_ = newBrain;

	debugMessage("Cat", COPY_OPERATOR);
	return (*this);
}

// GETTER
const Brain*	Cat::getBrain() const
{
	return (this->brain_);
}

const std::string	Cat::getBrainIdea(const unsigned int& index) const
{
	return (this->brain_->getIdea(index));
}

// SETTER
void	Cat::setType(const std::string& type)
{
	if (type != "Cat") {
		std::cout << RED << "Error : Wrong type." << END << std::endl;
		return ;
	}
	this->Animal::setType("Cat");
}

void	Cat::setBrainIdea(const std::string& idea)
{
	this->brain_->setIdea(idea);
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
	delete this->brain_;
}
