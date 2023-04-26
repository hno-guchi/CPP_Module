/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/26 16:13:18 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

void	PhoneBook::initialize()
{
	contact_count = 0;
}

static void	input_data(std::string *data)
{
	std::cout << "\n[Add] : "
		<< "Please enter this format.\n"
		<< "ex)          : [First name] [Last name] [Nickname] [Phone number] [Darkest secret]\n"
		<< "[Input data] : ";
		std::getline(std::cin, *data);
}

static int	tokenize(std::string *data, std::string *str)
{
	int					i;
	std::string			word;
	std::istringstream	iss_str(*str);

	i = 0;
	while (iss_str.eof() != true) {
		if (iss_str.fail()) {
			error_message(ADD_DATA_STREAM_ERROR);
			return (-1);
		}
		if (i < (CONTACT_DATA_TYPE_COUNT - 1)) {
			iss_str >> data[i];
			i += 1;
		} else if (i == (CONTACT_DATA_TYPE_COUNT - 1)) {
			iss_str >> word;
			data[i] += word;
			if (iss_str.peek() != EOF) {
				data[i] += ' ';
			}
		}
	}
	if (i != (CONTACT_DATA_TYPE_COUNT - 1)) {
		error_message(ADD_DATA_TOO_FEW);
		return (-1);
	}
	return (0);
}

bool	is_validation(std::string *data)
{
	if (20 < data[0].size()) {
		return (false);
	}
	return (true);
}

void	PhoneBook::add_command()
{
	std::string	line;
	std::string	data[CONTACT_DATA_TYPE_COUNT];

	for (;;) {
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
