/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:52:57 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/17 12:04:55 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

int	main()
{
	float	fp_num = 42.42f;
	int		intger_part = static_cast<int>roundf(fp_num);
	float	fractional_part = fp_num - intger_part;
	if (errno != 0) {
		std::cout << "error: roundf(); [" << errno << "]" << std::endl;
		return (1);
	}

	std::cout << "Floating point number : [" << fp_num << "]" << std::endl;
	std::cout << "Intger part number    : [" << integer_part << "]" << std::endl;
	std::cout << "Intger part number    : [" << fractional_part << "]" << std::endl;
}
