/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/04 11:44:55 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <sstream>
#include <locale>

# define COMMAND_COUNT 3
# define CONTACT_DATA_TYPE_COUNT 5
# define MAX_CONTACTS 8
# define SIZE_OF_ARRAY(array) sizeof(array)/sizeof(array[0]);

enum ERROR_TYPE {
	NOT_COMMAND,
	ADD_DATA_TOO_FEW,
	ADD_DATA_STREAM_ERROR,
	ADD_DATA_NAME_TOO_LONG,
	ADD_DATA_NAME_NOT_ONLY_ALPHA,
	ADD_DATA_NICKNAME_ERR_VALID,
	ADD_DATA_PHONE_NUMBER_PREFIX_NOT_ZERO,
	ADD_DATA_PHONE_NUMBER_WRONG_LENGTH,
	ADD_DATA_PHONE_NUMBER_ERR_VALID,
	ADD_DATA_SECRET_TOO_LONG,
	ADD_DATA_SECRET_NOT_USE_CHAR,
	ADD_DATA_REGISTERED_PHONE_NUMBER,
	SEARCH_WARONG_VALUE,
	SEARCH_UNREGISTERED_INDEX
};

enum SITUATION {
	MAIN,
	ADD,
	SEARCH
};

class PhoneBook {
public:
	PhoneBook();
	int		get_contact_count();
	int		get_next_add_index();
	Contact	get_data_contact(int index);
	void	set_data_contact(int idx, std::string first, std::string last, std::string nick, std::string phone_num, std::string secret);
	void	increment_contact_count();
	void	increment_next_add_index();
	void	add_command();
	void	search_command();
	void	exit_command();
	void	print_debug_contact_list();
	~PhoneBook();

private:
	int		m_contact_count;
	int		m_next_add_index;
	Contact	m_contact_list[MAX_CONTACTS];
};

// commmon
int		getline_prompt(std::string prompt, std::string *line);
void	begin_message(SITUATION type);
void	error_message(ERROR_TYPE type);
bool	is_registered_phone_number(PhoneBook *phonebook, std::string *number);

// PhoneBook::add_command();
int		getline_valid(std::string title, std::string *data, bool (*valid_func)(std::string));
bool	is_name(const std::string name);
bool	is_nickname(const std::string name);
bool	is_phone_number(const std::string number);
bool	is_darkest_secret(const std::string str);
bool	is_registered_phone_number(PhoneBook *phonebook, std::string number);

// PhoneBook::search_command();
bool	is_index(std::string str);
int		my_stoi(std::string str);

#endif
