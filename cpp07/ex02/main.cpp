/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:49:32 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/24 17:56:57 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int	main()
{
	Array<int>		i;
	Array<float>	ary(100);

	std::cout << "i.size(); "<< i.size() << std::endl;
	std::cout << "ary.size(); "<< ary.size() << std::endl;

#ifdef LEAKS
	system("leaks -q ex02");
#endif
}
