/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline_valid.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/28 18:26:18 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

static bool	is_all_alphabetic(const std::string data)
{
	for (int i = 0; data[i] != '\0'; i++) {
		if (!ft_isalpha(data[i])) {
			return (false);
		}
	}
	return (true);
}

bool	is_name(const std::string name)
{
	if (20 < ft_strlen(name)) {
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
	if (20 < ft_strlen(name)) {
		error_message(ADD_DATA_NAME_TOO_LONG);
		return (false);
	}
	for (int i = 0; name[i] != '\0'; i++) {
		if (!ft_isalpha(name[i]) && name[i] != '-' && name[i] != '_') {
			error_message(ADD_DATA_NICKNAME_ERR_VALID);
			return (false);
		}
	}
	return (true);
}

bool	is_phone_number(const std::string number)
{
	if (number[0] != '0') {
		error_message(ADD_DATA_PHONE_NUMBER_PREFIX_NOT_ZERO);
		return (false);
	}
	if (ft_strlen(number) != 10 && ft_strlen(number) != 11) {
		error_message(ADD_DATA_PHONE_NUMBER_WRONG_LENGTH);
		return (false);
	}
	for (int i = 0; number[i] != '\0'; i++) {
		if (!ft_isdigit(number[i])) {
			error_message(ADD_DATA_PHONE_NUMBER_ERR_VALID);
			return (false);
		}
	}
	return (true);
}

bool	is_darkest_secret(const std::string str)
{
	if (str == "") {
		error_message(ADD_DATA_TOO_FEW);
		return (false);
	}
	if (100 < ft_strlen(str)) {
		error_message(ADD_DATA_SECRET_TOO_LONG);
		return (false);
	}
	for (int i = 0; str[i] != '\0'; i++) {
		if (!ft_isalpha(str[i]) && str[i] != ' ' && str[i] != '\'' && str[i] != ',' && str[i] != '.') {
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
		while (line == "") {
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