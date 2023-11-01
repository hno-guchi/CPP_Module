/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:31:58 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/01 19:21:53 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "color.hpp"
#include "MutantStack.hpp"
#include <list>

#ifdef MY_TEST

template <typename CONTAINER_TYPE>
void	printElement(const std::string& sub, const std::string& type, const CONTAINER_TYPE& container)
{
	typename CONTAINER_TYPE::const_iterator eitr = container.end();

	eitr--;
	std::cout << YELLOW << "----- [" << sub << "(" << type << ")] -----" << END << std::endl;
	for (typename CONTAINER_TYPE::const_iterator itr = container.begin(); itr != container.end(); ++itr) {
		std::cout << "[" << *itr << "]" << std::flush;
		if (itr != eitr) {
			std::cout << " -> " << std::flush;
		}
	}
	std::cout << std::endl;
}

int main()
{
	MutantStack<int>	mstack0;
	MutantStack<int>	mstack1(mstack0);
	MutantStack<int>	mstack3;

	mstack0.push(0); mstack0.push(1); mstack0.push(2); mstack0.push(3); mstack0.push(4);
	printElement("mstack0", "std::deque<int>", mstack0); std::cout << std::endl;

	mstack3 = mstack0;
	printElement("mstack3", "std::deque<int>", mstack3); std::cout << std::endl;

	std::list<int>	list0;
	list0.push_front(0); list0.push_front(1); list0.push_front(2); list0.push_front(3); list0.push_front(4);
	printElement("list0", "std::list<int>", list0);
#ifdef LEAKS
	system("leaks -q ex02");
#endif
	return (0);
}

#else // MY_TEST

int main()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "mstack.top(); [" << mstack.top() << "]" << std::endl;
	mstack.pop();
	std::cout << "after pop();  [" << mstack.size() << "]" << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	for (; it != ite; ++it) {
		std::cout << "[" << *it << "]" << std::flush;
		if ((it + 1) != ite) {
			std::cout << " -> " << std::flush;
		}
	}
	std::cout << std::endl;

	std::stack<int> s(mstack);
	for (std::size_t i = s.size(); 0 < i; --i) {
		std::cout << "[" << s.top() << "]" << std::flush;
		if (i != 1) {
			std::cout << " -> " << std::flush;
		}
		s.pop();
	}
	std::cout << std::endl;

#ifdef LEAKS
	system("leaks -q ex02");
#endif
	return (0);
}

#endif // MY_TEST
