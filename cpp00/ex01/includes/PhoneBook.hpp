/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/27 12:09:42 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
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
	ADD_DATA_PHONE_NUMBER_TOO_LONG,
	ADD_DATA_PHONE_NUMBER_ERR_VALID,
	ADD_DATA_SECRET_NOT_USE_CHAR,
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
void	error_message(ERROR_TYPE type);
bool	ft_isdigit(const char c);

// add_command();
bool	ft_isalpha(const char c);
void	input_data(std::string *data);
int		tokenize(std::string *data, std::string *str);
bool	is_validation(const std::string *data);
void	do_add(PhoneBook *phonebook, std::string *data);

#endif
