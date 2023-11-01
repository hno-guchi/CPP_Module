/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/01 13:40:16 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include "debugMessage.hpp"

template <typename T>
class MutantStack : public std::stack<T> {
// private:
	// SUBJECT ATTRIBUTE
	// MY ATTRIBUTE
public:
	// CONSTRUCTOR
	MutantStack();
	MutantStack(const MutantStack& other);
	// DESTRUCTOR
	~MutantStack();
	// OPERATOR
	MutantStack&	operator=(const MutantStack& other);

	// GETTER
	// SETTER
	// SUBJECT FUNC
	typedef typename std::deque<T>::iterator			iterator;
	typedef typename std::deque<T>::const_iterator	const_iterator;

	iterator		begin();
	const_iterator	begin() const;
	iterator		end();
	const_iterator	end() const;
};

#include "MutantStack.tpp"

#endif
