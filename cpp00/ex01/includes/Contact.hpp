/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/04 11:45:16 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {
public:
	Contact();
	std::string	get_phone_number();
	void		set_index(int idx);
	void		set_first_name(std::string name);
	void		set_last_name(std::string name);
	void		set_nickname(std::string name);
	void		set_phone_number(std::string number);
	void		set_darkest_secret(std::string str);
	void		print_data();
	void		print_debug_data();
	~Contact();

private:
	int			m_index;
	std::string	m_first_name;
	std::string	m_last_name;
	std::string	m_nickname;
	std::string	m_phone_number;
	std::string	m_darkest_secret;
};

void	print_field_title();
void	print_field(std::string str);

#endif
