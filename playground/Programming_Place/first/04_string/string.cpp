/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:33:01 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/04/13 12:11:56 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0
第４章　文字列
https://programming-place.net/ppp/contents/cpp/language/004.html

<string> は、標準ヘッダ。標準ライブラリの１つ。std namespace に所属。
当面、std::string は、構造体のような型と考えれば良い。
（std::string は、std::basic_string といったクラステンプレートに対する typedef）

std::string の内部では、
char の配列があり、必要なタイミングで、メモリの確保や解放を行う。

std::string の初期化
仮引数が[const char *]型のコンストラクタを呼び出している。
初期化値がない場合は、から文字列となる。

std::istringstream
空白を区切り文字とする。
前から順番に変数に入れていく。
"100 20.5 abcde" の時、
"100" のみ変数に入れ、次の処理に移ってもエラーにはならない。

#endif

#include <iostream>
#include <string>
#include <sstream>

int	main()
{
	// Initialize
	std::string str1("abcde");
	std::string str2 = "fghijklmn";
	std::string str3; // str3 == "";
	// std::string str4(NULL); // segmentation fault

	str3 = str1;

	std::cout << "--- [Initialize] ----" << std::endl;
	std::cout << str1 << "\n"
		<< str2 << "\n"
		<< str3
		<< std::endl;
	std::cout << "--------------------\n" << std::endl;

	// Compare
	std::cout << "----- [Compare] -----" << std::endl;
	if (str1 == str3) {
		std::cout << "[OK]" << std::endl;
	} else {
		std::cout << "[NOT]" << std::endl;
	}
	std::cout << "--------------------\n" << std::endl;

	// Size
	std::cout << "------ [Size] -------" << std::endl;
	std::cout << str1 << ": str1.size();   [" << str1.size() << "]\n"
		<< str1 << ": str1.length(); [" << str1.length() << "]"
		<< std::endl;
	std::cout << "--------------------\n" << std::endl;
	
	// Empty
	std::cout << "------ [Empty] ------" << std::endl;
	if (str3.empty() == true) {
		std::cout << "str3.empty(); is [true];" << std::endl;
	} else {
		std::cout << "str3.empty(); is [false];" << std::endl;
	}
	// if (str4.empty() == true) {
	// 	std::cout << "str4.empty(); is [true];" << std::endl;
	// } else {
	// 	std::cout << "str4.empty(); is [false];" << std::endl;
	// }
	std::cout << "--------------------\n" << std::endl;

	// Access char
	char	c = str1[2];
	std::cout << "--- [Access char] ---" << std::endl;
	std::cout << c << std::endl;
	std::cout << "--------------------\n" << std::endl;

	// Write
	std::ostringstream	oss1;
	oss1 << "Write to std::string" << 123;
	std::ostringstream	oss2("initialize version.");

	std::cout << "-- [Write string] --" << std::endl;
	std::string	str4(oss1.str());
	std::cout << str4 << std::endl;
	std::string	str5(oss2.str());
	std::cout << str5 << std::endl;
	std::cout << "--------------------\n" << std::endl;

	// Read
	std::string	str6("100 24.5 abcde");
	std::istringstream	iss(str6);

	int			num;
	double		d;
	std::string	str7;

	std::cout << "-- [Read string] ---" << std::endl;
	iss >> num >> d >> str7;
	std::cout << num << " " << d << " " << str7 << std::endl;
	std::cout << "--------------------\n" << std::endl;
}
