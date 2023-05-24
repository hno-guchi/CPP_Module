/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:46:16 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/24 11:54:10 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include "debugMessage.hpp"

# define ST_DEFAULT_HIT_POINT 100
# define ST_DEFAULT_ENERGY_POINT 50
# define ST_DEFAULT_ATTACK_POINT 20

class ScavTrap : protected ClapTrap {
	public:
		// CONSTRUCTER
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& src);

		// OPERATOR
		ScavTrap&	operator=(const ScavTrap& rhs);

		// GETTER
		std::string		getName() const;
		unsigned int	getHitPoint() const;
		unsigned int	getEnergyPoint() const;
		unsigned int	getAttackPoint() const;
		unsigned int	getUpperLimitHitPoint() const;

		// SETTER
		void			setName(const std::string& name);
		void			setHitPoint(const unsigned int& amount);
		void			setEnergyPoint(const unsigned int& amount);
		void			setAttackPoint(const unsigned int& amount);

		// SUBJECT FUNC
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	guardGate();

		// DESTRUCTER
		virtual ~ScavTrap();
};

#endif
