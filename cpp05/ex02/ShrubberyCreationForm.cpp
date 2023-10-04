/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/04 17:34:34 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// CONSTRUCTER
ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm(DEFAULT_FORM_NAME, SBC_SIGN_GRADE, SBC_EXEC_GRADE)
{
	debugMessage("ShrubberyCreationForm", DEFAULT_CONSTRUCT);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm(target, SBC_SIGN_GRADE, SBC_EXEC_GRADE)
{
	debugMessage("ShrubberyCreationForm", HAS_ARGS_CONSTRUCT);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) :
	AForm(src)
{
	debugMessage("ShrubberyCreationForm", COPY_CONSTRUCT);
}

// DESTRUCTER
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	debugMessage("ShrubberyCreationForm", DESTRUCT);
}

// OPERATOR
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this == &rhs) {
		return (*this);
	}
	AForm::operator=(rhs);
	debugMessage("ShrubberyCreationForm", COPY_OPERATOR);
	return (*this);
}

// GETTER

// SETTER

// SUBJECT FUNC
static void	writeAsciiTree(std::ofstream& fd)
{
	fd \
		<< "                           ........\n" \
		<< "                            ;::;;::;,\n" \
		<< "                            ;::;;::;;,\n" \
		<< "                           ;;:::;;::;;,\n" \
		<< "           .vnmmnv%vnmnv%,.;;;:::;;::;;,  .,vnmnv%vnmnv,\n" \
		<< "        vnmmmnv%vnmmmnv%vnmmnv%;;;;;;;%nmmmnv%vnmmnv%vnmmnv\n" \
		<< "      vnmmnv%vnmmmmmnv%vnmmmmmnv%;:;%nmmmmmmnv%vnmmmnv%vnmmmnv\n" \
		<< "     vnmmnv%vnmmmmmnv%vnmmmmmmmmnv%vnmmmmmmmmnv%vnmmmnv%vnmmmnv\n" \
		<< "    vnmmnv%vnmmmmmnv%vnmmmmmmmmnv%vnmmmmmmmmmmnv%vnmmmnv%vnmmmnv\n" \
		<< "   vnmmnv%vnmmmmmnv%vnmm;mmmmmmnv%vnmmmmmmmm;mmnv%vnmmmnv%vnmmmnv,\n" \
		<< "  vnmmnv%vnmmmmmnv%vnmm;' mmmmmnv%vnmmmmmmm;' mmnv%vnmmmnv%vnmmmnv\n" \
		<< "  vnmmnv%vnmmmmmnv%vn;;    mmmmnv%vnmmmmmm;;    nv%vnmmmmnv%vnmmmnv\n" \
		<< " vnmmnv%vnmmmmmmnv%v;;      mmmnv%vnmmmmm;;      v%vnmmmmmnv%vnmmmnv\n" \
		<< " vnmmnv%vnmmmmmmnv%vnmmmmmmmmm;;       mmmmmmmmmnv%vnmmmmmmnv%vnmmmnv\n" \
		<< " vnmmnv%vnmmmmmmnv%vnmmmmmmmmmm;;     mmmmmmmmmmnv%vnmmmmmmnv%vnmmmnv\n" \
		<< " vnmmnv%vnmmmmm nv%vnmmmmmmmmmmnv;, mmmmmmmmmmmmnv%vn;mmmmmnv%vnmmmnv\n" \
		<< " vnmmnv%vnmmmmm  nv%vnmmmmmmmmmnv%;nmmmmmmmmmmmnv%vn; mmmmmnv%vnmmmnv\n" \
		<< " `vnmmnv%vnmmmm,  v%vnmmmmmmmmmmnv%vnmmmmmmmmmmnv%v;  mmmmnv%vnnmmnv'\n" \
		<< "  vnmmnv%vnmmmm;,   %vnmmmmmmmmmnv%vnmmmmmmmmmnv%;'   mmmnv%vnmmmmnv\n" \
		<< "   vnmmnv%vnmmmm;;,   nmmm;'              mmmm;;'    mmmnv%vnmmmmnv'\n" \
		<< "   `vnmmnv%vnmmmmm;;,.         mmnv%v;,            mmmmnv%vnmmmmnv'\n" \
		<< "    `vnmmnv%vnmmmmmmnv%vnmmmmmmmmnv%vnmmmmmmnv%vnmmmmmnv%vnmmmmnv'\n" \
		<< "      `vnmvn%vnmmmmmmnv%vnmmmmmmmnv%vnmmmmmnv%vnmmmmmnv%vnmmmnv'\n" \
		<< "          `vn%vnmmmmmmn%:%vnmnmmmmnv%vnmmmnv%:%vnmmnv%vnmnv'\n" \
		<< "\n" \
		<< " #  #   #   #### #### #   #\n" \
		<< " ####  ###  # ## # ##  ###\n" \
		<< " #  # # # # #    #      #\n" \
		<< "\n" \
		<< "        #  #   #   #   #    ##  #     # #### #### #  ##\n" \
		<< "        ####  ###  #   #   #  #  # # #  #--  #--  # # #\n" \
		<< "        #  # #   # ### ###  ##    ###   #### #### ##  #" \
		<< std::endl;
}

static const std::string	getFileName(const std::string& target)
{
	std::string				fileName;
	std::string::size_type	pathPosition(0);

	if ((pathPosition = target.find_last_of('/')) != std::string::npos) {
		fileName = target.substr(pathPosition + 1);
	}
	else {
		fileName = target;
	}
	fileName += SBC_SUFFIX;
	return (fileName);
}

void	ShrubberyCreationForm::createAsciiTree()
{
	try {
		const std::string	fileName(getFileName(this->getName()));
		std::ofstream		fileFd(fileName.c_str()); // (std::string str); c++98

		if (fileFd.is_open() == false) {
			throw ShrubberyCreationForm::FailedOpenFdException();
		}
		writeAsciiTree(fileFd);
		fileFd.close();
	}
	catch (std::exception& e) {
			std::cerr << RED << e.what() << END << std::endl;
	}
}

// EXCEPTION
ShrubberyCreationForm::FailedOpenFdException::FailedOpenFdException() throw()
	: message_(FAILED_OPEN_FD_MESSAGE)
{
	debugMessage("FailedOpenFdException", DEFAULT_CONSTRUCT);
}

ShrubberyCreationForm::FailedOpenFdException::~FailedOpenFdException() throw()
{
	debugMessage("FailedOpenFdException", DESTRUCT);
}

const char*	ShrubberyCreationForm::FailedOpenFdException::what() const throw()
{
	return (this->message_.c_str());
}
