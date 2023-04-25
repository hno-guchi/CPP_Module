/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:49:18 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/21 18:10:11 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

# define COMMAND_COUNT 3

enum ERROR_TYPE {
	NOT_COMMAND,
};

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

static void	error_message(ERROR_TYPE type)
{
	if (type == NOT_COMMAND) {
		std::cout << "Not command.\n"
			<< "Command is ADD, SEARCH, EXIT only.\n" << std::endl;
	} else {
		std::cout << "Exception Error!!\n" << std::endl;
	}
}

int	main()
{
	std::string	command;

	while (1)
	{
		std::cout << "PhoneBook: ";
		std::getline(std::cin, command);
		if (command == "") {
			;
		} else if (!is_command(command)) {
			error_message(NOT_COMMAND);
		} else {
			std::cout << command << std::endl;
		}
	}
}
