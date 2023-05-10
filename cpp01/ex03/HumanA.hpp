/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:04:46 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/10 09:24:07 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iomanip>
#include <stdexcept>

class	HumanA {
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	attack();

	private:
		std::string	name;
		Weapon		&weapon;
};

#endif
