/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/02 12:09:00 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::print_data()
{
	std::cout << std::right << std::setw(10)
		<< m_index << " | "
		<< std::flush;
	print_field(m_first_name);
	print_field(m_last_name);
	print_field(m_nickname);
	std::cout << std::endl;
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
