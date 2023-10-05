/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/05 10:37:31 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "debugMessage.hpp"
#include "color.hpp"
#include "AForm.hpp"

# define PP_SIGN_GRADE 25
# define PP_EXEC_GRADE 5

class PresidentialPardonForm : public AForm {
private:
	// SUBJECT ATTRIBUTE

	// MY ATTRIBUTE

	// SUBJECT FUNC
	void	action() const;
public:
	// CONSTRUCTER
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	// DESTRUCTER
	~PresidentialPardonForm();

	// OPERATOR
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& rhs);

	// GETTER

	// SETTER
};

#endif
