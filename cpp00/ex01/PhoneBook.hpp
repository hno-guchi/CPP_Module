/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/25 12:36:49 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

# define MAX_CONTACTS 8
# define SIZE_OF_ARRAY(array) sizeof(array)/sizeof(array[0]);

class PhoneBook {
	int		contact_count;
	Contact	contact_list[MAX_CONTACTS];

public:
	void	add_command();
	void	search_command();
	void	exit_command();
}

#endif
