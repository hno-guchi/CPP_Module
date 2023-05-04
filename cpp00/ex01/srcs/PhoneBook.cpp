/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/02 18:41:16 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

void	PhoneBook::initialize()
{
	m_contact_count = 0;
	m_next_add_index = 0;
	for (int i = 0; i < MAX_CONTACTS; i++) {
		this->m_contact_list[i].set_index(i);
		this->m_contact_list[i].set_first_name("");
		this->m_contact_list[i].set_last_name("");
		this->m_contact_list[i].set_nickname("");
		this->m_contact_list[i].set_phone_number("");
		this->m_contact_list[i].set_darkest_secret("");
	}
}

int	PhoneBook::get_contact_count()
{
	return (m_contact_count);
}

int	PhoneBook::get_next_add_index()
{
	return (m_next_add_index);
}

Contact	PhoneBook::get_data_contact(int index)
{
	return (m_contact_list[index]);
}

void	PhoneBook::set_data_contact(int idx, std::string first, std::string last,
			std::string nick, std::string phone_num, std::string secret)
{
	if (idx < 0 || MAX_CONTACTS <= idx) {
		return ;
	}
	this->m_contact_list[idx].set_index(idx);
	this->m_contact_list[idx].set_first_name(first);
	this->m_contact_list[idx].set_last_name(last);
	this->m_contact_list[idx].set_nickname(nick);
	this->m_contact_list[idx].set_phone_number(phone_num);
	this->m_contact_list[idx].set_darkest_secret(secret);
}

void	PhoneBook::increment_contact_count()
{
	if (m_contact_count < MAX_CONTACTS) {
		m_contact_count += 1;
	}
}

void	PhoneBook::increment_next_add_index()
{
	if ((m_next_add_index + 1) == MAX_CONTACTS) {
		m_next_add_index = 0;
	} else {
		m_next_add_index += 1;
	}
}

void	PhoneBook::add_command()
{
	int			index;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	index = this->get_next_add_index();
	begin_message(ADD);
	if (getline_valid("[First name]     : ", &first_name, is_name) < 0) {
		return ;
	}
	if (getline_valid("[Last name]      : ", &last_name, is_name) < 0) {
		return ;
	}
	if (getline_valid("[Nickname]       : ", &nickname, is_nickname) < 0) {
		return ;
	}
	if (getline_valid("[Phone number]   : ", &phone_number, is_phone_number) < 0) {
		return ;
	}
	if (getline_valid("[Darkest secret] : ", &darkest_secret, is_darkest_secret) < 0) {
		return ;
	}
	if (is_registered_phone_number(this, phone_number)) {
		error_message(ADD_DATA_REGISTERED_PHONE_NUMBER);
		return ;
	}
	this->set_data_contact(index, first_name, last_name, nickname, phone_number, darkest_secret);
	this->increment_contact_count();
	this->increment_next_add_index();
	std::cout << "\n[ADD] : Success!!\n" << std::endl;
}

void	PhoneBook::search_command()
{
	Contact		target;
	std::string	index;

	begin_message(SEARCH);
	while (index == "") {
		if (getline_prompt("[index]  : ", &index) < 0) {
			return ;
		}
	}
	if (!is_index(index)) {
		error_message(SEARCH_WARONG_VALUE);
		return ;
	}
	if (m_contact_count <= my_stoi(index)) {
		error_message(SEARCH_UNREGISTERED_INDEX);
		return ;
	}
	target = this->get_data_contact(my_stoi(index));
	print_field_title();
	target.print_data();
}

void	PhoneBook::exit_command()
{
	std::cin.setstate(std::ios::eofbit);
	std::cout << "exit" << std::endl;
}

void	PhoneBook::print_contact_list()
{
	print_field_title();
	for (int i = 0; i < MAX_CONTACTS; i++) {
		this->get_data_contact(i).print_data();
	}
}
