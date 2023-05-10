/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:14:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/10 16:21:13 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

static bool	isValidation(int argc, char *argv[])
{
	if (argc != 4) {
		std::cerr << "Error: Invalid arguments." << std::endl;
		return (false);
	}
	std::string	target(argv[2]);
	std::string	replace_word(argv[3]);
	if (target == replace_word) {
		std::cerr << "Error: target == replace_word." << std::endl;
		return (false);
	}
	if (target.empty() == true) {
		std::cerr << "Error: Empty argument. [s1]" << std::endl;
		return (false);
	}
	std::ifstream	sourceFileFd(argv[1]);
	if (sourceFileFd.is_open() == false) {
		std::cerr << "Error: Failed open(sourceFileFd)." << std::endl;
		return (false);
	}
	sourceFileFd.close();
	return (true);
}

static const std::string	getReplaceFileName(std::string str)
{
	std::string				replaceFileName;
	std::string::size_type	pathPosition(0);

	if ((pathPosition = str.find_last_of('/')) != std::string::npos) {
		replaceFileName = str.substr(pathPosition + 1);
	}
	else {
		replaceFileName = str;
	}
	replaceFileName += ".replace";
	return (replaceFileName);
}

static void	do_replace(std::ifstream &inputFd, std::ofstream &outputFd, char *argv[])
{
	std::string	s1(argv[0]);
	std::string	s2(argv[1]);
	std::string	line;

	while (std::getline(inputFd, line, '\n')) {
		if (inputFd.fail() == true) {
			// std::cerr << "Error: Failed getline." << std::endl;
			throw std::runtime_error("Error: Failed getline.");
			break ;
		}
		std::string				replaced_line;
		std::string::size_type	prev_position(0);
		std::string::size_type	current_position(0);

		while ((current_position = line.find(s1, prev_position)) != std::string::npos) {
			replaced_line += line.substr(prev_position, current_position - prev_position);
			replaced_line += s2;
			prev_position = current_position + s1.length();
		}
		replaced_line += line.substr(prev_position);
		outputFd << replaced_line << std::endl;
	}
}

int	main(int argc, char *argv[])
{
	if (!isValidation(argc, argv)) {
		return (1);
	}
	std::ifstream	sourceFileFd(argv[1]);
	if (sourceFileFd.is_open() == false) {
		std::cerr << "Error: Failed open(sourceFileFd)." << std::endl;
		return (1);
	}
	const std::string	replaceFileName(getReplaceFileName(argv[1]));
	std::ofstream		replaceFileFd(replaceFileName);
	if (replaceFileFd.is_open() == false) {
		std::cerr << "Error: Failed open(replaceFileFd)." << std::endl;
		sourceFileFd.close();
		return (1);
	}
	try {
		do_replace(sourceFileFd, replaceFileFd, &(argv[2]));
	}
	catch (const std::runtime_error &e) {
		std::cout << e.what() << std::endl;
	}
	sourceFileFd.close();
	replaceFileFd.close();
}
