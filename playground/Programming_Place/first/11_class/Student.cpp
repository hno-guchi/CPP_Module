/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:12:08 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/20 19:16:07 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Student.hpp"

void	Student::SetData(std::string name, int grade, int score)
{
	m_Name = name;
	m_Grade = grade;
	m_Score = score;
}

void	Student::PrintMember()
{
	std::cout << m_Name << "	"
		<< m_Grade << "	"
		<< m_Score << std::endl;
}

std::string	Student::GetName()
{
	return (m_Name);
}

int	Student::GetGrade()
{
	return (m_Grade);
}

int	Student::GetScore()
{
	return (m_Score);
}
