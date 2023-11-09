/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:03:14 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/09 15:56:41 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <locale>
#include <deque>
#include <stdexcept>

class RPN {
private:
	static const std::string	operations_;

public:
	// CONSTRUCTOR
	RPN();
	// DESUTRUCTOR
	~RPN();

	void	execute(std::string str) const;

	// EXCEPTION
	class InvalidArg : public std::invalid_argument {
	public:
		InvalidArg(const std::string& msg = "Invalid argument.");
	};
};

#endif
