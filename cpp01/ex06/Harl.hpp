/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:35:01 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/16 18:32:44 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>

# define END             "\033[0m"

# define RED             "\033[31m"
# define GREEN           "\033[32m"
# define YELLOW          "\033[33m"
# define MAGENTA         "\033[35m"
# define LEVEL_MAX_COUNT 4

class	Harl {
	public:
		Harl();
		~Harl();

		void			harlFilter(unsigned int level);
		void			complain(std::string level);

	private:
		void			debug();
		void			info();
		void			warning();
		void			error();
		typedef void	(Harl::*funcPtr)();
		void			executeDebug();
		void			executeInfo();
		void			executeWarning();
		void			executeError();
};

#endif
