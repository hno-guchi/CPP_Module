/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/01 18:59:24 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <list>
#include <vector>
#include "debugMessage.hpp"

template <typename TYPE>
class MutantStack : public std::stack<TYPE> {
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
	typedef typename std::stack<TYPE>::container_type::reverse_iterator			iterator;
	typedef typename std::stack<TYPE>::container_type::const_reverse_iterator	const_iterator;
	iterator				begin();
	const_iterator			begin() const;
	iterator				end();
	const_iterator			end() const;

	typedef typename std::stack<TYPE>::container_type::iterator					reverse_iterator;
	typedef typename std::stack<TYPE>::container_type::const_iterator			const_reverse_iterator;
	reverse_iterator		rbegin();
	const_reverse_iterator	rbegin() const;
	reverse_iterator		rend();
	const_reverse_iterator	rend() const;
};

#include "MutantStack.tpp"

#endif
