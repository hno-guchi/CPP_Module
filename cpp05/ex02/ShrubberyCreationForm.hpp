/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/05 08:07:58 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "debugMessage.hpp"
#include "color.hpp"
#include "AForm.hpp"
#include <fstream>
#include <string>
// #include <stdexcept>

# define SBC_SUFFIX "_shrubbery"
# define SBC_SIGN_GRADE 145
# define SBC_EXEC_GRADE 137
# define FAILED_OPEN_FD_MESSAGE "Failed open fd."

class AForm;

class ShrubberyCreationForm : public AForm {
private:
	// SUBJECT ATTRIBUTE

	// MY ATTRIBUTE

public:
	// CONSTRUCTER
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	// DESTRUCTER
	virtual ~ShrubberyCreationForm();
	// OPERATOR
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& rhs);
	// GETTER

	// SETTER

	// SUBJECT FUNC
	void	action() const;
	// EXCEPTION
	class FailedOpenFdException : public std::exception {
	private:
		std::string	message_;
	
	public:
		FailedOpenFdException() throw();
		~FailedOpenFdException() throw();
		const char*	what() const throw();
	};
};

#endif
