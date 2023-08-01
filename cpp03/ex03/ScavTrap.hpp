/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:46:16 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/08/01 09:20:53 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include "debugMessage.hpp"

# define ST_DEFAULT_HIT_POINT 100
# define ST_DEFAULT_ENERGY_POINT 50
# define ST_DEFAULT_ATTACK_POINT 20

class ScavTrap : public virtual ClapTrap {
	public:
		// CONSTRUCTER
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& src);

		// OPERATOR
		ScavTrap&	operator=(const ScavTrap& rhs);

		// SUBJECT FUNC
		virtual void	attack(const std::string& target);
		void			guardGate();

		// DESTRUCTER
		virtual ~ScavTrap();
};

#endif
