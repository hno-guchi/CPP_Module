/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/05 15:27:12 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "debugMessage.hpp"
#include "color.hpp"

class Intern {
private:
	// SUBJECT ATTRIBUTE

	// MY ATTRIBUTE

public:
	// CONSTRUCTER
	Intern();
	Intern(const std::string& type);
	Intern(const Intern& src);
	// DESTRUCTER
	~Intern();

	// OPERATOR
	Intern&	operator=(const Intern& rhs);

	// GETTER

	// SETTER

	// SUBJECT FUNC

};

#endif
