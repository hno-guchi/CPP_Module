/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:38:00 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/12 17:45:27 by hnoguchi         ###   ########.fr       */
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

void	Harl::executeFunction(eLevel level)
{
	switch(level) {
		case DEBUG:
			this->executeDebug();
			break ;
		case INFO:
			this->executeInfo();
			break ;
		case WARNING:
			this->executeWarning();
			break ;
		case ERROR:
			this->executeError();
			break ;
		default:
			throw std::runtime_error("Error: Not exist level [NOT].");
			break ;
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
				this->executeFunction(DEBUG);
				break ;
			case 1:
				this->executeFunction(INFO);
				break ;
			case 2:
				this->executeFunction(WARNING);
				break ;
			case 3:
				this->executeFunction(ERROR);
				break ;
			default:
				this->executeFunction(NOT);
				break ;
		}
	}
	catch (const std::runtime_error &e) {
		std::cout << e.what() << std::endl;
	}
}
