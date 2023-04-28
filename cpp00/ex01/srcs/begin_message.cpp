/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_message.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:13:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/28 10:31:13 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

static void	print_message_in_main()
{
	std::cout << "Hello. This app can use command ADD, SEARCH and EXIT only.\n\n"
		<< "ADD    : Add contact data in app.\n"
		<< "SEARCH : Search phone number in app. if exist out put data.\n"
		<< "EXIT   : Finish app. Please note that register data will be lost.\n"
		<< std::endl;
}

static void	print_message_in_add()
{
	std::cout << "\n[Add] : "
		<< "Please enter this format.\n"
		<< "ex)        : [First name] [Last name] [Nickname] [Phone number] [Darkest secret]"
		<< std::endl;
}

static void	print_message_in_search()
{
	std::cout << "\n[SEARCH] : "
		<< "Pleas enter phone number. (Only number. Not use hyphen(-).)"
		<< std::endl;
}

void	begin_message(SITUATION type)
{
	switch(type) {
		case MAIN:
			print_message_in_main();
			break ;
		case ADD:
			print_message_in_add();
			break ;
		case SEARCH:
			print_message_in_search();
			break ;
		default:
			break ;
	}
}
