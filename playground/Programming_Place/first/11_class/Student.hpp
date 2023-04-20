/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:19:44 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/20 19:23:03 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STUDENT_HPP
# define STUDENT_HPP

#include <iostream>

class Student {
	std::string	m_Name;
	int			m_Grade;
	int			m_Score;
	// Teacher		*m_MyTeacher;

public:
	void			SetData(std::string name, int grade, int score);
	void			PrintMember();
	std::string		GetName();
	int				GetGrade();
	int				GetScore();
};

#endif
