/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Csv.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:48:41 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/11/29 14:17:12 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Csv.hpp"
#include "debugMessage.hpp"

// CONSTRUCTOR
Csv::Csv(const std::string& fileName, const bool isHeader) :
	fileName_(fileName), isHeader_(isHeader), countField_(0)
{
#ifdef DEBUG
	debugMessage("Csv", HAS_ARG_CONSTRUCT);
#endif // DEBUG
}

Csv::~Csv()
{
#ifdef DEBUG
	debugMessage("Csv", DESTRUCT);
#endif // DEBUG
}

// GETTER
const std::string&	Csv::getFileName() const
{
	return (this->fileName_);
}

const size_t	Csv::getCountField() const
{
	return (this->countField_);
}

const bool	Csv::getIsHeader() const
{
	return (this->isHeader_);
}

static void	getField(std::string& field, std::string& line, const std::string& delimiter)
{
	if (line.empty()) {
		// throw Csv::ValidErr("Empty field.");
		return ;
	}
	try {
		// if (line == delimiter) {
		// 	throw Csv::ValidErr("Bad line format.");
		// }
		size_t	pos = line.find(delimiter);
		if (pos == std::string::npos) {
			field = line.substr(0);
			line = "";
		}
		// else if (pos == 0) {
		// 	throw Csv::ValidErr("Bad line format.");
		// }
		else if (pos == line.size() - delimiter.size()) {
			throw Csv::ValidErr("Bad line format.");
		}
		else {
			field = line.substr(0, pos);
			line = line.substr(pos + delimiter.size());
		}
		// if (line == delimiter) {
		// 	throw Csv::ValidErr("Bad line format.");
		// }

		if (field.empty()) {
			throw Csv::ValidErr("Empty field.");
		}

		if (field.find(' ') != std::string::npos) {
			throw Csv::ValidErr("Bad field format.");
		}
	}
	catch (const std::exception& e) {
		throw ;
	}
}

void	Csv::setHeader(std::string line, const std::string& delimiter)
{
	size_t		i(0);
	std::string	field("");
	try {
		while (!line.empty()) {
			getField(field, line, delimiter);
			this->header_[i] = field;
			i += 1;
			// std::cout << field << std::endl;
		}
	}
	catch (const std::exception& e) {
		throw ;
	}
}

void	Csv::setRecord(const std::string& fileName)
{
	try {
		std::ifstream	fd(fileName);

		if (fd.fail() || fd.eof()) {
			throw Csv::FatalErr("Failed std::ifstream().");
		}
		std::string		line("");
		if (this->isHeader_) {
			std::getline(fd, line, '\n');
			if (fd.fail()) {
				throw Csv::FatalErr("Failed std::getline().");
			}
			this->setHeader(line, ",");
		}
		if (this->header_.size() != this->countField_) {
			throw Csv::ValidErr("Bad header format.");
		}
		// while (std::getline(fd, line, '\n')) {
		// 	std::map<size_t, std::string> fields;
		// 	tokenize(fields, line, ",");
		// 	parseFields(fields);
		// 	addData(fields);
		// }
	}
	catch (const std::exception& e) {
		throw ;
	}
}

// EXCEPTION
Csv::FatalErr::FatalErr(const std::string& msg) : std::logic_error(msg) {}
Csv::ValidErr::ValidErr(const std::string& msg) : std::logic_error(msg) {}

// GETTER
// const std::map<size_t, std::string>	Csv::getHeader() const
// {
// 	return (this->header_);
// }
