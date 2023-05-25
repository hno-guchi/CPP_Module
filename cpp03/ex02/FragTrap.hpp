/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:46:16 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/25 17:03:47 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "debugMessage.hpp"

# define FT_DEFAULT_HIT_POINT 100
# define FT_DEFAULT_ENERGY_POINT 100
# define FT_DEFAULT_ATTACK_POINT 30

class FragTrap : public ClapTrap {
	public:
		// CONSTRUCTER
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& src);

		// OPERATOR
		FragTrap&	operator=(const FragTrap& rhs);

		// SUBJECT FUNC
		void	highFivesGuys();

		// DESTRUCTER
		virtual ~FragTrap();
};

#endif
