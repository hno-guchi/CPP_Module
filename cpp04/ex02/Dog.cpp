/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/26 18:03:04 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// CONSTRUCTER
Dog::Dog() :
	Animal()
{
	this->brain_ = new Brain();
	debugMessage("Dog", DEFAULT_CONSTRUCT);
	this->type_ = "Dog";
}

Dog::Dog(const std::string& type) :
	Animal(type)
{
	this->brain_ = new Brain();
	debugMessage("Dog", HAS_ARGS_CONSTRUCT);
	this->type_ = "Dog";
}

Dog::Dog(const Dog& src) :
	Animal(src)
{
	// this->brain_ = new Brain(*src.brain_);
	this->brain_ = new Brain();
	*this->brain_ = *src.brain_;
	debugMessage("Dog", COPY_CONSTRUCT);
}

// OPERATOR
Dog&	Dog::operator=(const Dog& rhs)
{
	Animal::operator=(rhs);

	// Brain*	newBrain = new Brain(*rhs.brain_);
	Brain*	newBrain = new Brain();

	*newBrain = *rhs.brain_;

	delete this->brain_;
	this->brain_ = newBrain;
	debugMessage("Dog", COPY_OPERATOR);
	return (*this);
}

// GETTER
const Brain*	Dog::getBrain() const
{
	return (this->brain_);
}

const std::string	Dog::getBrainIdea(const unsigned int& index) const
{
	return (this->brain_->getIdea(index));
}

// SETTER
void	Dog::setType(const std::string& type)
{
	if (type != "Dog") {
		std::cout << RED << "Error : Wrong type." << END << std::endl;
		return ;
	}
	this->Animal::setType("Dog");
}

void	Dog::setBrain(const Brain& brain)
{
	// Brain*	newBrain = new Brain(brain);
	Brain*	newBrain = new Brain();

	*newBrain = brain;

	delete this->brain_;
	this->brain_ = newBrain;
}

void	Dog::setBrainIdea(const std::string& idea)
{
	this->brain_->setIdea(idea);
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
	delete this->brain_;
}
