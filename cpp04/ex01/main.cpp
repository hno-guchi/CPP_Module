/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:03:10 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/28 17:17:51 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifdef BRAIN
#include "Brain.hpp"

static void	testMemberFunction(const std::string& prefix, const Brain& object)
{
	std::cout \
		<< "\n===== " << GREEN << prefix << END << " ========\n" \
		<< "ideasSize    : [" << object.getIdeaArraySize() << "]  |\n" \
		<< "currentindex : [" << object.getLastIndex() << "]  |\n" \
		<< "ideas[" << object.getLastIndex() << "]     : " \
		<< std::endl;
		for (unsigned int i = 0; i < object.getLastIndex(); i++) {
			std::cout << "[" << i << "] : [" << object.getIdea(i) << "]" << std::endl;
		}
	std::cout << "=====================" << std::endl;
}

int	main()
{
	// CONSTRUCTER
	std::cout << GREEN << "====== CONSTRUCT =======" << END << std::endl;
	Brain	brain0; std::cout << std::endl;
	Brain	brain1 = Brain("First idea."); std::cout << std::endl;
	Brain	brain2(brain1);
	std::cout << GREEN << "========================" << END << "\n" << std::endl;

	// MEMBER
	std::cout << YELLOW << "====== DO FUNCTION =====" << END << std::endl;
	brain0.setIdea("Brain0 Idea.");

	// WRONG
	brain0.setIdea("");
	std::string	idea = brain2.getIdea(10);

	testMemberFunction("brain0", brain0);
	testMemberFunction("brain1", brain1);
	testMemberFunction("brain2", brain2);
	std::cout << YELLOW << "========================" << END << "\n" << std::endl;

	std::cout << RED << "====== DESTRUCTOR =====" << END << std::endl;
}

#elif CAT
#include "Cat.hpp"

static void	printBrainAddress(const std::string& prefix, const Cat& object)
{
	std::cout \
		<< GREEN << prefix << "[" << object.getBrain() << "]" << END \
		<< " | " << object.getBrainIdea(0) \
		<< std::endl;
}

int	main()
{
	// while (1) {
		// CONSTRUCTER
		std::cout << GREEN << "====== CONSTRUCT =======" << END << std::endl;
		Cat	cat0; std::cout << std::endl;
		Cat	cat1 = Cat("Cat"); std::cout << std::endl;

		cat0.setBrainIdea("cat0 idea.");
		cat1.setBrainIdea("cat1 idea.");

		Brain*	cat2_brain = new Brain("cat2 idea."); std::cout << std::endl;
		Cat		cat2 = Cat(cat0);
		std::cout << GREEN << "========================" << END << "\n" << std::endl;

		// DEEP COPY
		std::cout << YELLOW << "====== DEEP COPY =====" << END << std::endl;
		// copy constructer
		std::cout << "\n----- copy constructer ----------------" << std::endl;
		std::cout << "[cat0]" << std::endl;
		printBrainAddress("copy const(src)  : ", cat0);
		std::cout << "[cat2]" << std::endl;
		printBrainAddress("copy const(dst)  : ", cat2);

		cat2.setBrain(*cat2_brain);

		// copy operator(=)
		std::cout << "\n\n----- copy operator(=); ------------" << std::endl;
		std::cout << "[cat0]" << std::endl;
		printBrainAddress("Before           : ", cat0);
		cat0 = cat1; std::cout << std::flush;
		printBrainAddress("used operator=() : ", cat0);

		std::cout << "\n[cat1]" << std::endl;
		printBrainAddress("Before           : ", cat1);
		cat1 = cat2; std::cout << std::flush;
		printBrainAddress("used operator=() : ", cat1);

		std::cout << "\n[cat2]" << std::endl;
		printBrainAddress("Before           : ", cat2);
		cat2 = cat0; std::cout << std::flush;
		printBrainAddress("used operator=() : ", cat2);

		std::cout << YELLOW << "========================" << END << "\n" << std::endl;

		std::cout << RED << "====== DESTRUCTOR =====" << END << std::endl;

		delete cat2_brain; std::cout << std::endl;

		system("leaks -q ex01");
	// }
}

#elif DOG
#include "Dog.hpp"

static void	printBrainAddress(const std::string& prefix, const Dog& object)
{
	std::cout \
		<< GREEN << prefix << "[" << object.getBrain() << "]" << END \
		<< " | " << object.getBrainIdea(0) \
		<< std::endl;
}

int	main()
{
	// while (1) {
		// CONSTRUCTER
		std::cout << GREEN << "====== CONSTRUCT =======" << END << std::endl;
		Dog	dog0;				std::cout << std::endl;
		Dog	dog1 = Dog("Dog");	std::cout << std::endl;

		dog0.setBrainIdea("dog0 idea.");
		dog1.setBrainIdea("dog1 idea.");

		Brain*	dog2_brain = new Brain("dog2 idea."); std::cout << std::endl;
		Dog		dog2 = Dog(dog0);
		std::cout << GREEN << "========================" << END << "\n" << std::endl;

		// DEEP COPY
		std::cout << YELLOW << "====== DEEP COPY =====" << END << std::endl;
		// copy constructer
		std::cout << "\n----- copy constructer ----------------" << std::endl;
		std::cout << "[dog0]" << std::endl;
		printBrainAddress("copy const(src)  : ", dog0);
		std::cout << "[dog2]" << std::endl;
		printBrainAddress("copy const(dst)  : ", dog2);

		dog2.setBrain(*dog2_brain);

		// copy operator(=)
		std::cout << "\n\n----- copy operator(=); ------------" << std::endl;
		std::cout << "[dog0]" << std::endl;
		printBrainAddress("Before           : ", dog0);
		dog0 = dog1; std::cout << std::flush;
		printBrainAddress("used operator=() : ", dog0);

		std::cout << "\n[dog1]" << std::endl;
		printBrainAddress("Before           : ", dog1);
		dog1 = dog2; std::cout << std::flush;
		printBrainAddress("used operator=() : ", dog1);

		std::cout << "\n[dog2]" << std::endl;
		printBrainAddress("Before           : ", dog2);
		dog2 = dog0; std::cout << std::flush;
		printBrainAddress("used operator=() : ", dog2);

		std::cout << YELLOW << "========================" << END << "\n" << std::endl;

		std::cout << RED << "====== DESTRUCTOR =====" << END << std::endl;

		delete dog2_brain; std::cout << std::endl;

		system("leaks -q ex01");
	// }
}

#else

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << GREEN << "====== CONSTRUCT =======" << END << std::endl;
	const Animal*	j = new Dog(); std::cout << std::endl;
	const Animal*	i = new Cat(); std::cout << std::endl;
	Animal*			animals[10]; std::cout << std::endl;

	std::cout << "----- animals construct --------\n" << std::endl;
	int	index = 0;
	while (index < (10 / 2)) {
		std::cout << GREEN << "[" << index << "]" << END << std::endl;
		animals[index] = new Dog();
		index += 1;
		std::cout << std::endl;
	}
	while (index < 10) {
		std::cout << GREEN << "[" << index << "]" << END << std::endl;
		animals[index] = new Cat();
		index += 1;
		std::cout << std::endl;
	}
	std::cout << GREEN << "========================" << END << "\n" << std::endl;

	std::cout << RED << "====== DESTRUCTOR =====" << END << std::endl;
	delete i; std::cout << std::endl;
	delete j; std::cout << std::endl;

	// Compile error : error: cannot delete expression of type 'Animal *[10]'
	// delete[] animals;

	std::cout << "\n----- animals destruc -----\n" << std::endl;
	for (int idx = 0; idx < 10; idx++) {
		std::cout << RED << "[" << idx << "]" << END << std::endl;
		delete animals[idx]; std::cout << std::endl;
	}

#ifdef LEAKS
	system("leaks -q ex01");
#endif //LEAKS

	return (0);
}

#endif
