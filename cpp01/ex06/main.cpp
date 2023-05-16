/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:34:48 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/16 18:36:07 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout
			<< RED << "[ Wrong argument ]" << END
			<< std::endl;
		return (1);
	}
	Harl	obj;

	obj.complain(argv[1]);

#ifdef LEAKS
	system("leaks -q harlFilter");
#endif
}
