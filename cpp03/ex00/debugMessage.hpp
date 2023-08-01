/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugMessage.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:09:31 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/08/01 10:07:18 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGMESSAGE_HPP
# define DEBUGMESSAGE_HPP

#include <iostream>

# define DEFAULT_CONSTRUCT_MESSAGE "Default constructor called"
# define HAS_ARGS_CONSTRUCT_MESSAGE "Has args constructor called"
# define COPY_CONSTRUCT_MESSAGE "Copy constructor called"
# define COPY_OPERATOR_MESSAGE "Copy assignment operator called"
# define DESTRUCT_MESSAGE "Destructor called"

typedef enum eMessageType {
	DEFAULT_CONSTRUCT,
	HAS_ARGS_CONSTRUCT,
	COPY_CONSTRUCT,
	COPY_OPERATOR,
	DESTRUCT,
	NOT_MESSAGE
}	tMessageType;

void	debugMessage(const std::string &prefix, tMessageType type);
void	debugMessageAttack(const std::string& prefix, const std::string& name, const std::string& target, const unsigned int& amount);
void	debugMessageTakeDamage(const std::string& prefix, const std::string& name, const unsigned int& amount);
void	debugMessageBeRepaired(const std::string& prefix, const std::string& name, const unsigned int& amount);

#endif
