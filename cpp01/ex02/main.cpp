/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:23:09 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/09 09:41:56 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	str("HI THIS IS BRAIN");
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout
		<< "&str      = [" << std::hex << &str << "]; [" << str << "];\n"
		<< "stringPTR = [" << std::hex << stringPTR << "]; [" << *stringPTR << "];\n"
		<< "stringREF = [" << std::hex << &stringREF << "]; [" << stringREF << "];\n"
		<< std::flush;
}
