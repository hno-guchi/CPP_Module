/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_phone_number.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/27 18:47:53 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

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
