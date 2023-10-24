/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:49:32 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/24 19:25:37 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int	main()
{
	Array<int>		i;
	Array<int>	ary(100);
	Array<int>	ary2(ary);

	std::cout << "   i: ptr[" << &(i[0]) << "] | size[" << i.size() << "]" << std::endl;
	std::cout << " ary: ptr[" << &(ary[0]) << "] | size[" << ary.size() << "]" << std::endl;
	std::cout << "ary2: ptr[" << &(ary2[0]) << "] | size[" << ary2.size() << "]" << std::endl;
	i = ary;
	std::cout << "   i: ptr[" << &(i[0]) << "] | size[" << i.size() << "]" << std::endl;
	
	// int num = i[-1];
	// std::cout << num << std::endl;
	int num = i[100];
	std::cout << num << std::endl;
#ifdef LEAKS
	system("leaks -q ex02");
#endif
}
