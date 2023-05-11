/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:35:01 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/11 21:26:08 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

# define END             "\033[0m"

# define RED             "\033[31m"
# define GREEN           "\033[32m"
# define YELLOW          "\033[33m"
# define MAGENTA         "\033[35m"

typedef enum eLevel	tLevel;

class	Harl {
	public:
		Harl();
		~Harl();
		void		complain(std::string level);
		const void	(*getLevelFunction(tLevel level))();

	private:
		void	debug();
		void	info();
		void	warning();
		void	error();
};

enum eLevel {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	NOT
};

#endif
