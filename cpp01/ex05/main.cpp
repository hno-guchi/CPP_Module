/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:34:48 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/12 17:51:01 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl	obj;

	std::cout
		<< "\n" << GREEN << "===== SUCCESS CASE =====" << END
		<< std::endl;
	obj.complain("DEBUG");
	obj.complain("INFO");
	obj.complain("WARNING");
	obj.complain("ERROR");

	// warong args
	std::cout
		<< "\n" << RED << "===== WARONG CASE =====" << END
		<< std::endl;
	obj.complain("debug");
	obj.complain("info");
	obj.complain("WaRNING");
	obj.complain("ERRor");
	obj.complain("42Tokyo");
	obj.complain("");

#ifdef LEAKS
	system("leaks -q ex05");
#endif
}
