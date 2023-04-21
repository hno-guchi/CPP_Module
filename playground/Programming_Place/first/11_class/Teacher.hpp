/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Teacher.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:35:57 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/21 10:08:00 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEACHER_HPP
# define TEACHER_HPP

#include <iostream>
#include "Student.hpp"

// MY
class Teacher {
	std::string	m_Name;
	int			m_Grade;
	Student		*m_StudentList[41];
	int			m_StudentCount;

public:
	void	SetData(std::string name, int grade);
	int		GetGrade();
	void	AddStudent(Student *s);
	void	PrintMyStudents();
};

// 担当できる生徒の最大数
/*
# define CHARGE_STUDENT_MAX 40
# define SIZE_OF_ARRAY(array) sizeof(array)/sizeof(array[0])

class Teacher {
	std::string	mName;
	int			mGrade;
	Student		*mChargeStudents[CHARGE_STUDENT_MAX];
	int			mChargeStudentsCount;

public:
	void	SetData(std::string name, int grade);
	int		GetGrade();
	void	AddChargeStudent(Student *student);
	void	PrintChargeStudentsList();
}
*/

#endif
