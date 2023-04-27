/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/27 12:08:26 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

void	PhoneBook::initialize()
{
	m_contact_count = 0;
}

int	PhoneBook::get_contact_count()
{
	return (m_contact_count);
}

Contact	*PhoneBook::get_contact_list(int index)
{
	if (index < 0 || MAX_CONTACTS <= index) {
		return (NULL);
	}
	return (&(m_contact_list[index]));
}

void	PhoneBook::increment_contact_count()
{
	if (m_contact_count == MAX_CONTACTS) {
		m_contact_count = 0;
	} else {
		m_contact_count += 1;
	}
}

void	PhoneBook::add_command()
{
	std::string	line;
	std::string	data[CONTACT_DATA_TYPE_COUNT];

	while (1) {
		input_data(&line);
		if (line.empty() == true) {
			continue ;
		}
		if (tokenize(data, &line) < 0) {
			break ;
		}
		if (!is_validation(data)) {
			break ;
		}
		do_add(this, data);
		break ;
	}
}

void	PhoneBook::search_command()
{
	std::cout << "SEARCH command\n" << std::endl;
}

void	PhoneBook::exit_command()
{
	std::cout << "EXIT command\n" << std::endl;
}
