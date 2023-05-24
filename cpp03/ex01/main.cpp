/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:26:45 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/24 12:02:22 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

static void	colorMessage(tColor color, std::string message)
{
	switch(color) {
		case green:
			std::cout << GREEN << message << END << std::endl;
			break ;
		case yellow:
			std::cout << YELLOW << message << END << std::endl;
			break ;
		case red:
			std::cout << RED << message << END << std::endl;
			break ;
		default:
			std::cout << message << std::endl;
	}
}

static void	writeData(const std::string& objectName, const ScavTrap& rhs)
{
	std::cout << objectName << " | " << std::flush;
	std::cout << "Name[ " << MAGENTA << rhs.getName() << END << " ] | ";
	std::cout << "Hit[ " << MAGENTA << rhs.getHitPoint() << END << "/" << MAGENTA << rhs.getUpperLimitHitPoint() << END " ] | ";
	std::cout << "Energy[ " << MAGENTA << rhs.getEnergyPoint() << END << " ] | ";
	std::cout << "Attack[ " << MAGENTA << rhs.getAttackPoint() << END << " ] | " << std::endl;
}

int	main()
{
	colorMessage(green,  "===== CONSTRUCT =======");
	ScavTrap	player_0;
	ScavTrap	player_1("hnoguchi");
	ScavTrap	player_2(player_1);

	player_0 = player_2;
	colorMessage(green,  "=======================");
#ifdef BOUNDARY
	colorMessage(green,  "\n===== BOUNDARY ========");
	std::cout << "----------------------------------------------------------------" << std::endl;
	writeData("player_0", player_0);
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	player_0.setName("ChangedName");

	// Error (Under)
	player_0.setHitPoint(0);
	player_0.setEnergyPoint(0);
	player_0.setAttackPoint(0);

	std::cout << "----------------------------------------------------------------" << std::endl;
	writeData("player_0", player_0);
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	// Error (Over)
	player_0.setHitPoint(101);
	player_0.setEnergyPoint(101);
	player_0.setAttackPoint(101);

	std::cout << "----------------------------------------------------------------" << std::endl;
	writeData("player_0", player_0);
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	// Empty EnergyPoint - attack()
	player_0.setHitPoint(2);
	player_0.setEnergyPoint(1);
	player_0.setAttackPoint(1);

	std::cout << "----------------------------------------------------------------" << std::endl;
	writeData("player_0", player_0);
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	player_0.attack("changedName");
	player_0.takeDamage(player_0.getAttackPoint());

	std::cout << "----------------------------------------------------------------" << std::endl;
	writeData("player_0", player_0);
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	player_0.attack("changedName");

	std::cout << "----------------------------------------------------------------" << std::endl;
	writeData("player_0", player_0);
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	// Empty EnergyPoint - beRepaired()
	player_0.beRepaired(player_0.getAttackPoint());

	std::cout << "----------------------------------------------------------------" << std::endl;
	writeData("player_0", player_0);
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	// hitPoint is zero - takeDamage() - beRepaired(); - attack();
	player_0.takeDamage(player_0.getAttackPoint());
	player_0.setEnergyPoint(1);

	std::cout << "----------------------------------------------------------------" << std::endl;
	writeData("player_0", player_0);
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	player_0.attack("changedName");
	player_0.takeDamage(player_0.getAttackPoint());
	player_0.beRepaired(player_0.getAttackPoint());

	colorMessage(green,  "=======================");
#else
	colorMessage(green,  "\n===== FUNCTIONS =====");
	player_0.setName("p0");
	player_1.setName("p1");
	player_2.setName("p2");
	player_0.setAttackPoint(3);
	player_1.setAttackPoint(5);
	player_2.setAttackPoint(1);
	std::cout << "----------------------------------------------------------------" << std::endl;
	writeData("player_0", player_0);
	writeData("player_1", player_1);
	writeData("player_2", player_2);
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	player_0.attack("p1");
	player_1.takeDamage(player_0.getAttackPoint());
	std::cout << "----------------------------------------------------------------" << std::endl;
	writeData("player_0", player_0);
	writeData("player_1", player_1);
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	player_1.attack("p2");
	player_2.takeDamage(player_1.getAttackPoint());
	std::cout << "----------------------------------------------------------------" << std::endl;
	writeData("player_1", player_1);
	writeData("player_2", player_2);
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	player_2.attack("p0");
	player_0.takeDamage(player_2.getAttackPoint());
	std::cout << "----------------------------------------------------------------" << std::endl;
	writeData("player_2", player_2);
	writeData("player_0", player_0);
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	player_2.beRepaired(1000);
	std::cout << "----------------------------------------------------------------" << std::endl;
	writeData("player_2", player_2);
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	player_1.attack("p2");
	player_2.takeDamage(player_1.getAttackPoint());
	std::cout << "----------------------------------------------------------------" << std::endl;
	writeData("player_2", player_2);
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	player_1.attack("p2");
	player_2.takeDamage(player_1.getAttackPoint());
	std::cout << "----------------------------------------------------------------" << std::endl;
	writeData("player_2", player_2);
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	player_1.attack("p2");
	player_2.takeDamage(player_1.getAttackPoint());
	std::cout << "----------------------------------------------------------------" << std::endl;
	writeData("player_2", player_2);
	std::cout << "----------------------------------------------------------------\n" << std::endl;
	colorMessage(green,  "=======================");
#endif
}
