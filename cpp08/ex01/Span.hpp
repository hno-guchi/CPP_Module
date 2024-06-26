/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:33:12 by hnoguchi          #+#    #+#             */
/*   Updated: 2024/05/17 12:14:42 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Span {
 private:
	 std::vector<int>					data_;
	 std::size_t							capacity_;

 public:
	 // CONSTRUCTOR
	 Span();
	 explicit Span(unsigned int cap);
	 Span(const Span& src);
	 // DESTRUCTOR
	 ~Span();
	 // OPERATOR
	 Span&								operator=(const Span& rhs);
	 // GETTER
	 std::size_t							getSize() const;
	 std::size_t							getCapacity() const;
	 std::vector<int>::iterator			getBegin();
	 std::vector<int>::const_iterator	getBegin() const;
	 std::vector<int>::iterator			getEnd();
	 std::vector<int>::const_iterator	getEnd() const;
	 // SUB_FUNC
	 void								addNumber(int num);
	 std::size_t							shortestSpan() const;
	 std::size_t							longestSpan() const;
	 void								fillRandomNumber();
// EXCEPTION
class OverSize : public std::overflow_error {
 public:
	  explicit OverSize(const std::string& msg = "Over size.");
};
class NotExistSpan : public std::logic_error {
 public:
	 explicit NotExistSpan(const std::string& msg = "Not stored number, or only one.");
};
};

#endif
