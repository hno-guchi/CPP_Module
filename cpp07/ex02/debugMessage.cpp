/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugMessage.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:09:31 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/20 17:23:34 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debugMessage.hpp"

static void	writeMessage(const std::string &message)
{
	std::cout << message << std::endl;
}

void	debugMessage(const std::string &prefix, tMessageType type)
{
	std::cout << prefix << ": " << std::flush;
	switch (type) {
		case DEFAULT_CONSTRUCT:
			writeMessage("Default constructor called");
			break;
		case HAS_ARG_CONSTRUCT:
			writeMessage("Has arg constructor called");
			break;
		case COPY_CONSTRUCT:
			writeMessage("Copy constructor called");
			break;
		case COPY_OPERATOR:
			writeMessage("Copy assignment operator called");
			break;
		case GET_INDEX_OPERATOR:
			writeMessage("Index operator called(GET)");
			break;
		case SET_INDEX_OPERATOR:
			writeMessage("Index operator called(SET)");
			break;
		case DESTRUCT:
			writeMessage("Destructor called");
		default:
			break;
	}
}
