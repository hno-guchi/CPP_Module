/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/12 17:44:46 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include "debugMessage.hpp"
#include "color.hpp"
#include <iostream>
#include <locale>
#include <string>

# define NON_DISPLAYABLE_MESSAGE "Non displayable"
# define IMPOSIBLE_MESSAGE "impossible"

class ScalarConverter {
private:
	// SUBJECT ATTRIBUTE

	// MY ATTRIBUTE

	// CONSTRUCTER
	ScalarConverter();
	~ScalarConverter();

public:
	// OPERATOR
	// ScalarConverter&	operator=(const ScalarConverter& rhs);
	// GETTER

	// SETTER

	// SUBJECT FUNC
	static void	convert(std::string& str);
};

#endif
