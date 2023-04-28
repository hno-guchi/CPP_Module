/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/28 19:55:02 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "libft.hpp"
#include <iostream>
#include <iomanip>

class Contact {
	int			m_index;
	std::string	m_first_name;
	std::string	m_last_name;
	std::string	m_nickname;
	std::string	m_phone_number;
	std::string	m_darkest_secret;

public:
	void	print_data();
	void	add_data(int idx, std::string first, std::string last,
				std::string nick, std::string phone_num, std::string secret);
	std::string	get_phone_number();
};

void	print_field_title();
void	print_field(std::string str);

#endif
