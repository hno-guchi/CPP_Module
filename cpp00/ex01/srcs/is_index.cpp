/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_index.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/28 15:30:49 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

bool	is_index(std::string str)
{
	if (1 < ft_strlen(str)) {
		return (false);
	}
	if (!ft_isdigit(str[0])) {
		return (false);
	}
	if (!('0' <= str[0] && str[0] <= '7')) {
		return (false);
	}
	return (true);
}
