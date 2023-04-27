/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/27 15:28:40 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::print_data()
{
	std::cout
		<< m_index << " | "
		<< m_first_name << " | "
		<< m_last_name << " | "
		<< m_nickname
		<< std::endl;
}

void	Contact::add_data(int idx, std::string first, std::string last,
			std::string nick, std::string phone_num, std::string secret)
{
	m_index = idx;
	m_first_name = first;
	m_last_name = last;
	m_nickname = nick;
	m_phone_number = phone_num;
	m_darkest_secret = secret;
	std::cout << "[ADD] : Success!!" << std::endl;
}

std::string	Contact::get_phone_number()
{
	return (m_phone_number);
}

/*
int	main()
{
	Contact	contact;

	contact.add_data(0, "Hidenobu", "Noguchi", "hnoguchi", "012-3456-7890", "SECRET");
	contact.print_data();
}
*/
