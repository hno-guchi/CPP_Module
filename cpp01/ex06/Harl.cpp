/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:38:00 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/16 18:32:32 by hnoguchi         ###   ########.fr       */
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
		<< GREEN << "[ DEBUG ]" << END
		<< std::endl;
	std::cout
		<< "Debug message.\n"
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< std::endl;
}

void	Harl::info()
{
	std::cout
		<< MAGENTA << "[ INFO ]" << END
		<< std::endl;
	std::cout
		<< "Info message.\n"
		<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl;
}

void	Harl::warning()
{
	std::cout
		<< YELLOW << "[ WARNING ]" << END
		<< std::endl;
	std::cout
		<< "Warning message.\n"
		<< "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
		<< std::endl;

}

void	Harl::error()
{
	std::cout
		<< RED << "[ ERROR ]" << END
		<< std::endl;
	std::cout
		<< "Error message.\n"
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

void	Harl::executeDebug()
{
	funcPtr	ptr = &Harl::debug;
	(this->*ptr)();
}
void	Harl::executeInfo()
{
	funcPtr	ptr = &Harl::info;
	(this->*ptr)();
}

void	Harl::executeWarning()
{
	funcPtr	ptr = &Harl::warning;
	(this->*ptr)();
}

void	Harl::executeError()
{
	funcPtr	ptr = &Harl::error;
	(this->*ptr)();
}

void	Harl::harlFilter(unsigned int level)
{
	static funcPtr		ptrList[] = {
		&Harl::executeDebug,
		&Harl::executeInfo,
		&Harl::executeWarning,
		&Harl::executeError,
	};

	while (level < LEVEL_MAX_COUNT) {
		(this->*ptrList[level])();
		std::cout << std::endl;
		level += 1;
	}
}

void	Harl::complain(std::string level)
{
	unsigned int		i(0);
	static std::string	levelList[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
		"",
	};

	while (level != levelList[i] && levelList[i] != "") {
		i += 1;
	}
	try {
		switch (i) {
			case 0:
				this->harlFilter(i);
				break ;
			case 1:
				this->harlFilter(i);
				break ;
			case 2:
				this->harlFilter(i);
				break ;
			case 3:
				this->harlFilter(i);
				break ;
			default:
				throw std::runtime_error("[ Probably complaining about insignificant problems ]");
				break ;
		}
	}
	catch (const std::runtime_error &e) {
		std::cout
			<< RED << e.what() << END
			<< std::endl;
	}
}
