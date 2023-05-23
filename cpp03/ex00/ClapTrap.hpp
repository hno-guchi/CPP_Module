/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:59:45 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/24 08:00:27 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include "color.hpp"
#include "debugMessage.hpp"

# define MAX_NAME_SIZE 20
# define MAX_HIT_POINT 100
# define MAX_ENERGY_POINT 100
# define MAX_ATTACK_POINT 100

# define CT_DEFAULT_HIT_POINT 10
# define CT_DEFAULT_ENERGY_POINT 10
# define CT_MAX_ATTACK_POINT 10

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& src);

		ClapTrap&	operator=(const ClapTrap& rhs);

		std::string	getName();
		const int&	getHitPoint();
		const int&	getMaxHitPoint();
		int			getEnergyPoint();
		int			getAttackPoint();
		void		setName(const std::string& name);
		void		setHitPoint(const int& amount);
		void		setEnergyPoint(const int& amount);
		void		setAttackPoint(const int& amount);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		virtual ~ClapTrap();

	private:
		std::string	name_;
		int			hitPoint_;
		int			maxHitPoint_;
		int			energyPoint_;
		int			attackPoint_;
};

typedef enum eColor {
	green,
	yellow,
	red,
	not_coloer
}	tColor;

#endif
