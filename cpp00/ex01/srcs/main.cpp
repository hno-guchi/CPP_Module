/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:49:18 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/27 10:28:39 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static bool	is_command(std::string command)
{
	static std::string	command_list[COMMAND_COUNT] = {
		"ADD",
		"SEARCH",
		"EXIT",
	};

	for (int i = 0; i < COMMAND_COUNT; i++) {
		if (command == command_list[i]) {
			return (true);
		}
	}
	return (false);
}

static void	do_command(std::string command, PhoneBook *phonebook)
{
	if (command == "ADD") {
		phonebook->add_command();
	} else if (command == "SEARCH") {
		phonebook->search_command();
	} else if (command == "EXIT") {
		phonebook->exit_command();
	} else {
		std::cout << "Error: Command not exist.\n" << std::endl;
	}
}

int	main()
{
	PhoneBook	phonebook;
	std::string	command;

	for (;;) {
		std::cout << "PhoneBook: ";
		std::getline(std::cin, command);
		if (command == "") {
			;
		} else if (!is_command(command)) {
			error_message(NOT_COMMAND);
		} else {
			do_command(command, &phonebook);
		}
	}
}
