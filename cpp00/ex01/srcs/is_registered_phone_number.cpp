/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_registered_phone_number.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/28 10:57:03 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

bool	is_registered_phone_number(PhoneBook *phonebook, std::string *number)
{
	int		count;
	Contact	*target;

	count = phonebook->get_contact_count();
	if (count == 0) {
		return (false);
	}
	for (int i = 0; i < count; i++) {
		target = phonebook->get_contact_from_index(i);
		if (*number == target->get_phone_number()) {
			return (true);
		}
	}
	return (false);
}
