/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_stoi.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/28 15:29:49 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

int	my_stoi(std::string str)
{
	int					i;
	std::stringstream	ss_str(str);

	ss_str >> i;
	return (i);
}
