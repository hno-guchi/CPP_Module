/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_validation.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/28 09:31:26 by hnoguchi         ###   ########.fr       */
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

static bool	is_name(const std::string name)
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

static bool	is_nickname(const std::string name)
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

static bool	is_darkest_secret(const std::string str)
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

bool	is_validation(const std::string *data)
{
	if (!is_name(data[0])) {
		return (false);
	}
	if (!is_name(data[1])) {
		return (false);
	}
	if (!is_nickname(data[2])) {
		return (false);
	}
	if (!is_phone_number(data[3])) {
		return (false);
	}
	if (!is_darkest_secret(data[4])) {
		return (false);
	}
	return (true);
}
