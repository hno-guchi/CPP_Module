/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:03:10 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/25 19:12:48 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifdef ANIMAL
#include "Animal.hpp"

static void	testMemberFunction(const std::string& prefix, const Animal& object)
{
	std::cout
		<< GREEN << prefix << END
		<< " : type: [" << object.getType() << "]"
		<< " sound : " << std::flush;
	object.makeSound();
}

int	main()
{
	// CONSTRUCTER
	std::cout << GREEN << "====== CONSTRUCT =======" << END << std::endl;
	Animal			animal_0; std::cout << std::endl;
	Animal			animal_1 = Animal("Animal_1"); std::cout << std::endl;
	Animal			animal_2(animal_1);
	std::cout << GREEN << "========================" << END << "\n" << std::endl;

	// MEMBER
	std::cout << YELLOW << "====== DO FUNCTION =====" << END << std::endl;
	animal_0.setType("Animal_0");

	testMemberFunction("animal_0", animal_0);
	testMemberFunction("animal_1", animal_1);
	testMemberFunction("animal_2", animal_2);
	std::cout << YELLOW << "========================" << END << "\n" << std::endl;

	std::cout << RED << "====== DESTRUCTOR =====" << END << std::endl;
}

#elif CAT

#include "Cat.hpp"

static void	testMemberFunction(const std::string& prefix, const Cat& object)
{
	std::cout
		<< GREEN << prefix << END
		<< " : type: [" << object.getType() << "]"
		<< " sound : " << std::flush;
	object.makeSound();
}

int	main()
{
	// CONSTRUCTER
	std::cout << GREEN << "====== CONSTRUCT =======" << END << std::endl;
	Cat			cat0; std::cout << std::endl;
	Cat			cat1 = Cat("Cat"); std::cout << std::endl;
	Cat			cat2(cat1);
	std::cout << GREEN << "========================" << END << "\n" << std::endl;

	// MEMBER
	std::cout << YELLOW << "====== DO FUNCTION =====" << END << std::endl;
	cat0.setType("Cat");

	// WRONG ARGS
	cat1.setType("cat");
	cat2.setType("Dog");

	testMemberFunction("cat0", cat0);
	testMemberFunction("cat1", cat1);
	testMemberFunction("cat2", cat2);
	std::cout << YELLOW << "========================" << END << "\n" << std::endl;

	std::cout << RED << "====== DESTRUCTOR =====" << END << std::endl;
}

#elif DOG

#include "Dog.hpp"

static void	testMemberFunction(const std::string& prefix, const Dog& object)
{
	std::cout
		<< GREEN << prefix << END
		<< " : type: [" << object.getType() << "]"
		<< " sound : " << std::flush;
	object.makeSound();
}

int	main()
{
	// CONSTRUCTER
	std::cout << GREEN << "====== CONSTRUCT =======" << END << std::endl;
	Dog			dog0; std::cout << std::endl;
	Dog			dog1 = Dog("Dog"); std::cout << std::endl;
	Dog			dog2(dog1);
	std::cout << GREEN << "========================" << END << "\n" << std::endl;

	// MEMBER
	std::cout << YELLOW << "====== DO FUNCTION =====" << END << std::endl;
	dog0.setType("Dog");

	// WRONG ARGS
	dog1.setType("dog");
	dog2.setType("cat");

	testMemberFunction("dog0", dog0);
	testMemberFunction("dog1", dog1);
	testMemberFunction("dog2", dog2);
	std::cout << YELLOW << "========================" << END << "\n" << std::endl;

	std::cout << RED << "====== DESTRUCTOR =====" << END << std::endl;
}

#elif WRONG

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << GREEN << "====== CONSTRUCT =======" << END << std::endl;
	const WrongAnimal*	meta = new WrongAnimal(); std::cout << std::endl;
	// const WrongAnimal*	j = new Dog(); std::cout << std::endl;
	const WrongAnimal*	i = new WrongCat();
	std::cout << GREEN << "========================" << END << "\n" << std::endl;

	std::cout << YELLOW << "====== DO FUNCTION =====" << END << std::endl;
	// std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;

	i->makeSound(); //will output the cat sound!
	// j->makeSound();
	meta->makeSound();
	std::cout << YELLOW << "========================" << END << "\n" << std::endl;

	std::cout << RED << "====== DESTRUCTOR =====" << END << std::endl;
	delete i;
	// delete j;
	delete meta;

	return (0);
}

#else

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << GREEN << "====== CONSTRUCT =======" << END << std::endl;
	const Animal*	meta = new Animal(); std::cout << std::endl;
	const Animal*	j = new Dog(); std::cout << std::endl;
	const Animal*	i = new Cat();
	std::cout << GREEN << "========================" << END << "\n" << std::endl;

	std::cout << YELLOW << "====== DO FUNCTION =====" << END << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << YELLOW << "========================" << END << "\n" << std::endl;

	std::cout << RED << "====== DESTRUCTOR =====" << END << std::endl;
	delete i;
	delete j;
	delete meta;

#ifdef LEAKS
	system("leaks -q ex00");
#endif //LEAKS

	return (0);
}

#endif
