/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/28 12:35:23 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.hpp"

size_t	ft_strlen(const std::string str)
{
	size_t	len;

	for (len = 0; str[len] != '\0'; len++)
		;
	return (len);
}
