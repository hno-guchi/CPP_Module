/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/26 19:03:05 by hnoguchi         ###   ########.fr       */
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

bool	is_alpha(const char c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
		return (true);
	}
	return (false);
}

static bool	is_all_alphabetic(const std::string *data)
{
	for (std::string::const_iterator itr = data->begin(); itr != data->end(); itr++) {
		if (!is_alpha(*itr)) {
			return (false);
		}
	}
	return (true);
}

static bool	is_name(const std::string *name)
{
	if (20 < name->size()) {
		error_message(ADD_DATA_NAME_TOO_LONG);
		return (false);
	} else if (!is_all_alphabetic(name)) {
		error_message(ADD_DATA_NAME_NOT_ONLY_ALPHA);
		return (false);
	}
	return (true);
}

static bool	is_nickname(const std::string *name)
{
	if (20 < name->size()) {
		error_message(ADD_DATA_NAME_TOO_LONG);
		return (false);
	}
	for (std::string::const_iterator itr = name->begin(); itr != name->end(); itr++) {
		if (!is_alpha(*itr) && *itr != '-' && *itr != '_') {
			error_message(ADD_DATA_NICKNAME_ERR_VALID);
			return (false);
		}
	}
	return (true);
}

bool	is_digit(const char c)
{
	if ('0' <= c && c <= '9') {
		return (true);
	}
	return (false);
}

static bool	is_phone_number(const std::string *number)
{
	std::string::const_iterator	itr;

	itr = number->begin();
	if (*itr != '0') {
		error_message(ADD_DATA_PHONE_NUMBER_PREFIX_NOT_ZERO);
		return (false);
	}
	if (number->size() != 10 && number->size() != 11) {
		error_message(ADD_DATA_PHONE_NUMBER_TOO_LONG);
		return (false);
	}
	for (; itr != number->end(); itr++) {
		if (!is_digit(*itr)) {
			error_message(ADD_DATA_PHONE_NUMBER_ERR_VALID);
			return (false);
		}
	}
	return (true);
}

bool	is_validation(const std::string *data)
{
	if (!is_name(&(data[0]))) {
		return (false);
	}
	if (!is_name(&(data[1]))) {
		return (false);
	}
	if (!is_nickname(&(data[2]))) {
		return (false);
	}
	if (!is_phone_number(&(data[3]))) {
		return (false);
	}
	if (data[4].empty() == true) {
		error_message(ADD_DATA_TOO_FEW);
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
		// if (!is_submit_add_data(data) {
		// break ;
		// }
		// do_add(data);
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
