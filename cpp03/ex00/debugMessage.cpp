/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugMessage.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:09:31 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/08/01 10:07:59 by hnoguchi         ###   ########.fr       */
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
			writeMessage(DEFAULT_CONSTRUCT_MESSAGE);
			break;
		case HAS_ARGS_CONSTRUCT:
			writeMessage(HAS_ARGS_CONSTRUCT_MESSAGE);
			break;
		case COPY_CONSTRUCT:
			writeMessage(COPY_CONSTRUCT_MESSAGE);
			break;
		case COPY_OPERATOR:
			writeMessage(COPY_OPERATOR_MESSAGE);
			break;
		case DESTRUCT:
			writeMessage(DESTRUCT_MESSAGE);
		default:
			break;
	}
}

void	debugMessageAttack(const std::string& prefix, const std::string& name, const std::string& target, const unsigned int& amount)
{
	std::cout << prefix << ": " << name << " attacks " << target << ", causing " << amount << " points of damage!" << std::endl;
}

void	debugMessageTakeDamage(const std::string& prefix, const std::string& name, const unsigned int& amount)
{
	std::cout << prefix << ": "<< name << " is attacked, causing " << amount << " points of damage!" << std::endl;
}

void	debugMessageBeRepaired(const std::string& prefix, const std::string& name, const unsigned int& amount)
{
	std::cout << prefix << ": "<< name << " is repaired, causing " << amount << " points of repaire!" << std::endl;
}
