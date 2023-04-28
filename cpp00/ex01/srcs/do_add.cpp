/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_add.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/28 10:58:53 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

void	do_add(PhoneBook *phonebook, std::string *data)
{
	int		index;
	Contact	*target;

	index = phonebook->get_contact_count();
	target = phonebook->get_contact_from_index(index);
	target->add_data(index, data[0], data[1], data[2], data[3], data[4]);
	phonebook->increment_contact_count();
}
