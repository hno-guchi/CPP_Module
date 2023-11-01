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
template <typename TYPE, typename CONTAINER>
MutantStack<TYPE, CONTAINER>::MutantStack() :
	std::stack<TYPE, CONTAINER>()
{
	debugMessage("MutantStack", DEFAULT_CONSTRUCT);
}

template <typename TYPE, typename CONTAINER>
MutantStack<TYPE, CONTAINER>::MutantStack(const MutantStack& other) :
	std::stack<TYPE, CONTAINER>(other)
{
	debugMessage("MutantStack", HAS_ARG_CONSTRUCT);
}

// DESTRUCT
template <typename TYPE, typename CONTAINER>
MutantStack<TYPE, CONTAINER>::~MutantStack()
{
	debugMessage("MutantStack", DESTRUCT);
}

// OPERATOR
template <typename TYPE, typename CONTAINER>
MutantStack<TYPE, CONTAINER>&	MutantStack<TYPE, CONTAINER>::operator=(const MutantStack& other)
{
	debugMessage("MutantStack", COPY_OPERATOR);
	this->std::stack<TYPE, CONTAINER>::operator=(other);
	return (*this);
}

template <typename TYPE, typename CONTAINER>
typename std::stack<TYPE, CONTAINER>::container_type::reverse_iterator	MutantStack<TYPE, CONTAINER>::begin()
{
	return (this->c.rbegin());
}

template <typename TYPE, typename CONTAINER>
typename std::stack<TYPE, CONTAINER>::container_type::const_reverse_iterator	MutantStack<TYPE, CONTAINER>::begin() const
{
	return (this->c.rbegin());
}

template <typename TYPE, typename CONTAINER>
typename std::stack<TYPE, CONTAINER>::container_type::reverse_iterator	MutantStack<TYPE, CONTAINER>::end()
{
	return (this->c.rend());
}

template <typename TYPE, typename CONTAINER>
typename std::stack<TYPE, CONTAINER>::container_type::const_reverse_iterator	MutantStack<TYPE, CONTAINER>::end() const
{
	return (this->c.rend());
}

template <typename TYPE, typename CONTAINER>
typename std::stack<TYPE, CONTAINER>::container_type::iterator	MutantStack<TYPE, CONTAINER>::rbegin()
{
	return (this->c.begin());
}

template <typename TYPE, typename CONTAINER>
typename std::stack<TYPE, CONTAINER>::container_type::const_iterator	MutantStack<TYPE, CONTAINER>::rbegin() const
{
	return (this->c.begin());
}

template <typename TYPE, typename CONTAINER>
typename std::stack<TYPE, CONTAINER>::container_type::iterator		MutantStack<TYPE, CONTAINER>::rend()
{
	return (this->c.end());
}

template <typename TYPE, typename CONTAINER>
typename std::stack<TYPE, CONTAINER>::container_type::const_iterator	MutantStack<TYPE, CONTAINER>::rend() const
{
	return (this->c.end());
}
