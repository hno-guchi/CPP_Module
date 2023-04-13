/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:27:14 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/13 12:49:31 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <cstring>
// #include <iostream>
// 
// namespace {
// 	void	func(const char *str, std::size_t size)
// 	{
// 		if (0 < size)
// 		{
// 			std::cout << str << " [" << size << "]" << std::endl;
// 		}
// 		else
// 		{
// 			std::cout << "--- empty ---" << std::endl;
// 		}
// 	}
// }
// 
// int	main()
// {
// 	char	s1[10] = "abcde";
// 	char	s2[10] = "";
// 
// 	func(s1, std::strlen(s1));
// 	func(s2, std::strlen(s2));
// 
// 	std::strcpy(s2, "abcde");
// 	func(s2, std::strlen(s2));
// 
// 	if (std::strcmp(s1, s2) == 0)
// 	{
// 		std::cout << "[OK]" << std::endl;
// 	}
// 	else
// 	{
// 		std::cout << "[NOT]" << std::endl;
// 	}
// }

#include <iostream>
#include <string>

namespace {
	void	func(const std::string *str)
	{
		if (str->empty() == true)
		{
			std::cout << "--- empty ---" << std::endl;
		}
		else
		{
			std::cout << *str << " [" << str->size() << "]" << std::endl;
		}
	}
}

int	main()
{
	std::string	s1("abcde");
	std::string	s2;

	func(&s1);
	func(&s2);

	s2 = "abcde";
	func(&s2);

	if (s1 == s2)
	{
		std::cout << "[OK]" << std::endl;
	}
	else
	{
		std::cout << "[NOT]" << std::endl;
	}
}
