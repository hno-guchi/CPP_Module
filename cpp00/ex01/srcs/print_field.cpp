/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_field.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/28 12:56:43 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	print_field(std::string str)
{
	std::string	output_str;

	if (10 <= ft_strlen(str)) {
		for (int i = 0; i < 9; i++) {
			output_str += str[i];
		}
		output_str += '.';
	} else {
		output_str = str;
	}
	std::cout << std::right << std::setw(10)
		<< output_str << " | "
		<< std::flush;
}
