/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/28 17:19:17 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// CONSTRUCTER
Cat::Cat() :
	Animal()
{
	debugMessage("Cat", DEFAULT_CONSTRUCT);
	this->brain_ = new Brain();
	this->type_ = "Cat";
}

Cat::Cat(const std::string& type) :
	Animal(type)
{
	debugMessage("Cat", HAS_ARGS_CONSTRUCT);
	this->brain_ = new Brain();
	this->type_ = "Cat";
}

Cat::Cat(const Cat& src) :
	Animal(src)
{
	debugMessage("Cat", COPY_CONSTRUCT);
	// this->brain_ = new Brain(*src.brain_);
	this->brain_ = new Brain();
	*this->brain_ = *src.brain_;
}

// OPERATOR
Cat&	Cat::operator=(const Cat& rhs)
{
	Animal::operator=(rhs);

	debugMessage("Cat", COPY_OPERATOR);
	// Brain*	newBrain = new Brain(*rhs.brain_);
	Brain*	newBrain = new Brain();

	*newBrain = *rhs.brain_;

	delete this->brain_;
	this->brain_ = newBrain;
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

void	Cat::setBrain(const Brain& brain)
{
	// Brain*	newBrain = new Brain(brain);
	Brain*	newBrain = new Brain();

	*newBrain = brain;

	delete this->brain_;
	this->brain_ = newBrain;
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
	delete this->brain_;
	debugMessage("Cat", DESTRUCT);
}
