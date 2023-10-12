/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/12 16:12:57 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "debugMessage.hpp"
#include "color.hpp"

class AForm;

class PresidentialPardonForm : public AForm {
private:
	// SUBJECT ATTRIBUTE
	// MY ATTRIBUTE
	const static int	signGrade_ = 25;
	const static int	execGrade_ = 5;
	std::string			target_;
	// SUBJECT FUNC
	virtual void	action() const;
public:
	// CONSTRUCTER
	// PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target = "SAMPLE");
	PresidentialPardonForm(const PresidentialPardonForm& src);
	// DESTRUCTER
	~PresidentialPardonForm();
	// OPERATOR
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& rhs);
	// GETTER
	int						getSignGrade() const;
	int						getExecGrade() const;
	const std::string&	getTarget() const;
	// SETTER
	void				setTarget(const std::string& target);
};

#endif
