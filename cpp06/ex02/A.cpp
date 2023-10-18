/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/18 15:38:23 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// CONSTRUCTER
A::A()
{
	debugMessage("A", DEFAULT_CONSTRUCT);
}

// DESTRUCTER
A::~A()
{
	debugMessage("A", DESTRUCT);
}

// GETTER

// SETTER

// SUBJECT FUNC
Base*	A::generate(void)
{
	Base		*ptr = NULL;
	const int	flag = std::rand() % 3;

	try {
		switch (flag) {
			case 0:
				ptr = new A();
				break;
			case 1:
				ptr = new B();
				break;
			case 2:
				ptr = new C();
				break;
			default:
				std::cerr << RED << "Error: ivalied." << END << std::endl;
				break;
		}
	}
	catch (std::exception& e) {
		std::cerr << RED << e.what() << END << std::endl;
	}
	return (ptr);
}

void	A::identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "p: A" << std::endl;
	}
	else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "p: B" << std::endl;
	}
	else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "p: C" << std::endl;
	}
	else {
		std::cout << "p: Other" << std::endl;
	}
}

void	A::identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "p: A" << std::endl;
		return ;
	}
	catch (std::bad_cast& e) {
		;
		// std::cerr << RED << e.what() << END << std::endl;
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "p: B" << std::endl;
		return ;
	}
	catch (std::bad_cast& e) {
		;
		// std::cerr << RED << e.what() << END << std::endl;
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "p: C" << std::endl;
		return ;
	}
	catch (std::bad_cast& e) {
		;
		// std::cerr << RED << e.what() << END << std::endl;
	}
}

