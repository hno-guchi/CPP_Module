/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:56:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/18 15:24:48 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP

#include "debugMessage.hpp"
#include "color.hpp"
#include <random>
#include <stdexcept>
#include "Base.hpp"

class Base;
class B;
class C;

class A : public Base {
private:
public:
	// CONSTRUCTOR
	A();
	// DESTRUCTOR
	virtual ~A();
	// SUB fUNC
	Base*	generate(void);
	void	identify(Base* p);
	void	identify(Base& p);
};

#endif
