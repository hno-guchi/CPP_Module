/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 08:25:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/08/01 11:00:00 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "debugMessage.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		// CONSTRUCTER
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& src);

		// OPERATOR
		DiamondTrap&	operator=(const DiamondTrap& rhs);

		// GETTER
		std::string		getName() const;

		// SETTER
		void			setName(const std::string& name);
		// SUBJECT FUNC
		// void	attack(const std::string& target); // ScavTrap
		// This member function will display both its name and its ClapTrap name.
		// void	whoAmI();
		// DESTRUCTER
		virtual	~DiamondTrap();
	
	private:
		// SUBJECT ATTRIBUTE
		std::string		name_;
		// unsigned int	hitPoint_;		// FragTrap
		// unsigned int	energyPoint_;	// ScavTrap
		// unsigned int	attackPoint_;	// FragTrap

		// MY ATTRIBUTE
};

#endif
