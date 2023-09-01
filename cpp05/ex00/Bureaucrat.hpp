/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/09/01 14:47:29 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "debugMessage.hpp"
#include <iostream>

class Bureaucrat {
	public:
		// CONSTRUCTER
		Bureaucrat();
		Bureaucrat(const std::string& name, const int& grade);
		Bureaucrat(const Bureaucrat& src);

		// OPERATOR
		Bureaucrat&			operator=(const Bureaucrat& rhs);
		const Bureaucrat&	operator<<(const Bureaucrat& rhs) const;

		// GETTER
		const std::string&	getName() const;
		const int&			getGrade() const;

		// SETTER

		// SUBJECT FUNC
		void	incrementGrade(const int& range);
		void	decrementGrade(const int& range);

		// DESTRUCTER
		virtual ~Bureaucrat();

	private:
		// SUBJECT ATTRIBUTE
		const std::string	name;
		int					grade;

		// MY ATTRIBUTE

};

#endif
