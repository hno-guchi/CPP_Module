/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Teacher.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:46:18 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/21 10:07:58 by hnoguchi         ###   ########.fr       */
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

/*
void	Teacher::SetData(std::string name, int grade)
{
	mName = name;
	mGrade = grade;
	for (int i = 0; i < SIZE_OF_ARRAY(mChargeStudents); i++)
	{
		mChargeStudents[i] = NULL;
	}
	mChargeStudentsCount = 0;
}

void	Teacher::AddChargeStudent(Student *student)
{
	if (SIZE_OF_ARRAY(mChargeStudents) < mChargeStudentsCount)
	{
		return ;
	}
	if (student->GetGrade() != mGrade)
	{
		return ;
	}
	if (student == NULL)
	{
		return ;
	}
	mChargeStudents[mChargeStudentsCount] = student;
	mChargeStudentsCount += 1;
}
*/
