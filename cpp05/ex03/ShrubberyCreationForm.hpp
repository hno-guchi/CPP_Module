/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/12 16:22:25 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "debugMessage.hpp"
#include "color.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <ios>

class AForm;

class ShrubberyCreationForm : public AForm {
private:
	// SUBJECT ATTRIBUTE

	// MY ATTRIBUTE
	// std::string	suffix_ = "_shrubbery";
	const static int	signGrade_ = 145;
	const static int	execGrade_ = 137;
	// SUBJECT FUNC
	virtual void	action() const;
public:
	// CONSTRUCTER
	// ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target = "SAMPLE");
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	// DESTRUCTER
	~ShrubberyCreationForm();
	// OPERATOR
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& rhs);
	// GETTER
	int						getSignGrade() const;
	int						getExecGrade() const;
	// const std::string&	getSuffix() const;
	// SETTER
	// EXCEPTION
	class FailedOpenFdException : public std::ios_base::failure {
	public:
		FailedOpenFdException(const std::string& msg = "Failed open fd.");
	};
};

#endif
