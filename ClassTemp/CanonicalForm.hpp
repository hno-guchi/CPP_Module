/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CanonicalForm.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/28 15:13:14 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HPP
#define _HPP

#include "debugMessage.hpp"

class CanonicalForm {
	public:
		// CONSTRUCTER
		CanonicalForm();
		CanonicalForm(const std::string& type);
		CanonicalForm(const CanonicalForm& src);

		// OPERATOR
		CanonicalForm&	operator=(const CanonicalForm& rhs);

		// GETTER

		// SETTER

		// SUBJECT FUNC

		// DESTRUCTER
		virtual ~CanonicalForm();

	private:
		// SUBJECT ATTRIBUTE

		// MY ATTRIBUTE

};

#endif
