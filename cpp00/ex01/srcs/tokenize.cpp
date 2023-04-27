/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/27 10:47:25 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

int	tokenize(std::string *data, std::string *str)
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
