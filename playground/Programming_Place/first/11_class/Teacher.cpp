/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Teacher.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:46:18 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/20 19:20:38 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Teacher.hpp"

void	Teacher::SetData(std::string name, int grade)
{
	m_Name = name;
	m_Grade = grade;
	m_StudentCount = 0;
}

int		Teacher::GetGrade()
{
	return (m_Grade);
}

void	Teacher::AddStudent(Student *s)
{
	if (GetGrade() != s->GetGrade())
	{
		return ;
	}
	m_StudentList[m_StudentCount] = s;
	m_StudentCount += 1;
}

void	Teacher::PrintMyStudents()
{
	for (int i = 0; i < m_StudentCount; i++)
	{
		m_StudentList[i]->PrintMember();
	}
}
