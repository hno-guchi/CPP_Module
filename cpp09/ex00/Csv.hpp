/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Csv.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguch@42tokyo.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:51:17 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/30 15:03:15 by hnoguchi         ###   ########.fr       */
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
	const std::string								fileName_;
	const bool										isHeader_;
	size_t											countField_;
	std::map<size_t, std::string>					header_;
	std::list<std::map<std::string, std::string> >	recordKeyString_;
	std::list<std::map<size_t, std::string> >		recordKeySize_t_;

	void	setHeader(std::string line, const std::string& delimiter);
	void	setRecord(std::ifstream& fd, const std::string& delimiter);
	void	getField(std::string& field, std::string& line, const std::string& delimiter);
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
	size_t				getCountField() const;
	bool				getIsHeader() const;
	const std::map<size_t, std::string>	getHeader() const;
	template <typename TYPE>
	const std::list<std::map<TYPE, std::string> >&	getRecord() const
	{
		if (this->isHeader_) {
			return (this->recordKeyString_);
		}
		return (this->recordKeySize_t_);
	}
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
	// DEBUG
#ifdef DEBUG
	void	debugPrint() const;
#endif // DEBUG

};

#endif
