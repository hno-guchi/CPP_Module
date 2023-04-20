/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Practice.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:31:51 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/20 10:58:53 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// MY
template <typename RET, typename T1, typename T2, typename T3>
RET	search(T1 ary, T2 target, T3 size)
{
	for (int i = size; 0 < i; i--)
	{
		if (ary[i - 1] == target)
		{
			return (ary[i - 1]);
		}
	}
	return (0);
}

// ANS
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

// 1
template <typename T>
T*	LinearSearch(T* array, size_t size, T target)
{
	for (size_t i = 0; i < size; i++) {
		if (array[i] == target) {
			return (&(array[i]));
		}
	}
	return (NULL);
}

// 2
template <typename T>
const T*	LinearSearch(const T* array, size_t size, T target)
{
	for (size_t i = 0; i < size; i++) {
		if (array[i] == target) {
			return (&(array[i]));
		}
	}
	return (NULL);
}

template <typename T>
T*	LinearSearch(T* array, size_t size, T target)
{
	return (const_cast<T*>(LinearSearch(static_cast<const T*>(array), size, target)));
}

int	main()
{
	int	ary1[] = {1, 2, 3, 4, 5};

	std::cout << search<int>(ary1, 0, 5) << std::endl;
}
