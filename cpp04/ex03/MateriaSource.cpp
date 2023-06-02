/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/06/02 17:14:50 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// CONSTRUCTER
MateriaSource::MateriaSource()
{
	debugMessage("MateriaSource", DEFAULT_CONSTRUCT);
	for (int i = 0; i < MAX_LEARNED_LIST_SIZE; i++) {
		this->learnedList_[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	debugMessage("MateriaSource", COPY_CONSTRUCT);
	for (int i = 0; i < MAX_LEARNED_LIST_SIZE; i++) {
		this->learnedList_[i] = NULL;
	}
	this->operator=(src);
}

// OPERATOR
MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	debugMessage("MateriaSource", COPY_OPERATOR);
	for (int i = 0; i < MAX_LEARNED_LIST_SIZE; i++) {
		if (this->learnedList_[i] != NULL) {
			delete this->learnedList_[i];
			this->learnedList_[i] = NULL;
		}
		if (rhs.learnedList_[i] != NULL) {
			this->learnedList_[i] = rhs.learnedList_[i]->clone();
		}
	}
	return (*this);
}

// GETTER

// SETTER

// SUBJECT FUNC
void	MateriaSource::learnMateria(AMateria* materia)
{
	if (materia == NULL) {
		std::cout << RED << "Error: Wrong argument..." << END << std::endl;
		return ;
	}
	for (int i = 0; i < MAX_LEARNED_LIST_SIZE; i++) {
		if (this->learnedList_[i] == NULL) {
			this->learnedList_[i] = materia;
			return ;
		}
	}
	std::cout << RED << "Error: Inventory capacity is Fill..." << END << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MAX_LEARNED_LIST_SIZE; i++) {
		if (type == this->learnedList_[i]->getType()) {
			return (this->learnedList_[i]->clone());
		}
	}
	std::cout << RED << "Error: Wrong argument..." << END << std::endl;
	return (NULL);
}

void	MateriaSource::printLearnedList()
{
	std::cout << "learnedList[]________________________" << std::endl;
	for (int i = 0; i < MAX_LEARNED_LIST_SIZE; i++) {
		std::cout << "[" << i << "] | " << std::flush;
		std::cout << "[" << &this->learnedList_[i] << "] | " << std::flush;
		if (this->learnedList_[i] == NULL) {
		std::cout << "[" << std::setw(8) << " (null) " << "] |" << std::endl;
		}
		else {
			std::cout << "[" << std::setw(8) << this->learnedList_[i]->getType() << "] |" << std::endl;
		}

	}
	std::cout << "_____________________________________\n" << std::endl;
}

// DESTRUCTER
MateriaSource::~MateriaSource()
{
	std::cout << "------------------------------" << std::endl;
	for (int i = 0; i < MAX_LEARNED_LIST_SIZE; i++) {
		delete learnedList_[i];
	}
	debugMessage("MateriaSource", DESTRUCT);
	std::cout << "------------------------------\n" << std::endl;
}
