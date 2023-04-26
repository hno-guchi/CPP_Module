/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:49:18 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/26 15:56:04 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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

void	error_message(ERROR_TYPE type)
{
	if (type == NOT_COMMAND) {
		std::cout << "Not command.\n"
			<< "Command is ADD, SEARCH, EXIT only.\n" << std::endl;
	} else if (type == 	ADD_DATA_TOO_FEW) {
		std::cout << "PhoneBook: ADD: Too few data.\n" << std::endl;
	} else if (type == ADD_DATA_STREAM_ERROR) {
		std::cout << "PhoneBook: ADD: Stream error.\n" << std::endl;
	} else {
		std::cout << "Error: Exception Error!!\n" << std::endl;
	}
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
