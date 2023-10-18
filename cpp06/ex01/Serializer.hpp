/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/10/18 10:46:20 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIIALIZER_HPP
# define SERIIALIZER_HPP

#include "debugMessage.hpp"
#include "color.hpp"
#include <iostream>
#include <cstdint>

typedef struct s_data Data;

struct s_data {
	std::string	data;
};

class Serializer {
private:
	// SUBJECT ATTRIBUTE
	// MY ATTRIBUTE
	// CONSTRUCTER
	Serializer();
	~Serializer();

public:
	// OPERATOR
	// GETTER
	// SETTER
	// SUBJECT FUNC
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif
