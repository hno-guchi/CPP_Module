/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:31:58 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/01 17:26:43 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "color.hpp"
#include "MutantStack.hpp"

#ifdef MY_TEST

void	printStack(const std::string& sub, const MutantStack<int>& mstack)
{
	std::cout << YELLOW << "----- [" << sub << "] -----" << END << std::endl;

	for (MutantStack<int>::const_iterator itr = mstack.begin(); itr != mstack.end(); ++itr) {
		std::cout << "[" << *itr << "]" << std::flush;
		if ((itr + 1) != mstack.end()) {
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
	printStack("mstack0", mstack0);
	std::cout << std::endl;
	mstack3 = mstack0;
	printStack("mstack3", mstack3);

	// d.end();を超えたitrの挙動を確認。エラーなく進む。
	// std::deque<int>		d;
	// d.push_back(0); d.push_back(1); d.push_back(2);
	// std::deque<int>::iterator itr = d.begin();
	// for (int i = 0; i < 5; i++) {
	// 	std::cout << *itr << std::flush;
	// 	itr++;
	// }

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
