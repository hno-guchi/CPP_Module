/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/02 18:51:02 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {
public:
	// void	add_data(int idx, std::string first, std::string last, std::string nick, std::string phone_num, std::string secret);
	std::string	get_phone_number();
	void		set_index(int idx);
	void		set_first_name(std::string name);
	void		set_last_name(std::string name);
	void		set_nickname(std::string name);
	void		set_phone_number(std::string number);
	void		set_darkest_secret(std::string str);
	void		print_data();

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
