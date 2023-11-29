/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Csv.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguch@42tokyo.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:51:17 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/29 14:16:41 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSV_HPP
# define CSV_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include <list>
#include "color.hpp"

class Csv {
private:
	std::string										fileName_;
	bool											isHeader_;
	size_t											countField_;
	std::map<size_t, std::string>					header_;
	std::list<std::map<std::string, std::string> >	record_;

	void	setHeader(std::string line, const std::string& delimiter);
	void	setRecord(const std::string& fileName);
public:
	// CONSTRUCTOR
	Csv(const std::string& fileName = "data.csv", const bool isHeader = true);
	// Csv(const Csv& src);
	// DESTRUCTOR
	~Csv();
	// OPERATOR
	// Csv&	operator=(const Csv& rhs);
	// GETTER
	const std::string&	getFileName() const;
	const size_t		getCountField() const;
	const bool			getIsHeader() const;
	// const std::map<size_t, std::string>	getHeader() const;
	// SETTER
	// EXCEPTION
	class FatalErr : public std::logic_error {
	public:
		FatalErr(const std::string& msg = "Fatal error.");
	};
	class ValidErr : public std::logic_error {
	public:
		ValidErr(const std::string& msg = "Validation error.");
	};
};

#endif
