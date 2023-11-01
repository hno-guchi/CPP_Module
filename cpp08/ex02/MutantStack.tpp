/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:43:00 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/31 19:11:03 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "debugMessage.hpp"

// CONSTRUCT
template <typename TYPE>
MutantStack<TYPE>::MutantStack() :
	std::stack<TYPE>()
{
	debugMessage("MutantStack", DEFAULT_CONSTRUCT);
}

template <typename TYPE>
MutantStack<TYPE>::MutantStack(const MutantStack& other) :
	std::stack<TYPE>(other)
{
	debugMessage("MutantStack", HAS_ARG_CONSTRUCT);
}

// DESTRUCT
template <typename TYPE>
MutantStack<TYPE>::~MutantStack()
{
	debugMessage("MutantStack", DESTRUCT);
}

// OPERATOR
template <typename TYPE>
MutantStack<TYPE>&	MutantStack<TYPE>::operator=(const MutantStack& other)
{
	debugMessage("MutantStack", COPY_OPERATOR);
	this->std::stack<TYPE>::operator=(other);
	return (*this);
}

template <typename TYPE>
typename std::stack<TYPE>::container_type::reverse_iterator	MutantStack<TYPE>::begin()
{
	return (this->c.rbegin());
}

template <typename TYPE>
typename std::stack<TYPE>::container_type::const_reverse_iterator	MutantStack<TYPE>::begin() const
{
	return (this->c.rbegin());
}

template <typename TYPE>
typename std::stack<TYPE>::container_type::reverse_iterator	MutantStack<TYPE>::end()
{
	return (this->c.rend());
}

template <typename TYPE>
typename std::stack<TYPE>::container_type::const_reverse_iterator	MutantStack<TYPE>::end() const
{
	return (this->c.rend());
}

template <typename TYPE>
typename std::stack<TYPE>::container_type::iterator	MutantStack<TYPE>::rbegin()
{
	return (this->c.begin());
}

template <typename TYPE>
typename std::stack<TYPE>::container_type::const_iterator	MutantStack<TYPE>::rbegin() const
{
	return (this->c.begin());
}

template <typename TYPE>
typename std::stack<TYPE>::container_type::iterator		MutantStack<TYPE>::rend()
{
	return (this->c.end());
}

template <typename TYPE>
typename std::stack<TYPE>::container_type::const_iterator	MutantStack<TYPE>::rend() const
{
	return (this->c.end());
}
