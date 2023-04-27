/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/27 20:17:08 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

void	PhoneBook::initialize()
{
	m_contact_count = 0;
}

int	PhoneBook::get_contact_count()
{
	return (m_contact_count);
}

Contact	*PhoneBook::get_contact_list(int index)
{
	if (index < 0 || MAX_CONTACTS <= index) {
		return (NULL);
	}
	return (&(m_contact_list[index]));
}

void	PhoneBook::increment_contact_count()
{
	if (m_contact_count == MAX_CONTACTS) {
		m_contact_count = 0;
	} else {
		m_contact_count += 1;
	}
}

bool	is_registered_phone_number(PhoneBook *phonebook, std::string *number)
{
	int		count;
	Contact	*target;

	count = phonebook->get_contact_count();
	if (count == 0) {
		return (false);
	}
	for (int i = 0; i < count; i++) {
		target = phonebook->get_contact_list(i);
		if (*number == target->get_phone_number()) {
			return (true);
		}
	}
	return (false);
}

void	PhoneBook::add_command()
{
	std::string	line;
	std::string	data[CONTACT_DATA_TYPE_COUNT];

	begin_message(ADD);
	while (line == "") {
		if (!getline_prompt("[ADD data] : ", &line)) {
			return ;
		}
	}
	if (tokenize(data, &line) < 0) {
		return ;
	}
	if (!is_validation(data)) {
		return ;
	}
	if (is_registered_phone_number(this, &(data[3]))) {
		error_message(ADD_DATA_REGISTERED_PHONE_NUMBER);
		return ;
	}
	do_add(this, data);
}

void	PhoneBook::search_command()
{
	std::string	phone_number;

	begin_message(SEARCH);
	while (phone_number == "") {
		if (!getline_prompt("[Phone number] : ", &phone_number)) {
			return ;
		}
	}
	if (is_phone_number(phone_number)) {
		return ;
	}
	if (!is_registered_phone_number(this, &phone_number)) {
		error_message(NOT_REGISTERED_PHONE_NUMBER);
			return ;
	}
	//TODO
	std::cout << "SEARCH command\n" << std::endl;
}

void	PhoneBook::exit_command()
{
	std::cout << "EXIT command\n" << std::endl;
}
