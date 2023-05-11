/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:38:00 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/11 21:26:07 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug()
{
	std::cout
		<< GREEN << "DEBUG" << END
		<< ": Debug message."
		<< std::endl;
}

void	Harl::info()
{
	std::cout
		<< MAGENTA << "INFO" << END
		<< ": Info message."
		<< std::endl;
}

void	Harl::warning()
{
	std::cout
		<< YELLOW << "WARNING" << END
		<< ": Warning message."
		<< std::endl;

}

void	Harl::error()
{
	std::cout
		<< RED << "ERROR" << END
		<< ": Error message."
		<< std::endl;
}

void	Harl::complain(std::string level)
{
	static std::string	levelList[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
		"",
	};
	unsigned int	i(0);
	const void (*levelFunc)() = NULL;

	while (level != levelList[i] && levelList[i] != "") {
		i += 1;
	}
	try {
		switch (i) {
			case 0:
				levelFunc = getLevelFunction(DEBUG);
				break ;
			case 1:
				levelFunc = getLevelFunction(INFO);
				break ;
			case 2:
				levelFunc = getLevelFunction(WARNING);
				break ;
			case 3:
				levelFunc = getLevelFunction(ERROR);
				break ;
			default:
				// TODO
				throw ;
				break ;
		}
	}
	catch () {
		return ;
	}
	levelFunc();
}
