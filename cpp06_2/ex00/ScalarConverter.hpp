/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/17 17:03:48 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include "debugMessage.hpp"
#include "color.hpp"
#include <iostream>
#include <iomanip>
#include <locale>
#include <string>
#include <limits>

class ScalarConverter {
private:
	// SUBJECT ATTRIBUTE
	// MY ATTRIBUTE
	// CONSTRUCTER
	ScalarConverter();
	~ScalarConverter();

public:
	// OPERATOR
	// GETTER
	// SETTER
	// SUBJECT FUNC
	static void	convert(std::string& str);
};

#endif
