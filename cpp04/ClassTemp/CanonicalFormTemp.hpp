/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CanonicalFormTemp.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/25 10:48:35 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HPP
# define _HPP

class CanonicalFormTemp {
	public:
		// CONSTRUCTER
		CanonicalFormTemp();
		CanonicalFormTemp(const std::string& type);
		CanonicalFormTemp(const CanonicalFormTemp& src);

		// OPERATOR
		CanonicalFormTemp&	operator=(const CanonicalFormTemp& rhs);

		// GETTER

		// SETTER

		// SUBJECT FUNC

		// DESTRUCTER
		virtual ~CanonicalFormTemp();

	protected:
		// SUBJECT ATTRIBUTE

		// MY ATTRIBUTE

};

#endif
