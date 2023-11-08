/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:03:14 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/08 15:58:21 by hnoguchi         ###   ########.fr       */
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
	std::deque<int>	buff;

public:
	// CONSTRUCTOR
	RPN();
	// DESUTRUCTOR
	~RPN();

	void	execute(std::string str) const;

	// EXCEPTION
	class EmptyArg : public std::invalid_argument {
	public:
		EmptyArg(const std::string& msg = "Empty argument.");
	};
};

#endif

// tokenize
// number is less than 10.
// operations is only +, -, /, *.
