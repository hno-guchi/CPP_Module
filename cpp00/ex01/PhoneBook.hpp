/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/04/21 15:49:08 by hnoguchi         ###   ########.fr       */
=======
/*   Updated: 2023/04/25 11:17:19 by hnoguchi         ###   ########.fr       */
>>>>>>> 7e77521 ([ex01] Create file. Contact.hpp)
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

# define MAX_CONTACTS 8
# define SIZE_OF_ARRAY(array) sizeof(array)/sizeof(array[0]);

class PhoneBook {
	Contact	contact_list[MAX_CONTACTS];

<<<<<<< HEAD



=======
public:
	void	initialize();
	void	add_command();
	void	search_command();
	void	exit_command();
>>>>>>> 7e77521 ([ex01] Create file. Contact.hpp)
}

#endif
