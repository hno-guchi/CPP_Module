/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:49:18 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/26 18:44:02 by hnoguchi         ###   ########.fr       */
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

void	error_message(ERROR_TYPE type)
{
	if (type == NOT_COMMAND) {
		std::cout << "PhoneBook: : Command not found. Only command [ADD, SEARCH, EXIT].\n" << std::endl;
	} else if (type == 	ADD_DATA_TOO_FEW) {
		std::cout << "PhoneBook: ADD: Too few data.\n" << std::endl;
	} else if (type == ADD_DATA_STREAM_ERROR) {
		std::cout << "PhoneBook: ADD: Stream error.\n" << std::endl;
	} else if (type == ADD_DATA_NAME_TOO_LONG) {
		std::cout << "PhoneBook: ADD: Too long data. Over 20 characters First or Last name.\n" << std::endl;
	} else if (type == ADD_DATA_NAME_NOT_ONLY_ALPHA) {
		std::cout << "PhoneBook: ADD: Wrong name. Please only alphabet First or Last name.\n" << std::endl;
	} else if (type == ADD_DATA_NICKNAME_ERR_VALID) {
		std::cout << "PhoneBook: ADD: Wrong nickname. Please only alphabet or hyphen(-) or underber(_).\n" << std::endl;
	} else if (type == ADD_DATA_PHONE_NUMBER_PREFIX_NOT_ZERO) {
		std::cout << "PhoneBook: ADD: Wrong phone number. Please prefix zero(0).\n" << std::endl;
	} else if (type == ADD_DATA_PHONE_NUMBER_TOO_LONG) {
		std::cout << "PhoneBook: ADD: Too long phone number. Number is 10 or 11 chracters.\n" << std::endl;
	} else if (type == ADD_DATA_PHONE_NUMBER_ERR_VALID) {
		std::cout << "PhoneBook: ADD: Wrong phone number. Please only number.\n" << std::endl;
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
