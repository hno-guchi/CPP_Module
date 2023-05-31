/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:23:39 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/31 18:18:10 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef MATERIA

#include "Cure.hpp"

int	main()
{
	std::cout << GREEN << "====== CONSTRUCT =======" << END << std::endl;
	Cure			cure1;			std::cout << std::endl;
	Cure			cure2("cure");	std::cout << std::endl;
	Cure			cure3(cure2);	std::cout << std::endl;

	cure1 = cure3;					std::cout << std::endl;

	std::cout << "----- wrong args -----" << std::endl;
	Cure			wrongArgs("fire");
	std::cout << GREEN << "========================" << END << "\n" << std::endl;

	std::cout << YELLOW << "====== DO FUNCTION =====" << END << std::endl;
	const AMateria*	cure4 = cure1.clone();
	AMateria*		cure5 = cure2.clone();

	std::cout << "cure1[" << &cure1 << "]" << std::endl;
	std::cout << "cure2[" << &cure2 << "]" << std::endl;
	std::cout << "cure3[" << &cure3 << "]" << std::endl;
	std::cout << "cure4[" << cure4 << "]" << std::endl;

	cure2.use();
	cure5->use();
	std::cout << YELLOW << "========================" << END << "\n" << std::endl;

	std::cout << RED << "====== DESTRUCTOR =====" << END << std::endl;
	delete cure4;	std::cout << std::endl;

	system("leaks -q ex03");
}

#else

#include "Character.hpp"

int main()
{
	IMateriaSource*	src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// ICharacter*	me = new Character("me");
	AMateria*	tmp;

	tmp = src->createMateria("ice");
	// me->equip(tmp);
	tmp = src->createMateria("cure");
	// me->equip(tmp);

	// ICharacter*	bob = new Character("bob");

	// me->use(0, *bob);
	// me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return (0);
}

#endif
