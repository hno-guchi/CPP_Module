/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline_valid.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/04 11:18:53 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

static bool	is_all_alphabetic(const std::string data)
{
	std::locale	l = std::locale::classic();

	for (int i = 0; data[i] != '\0'; i++) {
		if (!std::isalpha(data[i], l)) {
			return (false);
		}
	}
	return (true);
}

bool	is_name(const std::string name)
{
	if (20 < name.length()) {
		error_message(ADD_DATA_NAME_TOO_LONG);
		return (false);
	} else if (!is_all_alphabetic(name)) {
		error_message(ADD_DATA_NAME_NOT_ONLY_ALPHA);
		return (false);
	}
	return (true);
}

bool	is_nickname(const std::string name)
{
	std::locale	l = std::locale::classic();

	if (20 < name.length()) {
		error_message(ADD_DATA_NAME_TOO_LONG);
		return (false);
	}
	for (int i = 0; name[i] != '\0'; i++) {
		if (!std::isalpha(name[i], l) && name[i] != '-' && name[i] != '_') {
			error_message(ADD_DATA_NICKNAME_ERR_VALID);
			return (false);
		}
	}
	return (true);
}

bool	is_phone_number(const std::string number)
{
	std::locale	l = std::locale::classic();

	if (number[0] != '0') {
		error_message(ADD_DATA_PHONE_NUMBER_PREFIX_NOT_ZERO);
		return (false);
	}
	if (number.length() != 10 && number.length() != 11) {
		error_message(ADD_DATA_PHONE_NUMBER_WRONG_LENGTH);
		return (false);
	}
	for (int i = 0; number[i] != '\0'; i++) {
		if (!std::isdigit(number[i], l)) {
			error_message(ADD_DATA_PHONE_NUMBER_ERR_VALID);
			return (false);
		}
	}
	return (true);
}

bool	is_darkest_secret(const std::string str)
{
	std::locale	l = std::locale::classic();

	if (str.empty() == true) {
		error_message(ADD_DATA_TOO_FEW);
		return (false);
	}
	if (100 < str.length()) {
		error_message(ADD_DATA_SECRET_TOO_LONG);
		return (false);
	}
	for (int i = 0; str[i] != '\0'; i++) {
		if (!std::isalpha(str[i], l) && str[i] != ' ' && str[i] != '\'' && str[i] != ',' && str[i] != '.') {
			error_message(ADD_DATA_SECRET_NOT_USE_CHAR);
			return (false);
		}
	}
	return (true);
}

int	getline_valid(std::string title, std::string *data, bool (*valid_func)(std::string))
{
	std::string	line;

	while (1) {
		while (line.empty() == true) {
			if (getline_prompt(title, &line) < 0) {
				return (-1);
			}
		}
		if (!valid_func(line)) {
			line = "";
			continue ;
		}
		break ;
	}
	*data = line;
	return (0);
}
