/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/28 13:01:58 by hnoguchi         ###   ########.fr       */
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

Contact	*PhoneBook::get_contact_from_index(int index)
{
	if (index < 0 || MAX_CONTACTS <= index) {
		return (NULL);
	}
	return (&(m_contact_list[index]));
}

Contact	*PhoneBook::get_contact_from_phone_number(std::string phone_number)
{
	int		count;
	Contact	*target;

	count = this->get_contact_count();
	if (count == 0) {
		return (NULL);
	}
	for (int i = 0; i < count; i++) {
		target = this->get_contact_from_index(i);
		if (phone_number == target->get_phone_number()) {
			return (target);
		}
	}
	return (NULL);
}

void	PhoneBook::increment_contact_count()
{
	if (m_contact_count == MAX_CONTACTS) {
		m_contact_count = 0;
	} else {
		m_contact_count += 1;
	}
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
	Contact		*target;
	std::string	phone_number;

	begin_message(SEARCH);
	while (phone_number == "") {
		if (!getline_prompt("[Phone number] : ", &phone_number)) {
			return ;
		}
	}
	if (!is_phone_number(phone_number)) {
		return ;
	}
	target = this->get_contact_from_phone_number(phone_number);
	if (target == NULL) {
		error_message(NOT_REGISTERED_PHONE_NUMBER);
		return ;
	}
	target->print_data();
}

void	PhoneBook::exit_command()
{
	std::cin.setstate(std::ios::eofbit);
	std::cout << "exit" << std::endl;
}
