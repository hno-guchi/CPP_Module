/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:03:10 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/26 18:04:23 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifdef CAT
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
	// CONSTRUCTER
	std::cout << GREEN << "====== CONSTRUCT =======" << END << std::endl;
	Cat	cat0; std::cout << std::endl;
	Cat	cat1 = Cat("Cat"); std::cout << std::endl;
	Cat	cat2(cat1);
	std::cout << GREEN << "========================" << END << "\n" << std::endl;

	// DEEP COPY
	cat0.setBrainIdea("cat0 idea.");
	cat1.setBrainIdea("cat1 idea.");
	cat2.setBrainIdea("cat2 idea.");

	std::cout << YELLOW << "====== DEEP COPY =====" << END << std::endl;
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
	cat2 = cat1; std::cout << std::flush;
	printBrainAddress("used operator=() : ", cat2);

	std::cout << YELLOW << "========================" << END << "\n" << std::endl;

	std::cout << RED << "====== DESTRUCTOR =====" << END << std::endl;

	system("leaks -q ex02");
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
	// CONSTRUCTER
	std::cout << GREEN << "====== CONSTRUCT =======" << END << std::endl;
	Dog	dog0; std::cout << std::endl;
	Dog	dog1 = Dog("Dog"); std::cout << std::endl;
	Dog	dog2(dog1);
	std::cout << GREEN << "========================" << END << "\n" << std::endl;

	// DEEP COPY
	dog0.setBrainIdea("dog0 idea.");
	dog1.setBrainIdea("dog1 idea.");
	dog2.setBrainIdea("dog2 idea.");

	std::cout << YELLOW << "====== DEEP COPY =====" << END << std::endl;
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
	dog2 = dog1; std::cout << std::flush;
	printBrainAddress("used operator=() : ", dog2);

	std::cout << YELLOW << "========================" << END << "\n" << std::endl;

	std::cout << RED << "====== DESTRUCTOR =====" << END << std::endl;

	system("leaks -q ex02");
}

#else

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << GREEN << "====== CONSTRUCT =======" << END << std::endl;
	// Compile Error: allocating an object of abstract class type 'Animal'
	// const Animal*	wrong = new Animal(); std::cout << std::endl;
	const Animal*	j = new Dog(); std::cout << std::endl;
	const Animal*	i = new Cat(); std::cout << std::endl;
	Animal*			animals[10];

	int	index = 0;
	while (index < (10 / 2)) {
		animals[index] = new Dog();
		index += 1;
	}
	while (index < 10) {
		animals[index] = new Cat();
		index += 1;
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
	system("leaks -q ex02");
#endif //LEAKS

	return (0);
}

#endif
