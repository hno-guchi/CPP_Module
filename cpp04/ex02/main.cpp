/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:03:10 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/28 10:49:17 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << GREEN << "====== CONSTRUCT =======" << END << std::endl;
	// Compile Error: allocating an object of abstract class type 'Animal'
	// const Animal*	wrong = new Animal(); std::cout << std::endl;
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

	std::cout << YELLOW << "====== DO FUNCTION =====" << END << std::endl;
	j->makeSound(); //dog
	i->makeSound(); //cat
	std::cout << YELLOW << "========================" << END << "\n" << std::endl;

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
