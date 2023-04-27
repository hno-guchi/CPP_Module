/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:49:18 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/27 18:47:35 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
	} else if (type == ADD_DATA_PHONE_NUMBER_WRONG_LENGTH) {
		std::cout << "PhoneBook: ADD: Wrong length of phone number. Number is 10 or 11 chracters.\n" << std::endl;
	} else if (type == ADD_DATA_PHONE_NUMBER_ERR_VALID) {
		std::cout << "PhoneBook: ADD: Wrong phone number. Please only number.\n" << std::endl;
	} else if (type == ADD_DATA_SECRET_NOT_USE_CHAR) {
		std::cout << "PhoneBook: ADD: Exist not use char in secret. Only use alphabet, space(\' \'), (,), (.) .\n" << std::endl;
	} else if (type == ADD_DATA_REGISTERED_PHONE_NUMBER) {
		std::cout << "PhoneBook: ADD: Already registered phone number.\n" << std::endl;
	} else if (type == NOT_REGISTERED_PHONE_NUMBER) {
		std::cout << "PhoneBook: SEARCH: Not found. Maybe the phone number is different.\n" << std::endl;
	} else {
		std::cout << "Error: Exception Error!!\n" << std::endl;
	}
}
