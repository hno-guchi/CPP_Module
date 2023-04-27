/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_validation.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/27 10:49:02 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

static bool	is_all_alphabetic(const std::string *data)
{
	for (std::string::const_iterator itr = data->begin(); itr != data->end(); itr++) {
		if (!ft_isalpha(*itr)) {
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
		if (!ft_isalpha(*itr) && *itr != '-' && *itr != '_') {
			error_message(ADD_DATA_NICKNAME_ERR_VALID);
			return (false);
		}
	}
	return (true);
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
		if (!ft_isdigit(*itr)) {
			error_message(ADD_DATA_PHONE_NUMBER_ERR_VALID);
			return (false);
		}
	}
	return (true);
}

static bool	is_darkest_secret(const std::string *str)
{
	if (str->empty() == true) {
		error_message(ADD_DATA_TOO_FEW);
		return (false);
	}
	for (std::string::const_iterator itr = str->begin(); itr != str->end(); itr++) {
		if (!ft_isalpha(*itr) && *itr != ' ' && *itr != '\'' && *itr != ',' && *itr != '.') {
			error_message(ADD_DATA_SECRET_NOT_USE_CHAR);
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
	if (!is_darkest_secret(&(data[4]))) {
		return (false);
	}
	return (true);
}
