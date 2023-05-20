/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:59:45 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/20 18:16:57 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include "color.hpp"

# define DEFAULT_CONSTRUCT_MESSAGE "Default constructor called"
# define COPY_CONSTRUCT_MESSAGE "Copy constructor called"
# define DESTRUCT_MESSAGE "Destructor called"
# define COPY_OPERATOR_MESSAGE "Copy assignment operator called"

# define MAX_NAME_SIZE 20
# define DEFAULT_HIT_POINT 10
# define DEFAULT_ENERGY_POINT 10
# define MAX_ATTACK_POINT 10

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& src);

		ClapTrap&	operator=(const ClapTrap& rhs);

		std::string	getName();
		int			getHitPoint();
		int			getEnergyPoint();
		int			getAttackPoint();
		void		setName(const std::string& name);
		void		setHitPoint(const int& amount);
		void		setEnergyPoint(const int& amount);
		void		setAttackPoint(const int& amount);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		~ClapTrap();

	private:
		std::string	name_;
		int			hitPoint_;
		int			energyPoint_;
		int			attackPoint_;
};

enum eColor {
	green,
	yellow,
	red,
	NOT
};

#endif
