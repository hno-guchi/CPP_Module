/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:23:39 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/06/02 16:42:11 by hnoguchi         ###   ########.fr       */
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

	Character	character1("hnoguchi");	std::cout << std::endl;

	cure2.use(character1);
	cure5->use(character1);
	std::cout << YELLOW << "========================" << END << "\n" << std::endl;

	std::cout << RED << "====== DESTRUCTOR =====" << END << std::endl;
	delete cure4;	std::cout << std::endl;

#ifdef LEAKS
	system("leaks -q ex03");
#endif
}

#elif M_SOURCE

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int	main()
{
	std::cout << GREEN << "====== CONSTRUCT =======" << END << std::endl;
	MateriaSource	mSource1;			std::cout << std::endl;
	MateriaSource	mSource2(mSource1);	std::cout << std::endl;
	MateriaSource	mSource3;			std::cout << std::endl;

	std::cout << GREEN << "========================" << END << "\n" << std::endl;

	mSource1.learnMateria(new Cure());	std::cout << std::endl;
	mSource1.learnMateria(new Ice());	std::cout << std::endl;
	mSource1.learnMateria(new Cure());	std::cout << std::endl;
	mSource1.learnMateria(new Ice());	std::cout << std::endl;

	mSource2.learnMateria(new Cure());	std::cout << std::endl;
	mSource2.learnMateria(new Ice());	std::cout << std::endl;

	mSource3 = mSource2;					std::cout << std::endl;

	std::cout << YELLOW << "====== DO FUNCTION =====" << END << std::endl;
	mSource1.printLearnedList();
	mSource2.printLearnedList();
	mSource3.printLearnedList();

	mSource1.learnMateria(new Cure());	std::cout << std::endl;
	mSource1.learnMateria(NULL);		std::cout << std::endl;
	mSource2.learnMateria(NULL);		std::cout << std::endl;

	AMateria*	cure1 = mSource1.createMateria("cure");
	AMateria*	ice1 = mSource1.createMateria("ice");
	AMateria*	wrong = mSource1.createMateria("wrong");

	Character	character1("hnoguchi");	std::cout << std::endl;

	cure1->use(character1);
	ice1->use(character1);
	if (wrong == NULL) {
		std::cout << "wrong Address: [" << &wrong << "]" << std::endl;
	}
	else {
		wrong->use(character1); // Segmentation fault
	}
	std::cout << YELLOW << "========================" << END << "\n" << std::endl;

	std::cout << RED << "====== DESTRUCTOR =====" << END << std::endl;
	delete cure1;
	delete ice1;

#ifdef LEAKS
	system("leaks -q ex03");
#endif
}

#elif CHARACTER

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int	main()
{
	std::cout << GREEN << "====== CONSTRUCT =======" << END << std::endl;
	Character	character1;					std::cout << std::endl;
	Character	character2("hnoguchi_2");	std::cout << std::endl;
	Character	character3;					std::cout << std::endl;

	std::cout << GREEN << "========================" << END << "\n" << std::endl;

	character1.setName("hnoguchi_1");	std::cout << std::endl;
	character1.equip(new Cure());		std::cout << std::endl;
	character1.equip(new Ice());		std::cout << std::endl;
	character1.equip(new Cure());		std::cout << std::endl;
	character1.equip(new Ice());		std::cout << std::endl;

	character2.equip(new Cure());		std::cout << std::endl;
	character2.equip(new Ice());		std::cout << std::endl;

	character3 = character2;			std::cout << std::endl;

	std::cout << YELLOW << "====== DO FUNCTION =====" << END << std::endl;
	character1.printData();
	character2.printData();
	character3.printData();

	std::cout << "\nequip() test ------------------------------" << std::endl;
	character1.equip(new Cure());
	character1.equip(NULL);
	character2.equip(NULL);

	std::cout << "\nunequip() test ----------------------------" << std::endl;
	const AMateria*	releasedMateria;

	releasedMateria = character1.getMateria(3);
	character1.unequip(3);
	delete releasedMateria;						std::cout << std::endl;
	// character1.printData();

	releasedMateria = character1.getMateria(1);
	character1.unequip(1);
	delete releasedMateria;						std::cout << std::endl;
	// character1.printData();

	releasedMateria = character1.getMateria(0);
	character1.unequip(0);
	delete releasedMateria;						std::cout << std::endl;
	// character1.printData();

	releasedMateria = character2.getMateria(3);
	character2.unequip(3);
	delete releasedMateria;						std::cout << std::endl;

	releasedMateria = character1.getMateria(4);
	character1.unequip(4);
	delete releasedMateria;						std::cout << std::endl;

	character1.printData();	std::cout << std::endl;
	character2.printData();	std::cout << std::endl;
	character3.printData();	std::cout << std::endl;

	std::cout << "\nuse() test --------------------------------" << std::endl;
	character1.use(0, character2);
	character2.use(1, character1);
	// character1.use(1, NULL); // Compile Error: error: non-const lvalue reference to type 'ICharacter' cannot bind to a temporary of type 'long'

	std::cout << YELLOW << "========================" << END << "\n" << std::endl;

	std::cout << RED << "====== DESTRUCTOR =====" << END << std::endl;

#ifdef LEAKS
	system("leaks -q ex03");
#endif
}

#elif WHILE_LEAKS

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <unistd.h>

int main()
{
	while (1) {
		IMateriaSource*	src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter*	me = new Character("me");
		AMateria*	tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);

		ICharacter*	bob = new Character("bob");

		// me->use(0, *bob);
		// me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
		// sleep(1);
	}
	return (0);
}

#else

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
	IMateriaSource*	src = new MateriaSource();	std::cout << std::endl;

	src->learnMateria(new Ice());			std::cout << std::endl;
	src->learnMateria(new Cure());				std::cout << std::endl;

	ICharacter*	me = new Character("me");		std::cout << std::endl;
	AMateria*	tmp;							std::cout << std::endl;

	tmp = src->createMateria("ice");			std::cout << std::endl;
	me->equip(tmp);								std::cout << std::endl;
	tmp = src->createMateria("cure");			std::cout << std::endl;
	me->equip(tmp);								std::cout << std::endl;

	ICharacter*	bob = new Character("bob");		std::cout << std::endl;

	me->use(0, *bob);							std::cout << std::endl;
	me->use(1, *bob);							std::cout << std::endl;

	delete bob;
	delete me;
	delete src;
#ifdef LEAKS
	system("leaks -q ex03");
#endif
	return (0);
}

#endif
