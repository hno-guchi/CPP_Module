/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/05 13:53:00 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// CONSTRUCTER
// DESTRUCTER
// OPERATOR
// ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& rhs)
// {
// 	if (this == &rhs) {
// 		return (*this);
// 	}
// 	debugMessage("ScalarConverter", COPY_OPERATOR);
// 	return (*this);
// }

// GETTER

// SETTER

// SUBJECT FUNC
void	ScalarConverter::convert(std::string& str)
{
	std::cout << "char:" << std::endl;
	std::cout << "int:" << std::endl;
	std::cout << "float:" << std::endl;
	std::cout << "double:" << std::endl;
	std::cout << str << std::endl;
}
