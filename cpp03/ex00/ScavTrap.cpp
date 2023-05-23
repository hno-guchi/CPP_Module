/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:58:05 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/23 12:23:58 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap : " << std::flush;
	writeMessage(DEFAULT_CONSTRUCT_MESSAGE);
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap : " << std::flush;
	writeMessage(DEFAULT_CONSTRUCT_MESSAGE);
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "ScavTrap : " << std::flush;
	writeMessage(COPY_CONSTRUCT_MESSAGE);
}

// ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs) : ClapTrap::operator=(rhs)
// {
// 	std::cout << "ScavTrap : " << std::flush;
// 	writeMessage(COPY_OPERATOR_MESSAGE);

// }

ScavTrap::~ScavTrap()
{
}
