/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_space.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:08:05 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/12 19:54:29 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0
第３章　名前空間
https://programming-place.net/ppp/contents/cpp/language/003.html

1. namaspace とは
   同一名称の変数や関数を識別するための枠組みのこと。
   所属するnamespaceが異なれば名前の衝突を避けることができる。
   
   namespace の内側にあるEntity (変数や関数、型など)を、
   「名前空間メンバ」と呼び、「名前空間メンバ」の名前を「名前空間メンバ名」と呼ぶ。
   「名前空間メンバ」を使用する際は、「名前空間名::名前空間メンバ名」と書く。
   int_array::copy();
	student::copy();

   「::」は「スコープ解決演算子」と呼ぶ。（namespace以外でも使用される。）

   同一の namespace 内であれば「名前空間メンバ名」のみでアクセスできる。

   namaspace には、変数の宣言、構造体、列挙型の定義もできる。
   マクロ定義は、namespace の影響を受けない。

2. namespace の分割
   同一名称のnamespace が複数箇所で定義されている場合、
   それらは、１つのnamespace として扱われ、１つの「名前空間スコープ」を形成する。
   このルールがあるので、ソースファイルとヘッダーファイルを分けることができる。

3. namespace の入れ子
   入れ子構造にできる。
   ある「名前空間メンバ」が、自身より深い位置にある「名前空間メンバ」にアクセスする際は、
   「自身が所属する名前空間以降の名前空間名::名前空間メンバ名」でアクセスできる。
   逆に、自身より浅い位置にある「名前空間メンバ」にアクセスする際は、
   アクセスしたい「名前空間メンバ」の完全一致した名前を書く。

4. 無名名前空間
   変数や関数に static を付け内部結合することと同じ意味合いを持つ。
   「無名名前空間」にある「名前空間メンバ」にアクセスする際「スコープ解決演算子」は、いらない。

5. グローバル名前空間
   namespace のブロックに囲まれていないもの。
   main(); は、必ずグローバル名前空間であること。

6. Using directive
7. Using宣言

8. alias
   namespace に別名を付ける。（長いnamespace の省略が可能）
   [namespace 別名 = 元の名前]

#endif

#include "name_space.hpp"

namespace student {
	void	copy(Data *dest, const Data *src)
	{
		dest->name[0] = 'B';
		dest->sex = src->sex;
		dest->score = src->score;
	}
}

int main()
{
	student::Data	student_list[DATA_MAX];

	student_list[0].name[0] = 'A';
	student_list[0].sex = student::Male;
	student_list[0].score = 99;

	student::copy(&(student_list[1]), &(student_list[0]));

	std::cout
		<< "student[0]-------\n"
		<< "name   : " << student_list[0].name << "\n"
		<< "sex    : " << student_list[0].sex << "\n"
		<< "score  : " << student_list[0].score << "\n"
		<< "-----------------\n"
		<< std::endl;

	std::cout
		<< "student[1]-------\n"
		<< "name   : " << student_list[1].name << "\n"
		<< "sex    : " << student_list[1].sex << "\n"
		<< "score  : " << student_list[1].score << "\n"
		<< "-----------------\n"
		<< std::endl;
}

