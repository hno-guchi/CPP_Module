/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/02 18:40:15 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::get_phone_number()
{
	return (m_phone_number);
}

void		Contact::set_index(int idx)
{
	this->m_index = idx;
}

void		Contact::set_first_name(std::string name)
{
	this->m_first_name = name;
}

void		Contact::set_last_name(std::string name)
{
	this->m_last_name = name;
}

void		Contact::set_nickname(std::string name)
{
	this->m_nickname = name;
}

void		Contact::set_phone_number(std::string number)
{
	this->m_phone_number = number;
}

void		Contact::set_darkest_secret(std::string str)
{
	this->m_darkest_secret = str;
}

void	Contact::print_data()
{
	std::cout << std::right << std::setw(10)
		<< this->m_index << " | "
		<< std::flush;
	print_field(this->m_first_name);
	print_field(this->m_last_name);
	print_field(this->m_nickname);
	std::cout << std::endl;
}
