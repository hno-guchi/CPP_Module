/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_index.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/04 10:31:48 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

bool	is_index(std::string str)
{
	std::locale	l = std::locale::classic();

	if (1 < str.length()) {
		return (false);
	}
	if (!std::isdigit(str[0], l)) {
		return (false);
	}
	if (!('0' <= str[0] && str[0] <= '7')) {
		return (false);
	}
	return (true);
}
