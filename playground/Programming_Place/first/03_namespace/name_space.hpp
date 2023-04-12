/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_space.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:01:22 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/12 19:55:02 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAME_SPACE_HPP
# define NAME_SPACE_HPP

#include <iostream>

// 4.
namespace {
	const int	DATA_MAX = 100;
}

// 1.
namespace int_array {
	void	copy(int *dest, int *src);
}

namespace student {

#define SCORE_MAX 100

	enum Sex {
		Male,
		Female,
	};

	struct Data {
		char	name[128];
		Sex		sex;
		int		score;
	};

	void	copy(Data *dest, const Data *src);
}

#endif
