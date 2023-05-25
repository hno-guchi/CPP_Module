/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:59:45 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/25 16:15:51 by hnoguchi         ###   ########.fr       */
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
# define CT_DEFAULT_ATTACK_POINT 0

class ClapTrap {
	public:
		// CONSTRUCTER
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& src);

		// OPERATOR
		ClapTrap&	operator=(const ClapTrap& rhs);

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
		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		// DESTRUCTER
		virtual ~ClapTrap();

	private:
		// SUBJECT ATTRIBUTE
		std::string		name_;
		unsigned int	hitPoint_;
		unsigned int	energyPoint_;
		unsigned int	attackPoint_;

		// MY ATTRIBUTE
		unsigned int	upperLimitHitPoint_;
};

typedef enum eColor {
	green,
	yellow,
	red,
	not_coloer
}	tColor;

#endif
