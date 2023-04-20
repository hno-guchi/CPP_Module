/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:54:38 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/20 15:10:44 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0

Programming Place Plus C++

第１１章　クラス
https://programming-place.net/ppp/contents/cpp/language/011.html

オブジェクト指向プログラミング（Object Oriented Programming Language : OOPL）
オブジェクトとは、データや処理をまとめた「もの」のこと。
クラスとは、オブジェクトの定義を表したもの。オブジェクトを作り出す基になる存在。
クラスからオブジェクトを生成することを「インスタンス化（実体化）」と言い、
生成されたオブジェクトを「インスタンス（実体）」と呼ぶ。

OOPの考え方
１。いくつかのオブジェクトを作成する。
２。それぞれのオブジェクトが与えられた処理を実行する。
３。必要があれば、他のオブジェクトに処理を依頼する。
ことで、プログラムを構築するという考え方をとる。

#endif

#include <iostream>

class Teacher {
	std::string	m_Name;
	int			m_Age;

public:
	void	SetData(std::string name, int age);
	void	IncrementAge();
	void	PrintMember();
};

void	Teacher::SetData(std::string name, int age)
{
	m_Name = name;
	m_Age = age;
}

void	Teacher::IncrementAge()
{
	m_Age += 1;
}

void	Teacher::PrintMember()
{
	std::cout << "m_Name : " << m_Name << std::endl;
	std::cout << "m_Age  : " << m_Age << std::endl;
}

class Student {
	std::string	m_Name;
	int			m_Grade;
	int			m_Score;

	const Teacher	*m_MyTeacher;

public:
	void	SetData(std::string name, int grade, int score, const Teacher *teacher);
	void	Promotion();
	void	PrintMember();
};

void	Student::SetData(std::string name, int grade, int score, const Teacher *teacher)
{
	// this->m_Name = name;
	// this->m_Grade = grade;
	// this->m_Score = score;
	// this->m_MyTeacher = teacher;
	m_Name = name;
	m_Grade = grade;
	m_Score = score;
	m_MyTeacher = teacher;
}

void	Student::Promotion()
{
	if (m_Grade < 6)
	{
		m_Grade += 1;
	}
}

void	Student::PrintMember()
{
	std::cout << "m_Name      : " << m_Name << "\n"
		<< "m_Grade     : " << m_Grade << "\n"
		<< "m_Score     : " << m_Score << "\n"
		<< "m_MyTeacher : " << m_MyTeacher
		<< std::endl;
}

int	main()
{
	Teacher	teacher;
	teacher.SetData("Ikeda Hayato", 33);

	teacher.PrintMember();
	std::cout << "==============================" << std::endl;

	Student	student;
	student.SetData("Satou Takeru", 1, 80, &teacher);

	student.PrintMember();
	std::cout << "==============================" << std::endl;

	teacher.IncrementAge();
	student.Promotion();

	teacher.PrintMember();
	std::cout << "==============================" << std::endl;

	student.PrintMember();
}
