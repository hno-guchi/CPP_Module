/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/27 19:14:54 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <sstream>

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
	ADD_DATA_SECRET_NOT_USE_CHAR,
	ADD_DATA_REGISTERED_PHONE_NUMBER,
	NOT_REGISTERED_PHONE_NUMBER,
};

enum SITUATION {
	MAIN,
	ADD,
	SEARCH,
};

class PhoneBook {
	int		m_contact_count;
	Contact	m_contact_list[MAX_CONTACTS];

public:
	void	initialize();
	int		get_contact_count();
	Contact	*get_contact_list(int index);
	void	increment_contact_count();
	void	add_command();
	void	search_command();
	void	exit_command();
};

// commmon
bool	getline_prompt(std::string prompt, std::string *line);
void	begin_message(SITUATION type);
void	error_message(ERROR_TYPE type);
size_t	ft_strlen(const std::string str);
bool	ft_isdigit(const char c);
bool	is_phone_number(const std::string number);

void	print_message_in_main();

// PhoneBook::add_command();
void	print_message_in_add();
bool	ft_isalpha(const char c);
int		tokenize(std::string *data, std::string *str);
bool	is_validation(const std::string *data);
void	do_add(PhoneBook *phonebook, std::string *data);

// PhoneBook::search_command();
void	print_message_in_search();
#endif
