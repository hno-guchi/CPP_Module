/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/08/31 16:38:38 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "debugMessage.hpp"

class Bureaucrat {
	public:
		// CONSTRUCTER
		Bureaucrat();
		Bureaucrat(const std::string& name);
		Bureaucrat(const Bureaucrat& src);

		// OPERATOR
		Bureaucrat&	operator=(const Bureaucrat& rhs);

		// GETTER

		// SETTER

		// SUBJECT FUNC

		// DESTRUCTER
		virtual ~Bureaucrat();

	private:
		// SUBJECT ATTRIBUTE
		const std::string	name;
		int					grade;

		// MY ATTRIBUTE

};

#endif
