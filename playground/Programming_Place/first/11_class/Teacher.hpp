/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Teacher.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:35:57 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/20 19:27:34 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEACHER_HPP
# define TEACHER_HPP

#include <iostream>
#include "Student.hpp"

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

#endif
