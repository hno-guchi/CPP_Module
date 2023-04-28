/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:49:18 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/28 09:54:54 by hnoguchi         ###   ########.fr       */
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

	phonebook.initialize();
	begin_message(MAIN);
	while (1) {
		if (!getline_prompt("PhoneBook: ", &command)) {
			break ;
		}
		if (command == "") {
			continue ;
		}
		if (!is_command(command)) {
			error_message(NOT_COMMAND);
		} else {
			do_command(command, &phonebook);
		}
		if (std::cin.eof() == true || std::cin.fail() == true) {
			break ;
		}
	}
}
