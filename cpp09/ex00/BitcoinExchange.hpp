/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguch@42tokyo.jp>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:51:17 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/14 16:37:29 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
// #include <string>
#include <map>
#include "debugMessage.hpp"

class BitcoinExchange {
private:
	std::string		fileName_;
	std::ifstream	fd_;

public:
	// CONSTRUCTOR
	BitcoinExchange(const std::string& name);
	BitcoinExchange(const BitcoinExchange& src);
	// DESTRUCTOR
	~BitcoinExchange();
	// OPERATOR
	BitcoinExchange&	operator=(const BitcoinExchange& rhs);
	// GETTER
	const std::string&		getFileName() const;
	const std::ifstream&	getFd() const;
	// SETTER
};

#endif
