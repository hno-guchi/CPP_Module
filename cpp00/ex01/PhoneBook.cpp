/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/26 12:36:25 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

void	PhoneBook::initialize()
{
	contact_count = 0;
}

static void	input_data(std::string *data)
{
	std::cout << "\n[Add contact]\n"
		<< "Please enter this format.\n"
		<< "ex)          : [First name] [Last name] [Nickname] [Phone number] [Darkest secret]\n"
		<< "[Input data] : ";
		std::getline(std::cin, *data);
}

static void	tokenize(Contact *temp, std::string *str)
{
	std::istringstream	iss_str(*str);
	std::string			data[CONTACT_DATA_TYPE_COUNT];
	int					i;

	i = 0;
	while (iss_str.eof() != true) {
		if (iss_str.good()) {
			if (i < CONTACT_DATA_TYPE_COUNT) {
				iss_str >> data[i];
				i += 1;
			} else {
				temp = NULL;
				error_message(ADD_DATA_TOO_MANY);
				return ;
			}
		}
	}
	// TODO: temp
}

/*
bool	is_validation(Contact *temp)
{
	if (temp == NULL) {
		return (false);
	}
}
*/

void	PhoneBook::add_command()
{
	Contact		temp;
	std::string	add_data;

	for (;;) {
		input_data(&add_data);
		if (add_data.empty() == true) {
			continue ;
		}
		tokenize(&temp, &add_data);
		// if (!is_validation(&temp)) {
		// 	break ;
		// }
		// check(&temp);
		// do_add(&temp);
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
