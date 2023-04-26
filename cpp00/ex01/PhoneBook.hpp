/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/26 12:37:24 by hnoguchi         ###   ########.fr       */
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
	ADD_DATA_TOO_MANY,
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
