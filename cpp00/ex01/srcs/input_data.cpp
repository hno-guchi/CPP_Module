/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_data.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/27 11:16:12 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

void	input_data(std::string *data)
{
	std::cout << "\n[Add] : "
		<< "Please enter this format.\n"
		<< "ex)          : [First name] [Last name] [Nickname] [Phone number] [Darkest secret]\n"
		<< "[Input data] : ";
		std::getline(std::cin, *data);
}
