/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/28 19:48:45 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <sstream>
#include "libft.hpp"
#include "Contact.hpp"

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
	SEARCH_UNREGISTERED_INDEX,
};

enum SITUATION {
	MAIN,
	ADD,
	SEARCH,
};

class PhoneBook {
	int		m_contact_count;
	int		m_next_add_index;
	Contact	m_contact_list[MAX_CONTACTS];

public:
	void	initialize();
	int		get_contact_count();
	int		get_next_add_index();
	Contact	*get_contact(int index);
	void	print_contact_list();
	void	increment_contact_count();
	void	increment_next_add_index();
	void	add_command();
	void	search_command();
	void	exit_command();
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
int		try_add(PhoneBook *phonebook, std::string first, std::string last, std::string nick, std::string phone_number, std::string secret);

// PhoneBook::search_command();
bool	is_index(std::string str);
int		my_stoi(std::string str);

#endif
