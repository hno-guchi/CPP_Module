/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/12 16:12:36 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

// CONSTRUCTER
// ShrubberyCreationForm::ShrubberyCreationForm() :
// 	AForm("SAMPLE", this->getSignGrade(), this->getExecGrade())
// {
// 	debugMessage("ShrubberyCreationForm", DEFAULT_CONSTRUCT);
// }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm(target, this->getSignGrade(), this->getExecGrade())
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
int	ShrubberyCreationForm::getSignGrade() const
{
	return (this->signGrade_);
}

int	ShrubberyCreationForm::getExecGrade() const
{
	return (this->execGrade_);
}

// const std::string&	ShrubberyCreationForm::getSuffix() const
// {
// 	return (this->suffix_);
// }

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
	fileName += "_shrubbery";
	return (fileName);
}

void	ShrubberyCreationForm::action() const
{
	const std::string	fileName(getFileName(this->getName()));
	std::ofstream		fileFd(fileName.c_str()); // (std::string str); c++98

	if (fileFd.is_open() == false) {
		throw ShrubberyCreationForm::FailedOpenFdException();
	}
	writeAsciiTree(fileFd);
	fileFd.close();
}

// EXCEPTION
ShrubberyCreationForm::FailedOpenFdException::FailedOpenFdException(const std::string& msg) : std::ios_base::failure(msg) {}
