/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:33:12 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/25 18:44:31 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

class Span {
private:
	std::string	size;

public:
	// CONSTRUCTOR
	Span();
	Span(unsigned int size);
	Span(const Span& src);
	// DESTRUCTOR
	~Span();
	// OPERATOR
	Span&	operator=(const Span& rhs);
};

#endif
