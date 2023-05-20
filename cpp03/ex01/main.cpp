/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:26:45 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/20 18:53:46 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static void	colorMessage(eColor color, std::string message)
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

static void	writeData(const std::string& name, const int& hit, const int& energy, const int& attack)
{
	std::cout << "Name[ " << MAGENTA << name << END << " ] | ";
	std::cout << "Hit[ " << MAGENTA << hit << END << " ] | ";
	std::cout << "Energy[ " << MAGENTA << energy << END << " ] | ";
	std::cout << "Attack[ " << MAGENTA << attack << END << " ] | " << std::endl;
}

int	main()
{
	colorMessage(green,  "===== CONSTRUCT =======");
	ClapTrap	player_0;
	ClapTrap	player_1("hnoguchi");
	ClapTrap	player_2(player_1);

	player_0 = player_2;
	colorMessage(green,  "=======================");
#ifdef GET_SET
	colorMessage(green,  "\n===== GET, SET ========");
	std::cout << "player_0 | " << std::flush; writeData(player_0.getName(), player_0.getHitPoint(), player_0.getEnergyPoint(), player_0.getAttackPoint());
	std::cout << "player_1 | " << std::flush; writeData(player_1.getName(), player_1.getHitPoint(), player_1.getEnergyPoint(), player_1.getAttackPoint());
	std::cout << "player_2 | " << std::flush; writeData(player_2.getName(), player_2.getHitPoint(), player_2.getEnergyPoint(), player_2.getAttackPoint());

	player_0.setName("ChangedName");
	player_0.setHitPoint(5);
	player_0.setEnergyPoint(11);
	player_0.setAttackPoint(3);

	std::cout << "player_0 | " << std::flush; writeData(player_0.getName(), player_0.getHitPoint(), player_0.getEnergyPoint(), player_0.getAttackPoint());
	std::cout << "player_1 | " << std::flush; writeData(player_1.getName(), player_1.getHitPoint(), player_1.getEnergyPoint(), player_1.getAttackPoint());
	std::cout << "player_2 | " << std::flush; writeData(player_2.getName(), player_2.getHitPoint(), player_2.getEnergyPoint(), player_2.getAttackPoint());

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
	std::cout << "player_0 | " << std::flush; writeData(player_0.getName(), player_0.getHitPoint(), player_0.getEnergyPoint(), player_0.getAttackPoint());
	std::cout << "player_1 | " << std::flush; writeData(player_1.getName(), player_1.getHitPoint(), player_1.getEnergyPoint(), player_1.getAttackPoint());
	std::cout << "player_2 | " << std::flush; writeData(player_2.getName(), player_2.getHitPoint(), player_2.getEnergyPoint(), player_2.getAttackPoint());
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	player_0.attack("p1");
	player_1.takeDamage(static_cast<unsigned int>(player_0.getAttackPoint()));
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "player_0 | " << std::flush; writeData(player_0.getName(), player_0.getHitPoint(), player_0.getEnergyPoint(), player_0.getAttackPoint());
	std::cout << "player_1 | " << std::flush; writeData(player_1.getName(), player_1.getHitPoint(), player_1.getEnergyPoint(), player_1.getAttackPoint());
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	player_1.attack("p2");
	player_2.takeDamage(static_cast<unsigned int>(player_1.getAttackPoint()));
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "player_1 | " << std::flush; writeData(player_1.getName(), player_1.getHitPoint(), player_1.getEnergyPoint(), player_1.getAttackPoint());
	std::cout << "player_2 | " << std::flush; writeData(player_2.getName(), player_2.getHitPoint(), player_2.getEnergyPoint(), player_2.getAttackPoint());
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	player_2.attack("p0");
	player_0.takeDamage(static_cast<unsigned int>(player_2.getAttackPoint()));
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "player_2 | " << std::flush; writeData(player_2.getName(), player_2.getHitPoint(), player_2.getEnergyPoint(), player_2.getAttackPoint());
	std::cout << "player_0 | " << std::flush; writeData(player_0.getName(), player_0.getHitPoint(), player_0.getEnergyPoint(), player_0.getAttackPoint());
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	player_2.beRepaired(1000);
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "player_2 | " << std::flush; writeData(player_2.getName(), player_2.getHitPoint(), player_2.getEnergyPoint(), player_2.getAttackPoint());
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	player_1.attack("p2");
	player_2.takeDamage(static_cast<unsigned int>(player_1.getAttackPoint()));
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "player_2 | " << std::flush; writeData(player_2.getName(), player_2.getHitPoint(), player_2.getEnergyPoint(), player_2.getAttackPoint());
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	player_1.attack("p2");
	player_2.takeDamage(static_cast<unsigned int>(player_1.getAttackPoint()));
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "player_2 | " << std::flush; writeData(player_2.getName(), player_2.getHitPoint(), player_2.getEnergyPoint(), player_2.getAttackPoint());
	std::cout << "----------------------------------------------------------------\n" << std::endl;

	player_1.attack("p2");
	player_2.takeDamage(static_cast<unsigned int>(player_1.getAttackPoint()));
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "player_2 | " << std::flush; writeData(player_2.getName(), player_2.getHitPoint(), player_2.getEnergyPoint(), player_2.getAttackPoint());
	std::cout << "----------------------------------------------------------------\n" << std::endl;
	colorMessage(green,  "=======================");
#endif
}
