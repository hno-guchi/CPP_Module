/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:03:14 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/10 17:41:25 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <locale>
#include <deque>
#include <algorithm>
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
	class OverInt : public std::out_of_range {
	public:
		OverInt(const std::string& msg = "Over INT_MAX or under INT_MIN.");
	};
};

#endif
