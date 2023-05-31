/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/31 18:45:12 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// CONSTRUCTER
MateriaSource::MateriaSource()
{
	debugMessage("MateriaSource", DEFAULT_CONSTRUCT);
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++) {
		this->inventory_[i] = NULL;
	}
	this->oldestIndex_ = "";
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	debugMessage("MateriaSource", COPY_CONSTRUCT);
	this->operator=(src);
}

// OPERATOR
MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	debugMessage("MateriaSource", COPY_OPERATOR);
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++) {
		this->inventory_[i] = NULL;
	}
	this->oldestIndex_ = rhs.getOldestIndex();
	return (*this);
}

// GETTER

// SETTER

// SUBJECT FUNC

// DESTRUCTER
MateriaSource::~MateriaSource()
{
	debugMessage("MateriaSource", DESTRUCT);
}
