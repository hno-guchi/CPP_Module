/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/26 18:41:56 by hnoguchi         ###   ########.fr       */
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
};

class PhoneBook {
	int		contact_count;
	Contact	contact_list[MAX_CONTACTS];

public:
	void	initialize();
	void	add_command();
	void	search_command();
	void	exit_command();
};

void	error_message(ERROR_TYPE type);

#endif
