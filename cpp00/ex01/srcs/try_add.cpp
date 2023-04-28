/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_add.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/28 20:11:32 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

static bool	is_registered_phone_number(PhoneBook *phonebook, std::string number)
{
	int		count;
	Contact	*target;

	count = phonebook->get_contact_count();
	if (count == 0) {
		return (false);
	}
	for (int i = 0; i < count; i++) {
		target = phonebook->get_contact(i);
		if (number == target->get_phone_number()) {
			return (true);
		}
	}
	return (false);
}

int	try_add(PhoneBook *phonebook, std::string first, std::string last, std::string nick, std::string phone_number, std::string secret)
{
	int		index;
	Contact	*target;

	index = phonebook->get_next_add_index();
	if (is_registered_phone_number(phonebook, phone_number)) {
		return (-1);
	}
	target = phonebook->get_contact(index);
	target->add_data(index, first, last, nick, phone_number, secret);
	phonebook->increment_contact_count();
	phonebook->increment_next_add_index();
	std::cout << "\n[ADD] : Success!!\n" << std::endl;
	return (0);
}
