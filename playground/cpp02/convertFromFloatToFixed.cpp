/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertFromFloatToFixed.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:56:07 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/18 14:20:52 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include <cfloat>

# define END             "\033[0m"

# define RED             "\033[31m"
# define GREEN           "\033[32m"
# define YELLOW          "\033[33m"

# define FRACTIONAL_BITS 8

void	converter(float fromNum)
{
	std::cout << GREEN << "========== " << fromNum << " ==========" << END << std::endl;
	int		fixed = static_cast<int>(roundf(fromNum * (1 << FRACTIONAL_BITS)));

	float	fromFixed = static_cast<float>(fixed);
	fromFixed /= (1 << FRACTIONAL_BITS);

	std::cout << "Floating point number     : [" << fromNum << "]" << std::endl;
	std::cout << "Fixed point number        : [" << fixed << "]" << std::endl;
	std::cout << "Floating point from fixed : [" << fromFixed << "]" << std::endl;

	std::cout << std::endl;
}

int	main()
{
	converter(42.42f);
	converter(1234.4312f);
	converter(FLT_MAX);
}
