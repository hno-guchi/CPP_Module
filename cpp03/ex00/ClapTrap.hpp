/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:59:45 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/23 16:38:53 by hnoguchi         ###   ########.fr       */
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

		std::string		getName() const;
		unsigned int	getHitPoint() const;
		unsigned int	getMaxHitPoint() const;
		unsigned int	getEnergyPoint() const;
		unsigned int	getAttackPoint() const;
		void			setName(const std::string& name);
		void			setHitPoint(const int& amount);
		void			setEnergyPoint(const int& amount);
		void			setAttackPoint(const int& amount);
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		virtual ~ClapTrap();

	private:
		std::string		name_;
		unsigned int	hitPoint_;
		unsigned int	maxHitPoint_;
		unsigned int	energyPoint_;
		unsigned int	attackPoint_;
};

enum eColor {
	green,
	yellow,
	red,
	NOT
};

void	writeMessage(std::string message);

#endif
