/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:46:07 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/18 11:01:01 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "color.hpp"

int	main()
{
	Data		data;
	uintptr_t	uint = Serializer::serialize(&data);
	Data		*ptr = Serializer::deserialize(uint);

	std::cout << GREEN << "++++++++++++++++++++++++++++++++++++++++" << END << std::endl;
	std::cout << "        Data ptr : [" << &data << "]" << std::endl;
	std::cout << "deserialized ptr : [" << ptr << "]" << std::endl;

	// std::cout << std::endl;

	// uint = Serializer::serialize(NULL);
	// ptr = Serializer::deserialize(uint);
	// std::cout << GREEN << "++++++++++++++++++++++++++++++++++++++++" << END << std::endl;
	// std::cout << "        Data ptr : [" << NULL << "]" << std::endl;
	// std::cout << "deserialized ptr : [" << ptr << "]" << std::endl;

	// Compile error
	// int	*iptr;
	// uint = Serializer::serialize(iptr);
}
