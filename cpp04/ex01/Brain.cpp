/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/26 17:52:58 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// CONSTRUCTER
Brain::Brain()
{
	debugMessage("Brain", DEFAULT_CONSTRUCT);
	for (int i = 0; i < IDEARS_SIZE; i++) {
		this->ideas_[i] = "";
	}
	this->ideasSize_ = 0;
	this->currentIndex_ = 0;
}

Brain::Brain(const std::string& idea)
{
	debugMessage("Brain", HAS_ARGS_CONSTRUCT);
	this->ideas_[0] = idea;
	for (int i = 1; i < IDEARS_SIZE; i++) {
		this->ideas_[i] = "";
	}
	if (!idea.empty()) {
		this->ideasSize_ = 1;
	}
	else {
		this->ideasSize_ = 0;
	}
	this->currentIndex_ = 0;
}

Brain::Brain(const Brain& src)
{
	debugMessage("Brain", COPY_CONSTRUCT);
	this->operator=(src);
}

// OPERATOR
Brain&	Brain::operator=(const Brain& rhs)
{
	debugMessage("Brain", COPY_OPERATOR);
	for (unsigned int i = 0; i < rhs.getLastIndex(); i++) {
		this->ideas_[i] = rhs.getIdea(i);
	}
	this->ideasSize_ = rhs.getIdeaArraySize();
	this->currentIndex_ = rhs.getLastIndex();
	return (*this);
}

// GETTER
std::string		Brain::getIdea(const unsigned int& index) const
{
	if (this->getLastIndex() <= index) {
		std::cout << RED << "Error: Not idea yet..." << END << std::endl;
		return ("");
	}
	return (this->ideas_[index]);
}

unsigned int	Brain::getIdeaArraySize() const
{
	return (this->ideasSize_);
}

unsigned int	Brain::getLastIndex() const
{
	return (this->currentIndex_);
}

// SETTER
void	Brain::setIdea(const std::string& idea)
{
	if (this->currentIndex_ == IDEARS_SIZE) {
		std::cout << RED << "Error: Idea is full..." << END << std::endl;
	}
	else if (idea.empty()) {
		std::cout << RED << "Error: Not empty idea..." << END << std::endl;
	}
	else {
		this->ideas_[this->currentIndex_] = idea;
		this->currentIndex_ += 1;
	}
}

// SUBJECT FUNC

// DESTRUCTER
Brain::~Brain()
{
	debugMessage("Brain", DESTRUCT);
}
