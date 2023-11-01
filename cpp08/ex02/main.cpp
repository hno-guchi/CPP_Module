/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:31:58 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/01 13:23:31 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "color.hpp"
#include "MutantStack.hpp"

#ifdef TEST

#ifdef CONSTRUCT

int main()
{
	MutantStack<int>	mstack0;
	MutantStack<int>	mstack1(mstack0);
	MutantStack<int>	mstack3;

	mstack3 = mstack0;

#ifdef LEAKS
	system("leaks -q ex02");
#endif
	return (0);
}

#endif // CONSTRUCT

#else // TEST

int main()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	(void)it;
	(void)ite;
	// ++it;
	// --it;
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	std::stack<int> s(mstack);
#ifdef LEAKS
	system("leaks -q ex02");
#endif
	return (0);
}

#endif // TEST
