/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:26:45 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/08/02 14:10:18 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

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

static void	writeData(const std::string& objectName, const DiamondTrap& rhs)
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
	DiamondTrap	player_0;
	std::cout << std::endl;
	DiamondTrap	player_1;
	std::cout << std::endl;
	// DiamondTrap	player_0(); // Compile Error
	DiamondTrap	player_2("hnoguchi");
	std::cout << std::endl;
	DiamondTrap	player_3(player_2);
	std::cout << std::endl;

	player_1 = player_3;
	colorMessage(green,  "=======================");

	std::cout << "----------------------------------------------------------------" << std::endl;
	writeData("player_0", player_0);
	writeData("player_1", player_1);
	writeData("player_2", player_2);
	writeData("player_3", player_3);
	std::cout << "player_0" << std::endl;
	player_0.whoAmI();
	std::cout << "player_1" << std::endl;
	player_1.whoAmI();
	std::cout << "player_2" << std::endl;
	player_2.whoAmI();
	std::cout << "player_3" << std::endl;
	player_3.whoAmI();
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	// colorMessage(green,  "\n===== FUNCTIONS =====");
	// player_0.setName("p0");
	// player_1.setName("p1");
	// player_2.setName("p2");
	// player_0.setAttackPoint(30);
	// player_1.setAttackPoint(50);
	// player_2.setAttackPoint(10);
	// std::cout << "----------------------------------------------------------------" << std::endl;
	// writeData("player_0", player_0);
	// writeData("player_1", player_1);
	// writeData("player_2", player_2);
	// std::cout << "----------------------------------------------------------------\n" << std::endl;

	// player_0.attack("p1");
	// player_1.takeDamage(player_0.getAttackPoint());
	// std::cout << "----------------------------------------------------------------" << std::endl;
	// writeData("player_0", player_0);
	// writeData("player_1", player_1);
	// std::cout << "----------------------------------------------------------------\n" << std::endl;

	// player_1.attack("p2");
	// player_2.takeDamage(player_1.getAttackPoint());
	// std::cout << "----------------------------------------------------------------" << std::endl;
	// writeData("player_1", player_1);
	// writeData("player_2", player_2);
	// std::cout << "----------------------------------------------------------------\n" << std::endl;

	// player_2.attack("p0");
	// player_0.takeDamage(player_2.getAttackPoint());
	// std::cout << "----------------------------------------------------------------" << std::endl;
	// writeData("player_2", player_2);
	// writeData("player_0", player_0);
	// std::cout << "----------------------------------------------------------------\n" << std::endl;

	// player_2.beRepaired(1000);
	// std::cout << "----------------------------------------------------------------" << std::endl;
	// writeData("player_2", player_2);
	// std::cout << "----------------------------------------------------------------\n" << std::endl;

	// player_1.attack("p2");
	// player_2.takeDamage(player_1.getAttackPoint());
	// std::cout << "----------------------------------------------------------------" << std::endl;
	// writeData("player_2", player_2);
	// std::cout << "----------------------------------------------------------------\n" << std::endl;

	// player_1.attack("p2");
	// player_2.takeDamage(player_1.getAttackPoint());
	// std::cout << "----------------------------------------------------------------" << std::endl;
	// writeData("player_2", player_2);
	// std::cout << "----------------------------------------------------------------\n" << std::endl;

	// player_1.attack("p2");
	// player_2.takeDamage(player_1.getAttackPoint());
	// std::cout << "----------------------------------------------------------------" << std::endl;
	// writeData("player_2", player_2);
	// std::cout << "----------------------------------------------------------------\n" << std::endl;

	// player_0.highFivesGuys();
	// player_1.highFivesGuys();
	// player_2.highFivesGuys();

	// colorMessage(green,  "=======================");
}
