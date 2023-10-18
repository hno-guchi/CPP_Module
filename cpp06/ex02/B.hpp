/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:56:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/18 15:25:17 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP

#include "debugMessage.hpp"
#include "color.hpp"
#include <random>
#include <stdexcept>
#include "Base.hpp"

class Base;
class A;
class C;

class B : public Base {
public:
	// CONSTRUCTOR
	B();
	// DESTRUCTOR
	virtual ~B();
	// SUB fUNC
	Base*	generate(void);
	void	identify(Base* p);
	void	identify(Base& p);
};

#endif
