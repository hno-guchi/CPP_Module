/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:30:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/20 19:31:15 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Student.hpp"
#include "Teacher.hpp"

namespace {
	void	CompareScore(Student *a, Student *b)
	{
		int	ScoreA = a->GetScore();
		int	ScoreB = b->GetScore();
	
		if (ScoreA == ScoreB)
		{
			std::cout << "...Same Score..." << std::endl;
		}
		else if (ScoreA < ScoreB)
		{
			std::cout << b->GetName() << std::endl;
		}
		else
		{
			std::cout << a->GetName() << std::endl;
		}
	}
}

int	main()
{
	Teacher	teacher;
	teacher.SetData("Ikeda Hayato", 3);

	Student	a;
	a.SetData("Aida Satoshi", 3, 80);
	teacher.AddStudent(&a);

	Student	b;
	b.SetData("Baba Hiroshi", 3, 82);
	teacher.AddStudent(&b);

	Student	c;
	c.SetData("Ishikawa Goemon", 2, 89);
	teacher.AddStudent(&c);

	a.PrintMember();
	b.PrintMember();
	c.PrintMember();

	CompareScore(&a, &b);
	teacher.PrintMyStudents();
}
