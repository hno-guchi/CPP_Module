/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:03:14 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/08 10:07:37 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

class RPN {
private:
	// SUBJECT ATTRIBUTE

	// MY ATTRIBUTE

public:
	// CONSTRUCTOR
	RPN();
	RPN(const std::string& type);
	RPN(const RPN& src);
	// DESTRUCTOR
	~RPN();

	// OPERATOR
	RPN&	operator=(const RPN& rhs);

	// GETTER

	// SETTER

	// SUBJECT FUNC
};

#endif
