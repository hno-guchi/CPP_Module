#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <string>

void				fatalError(const std::string& prefix, const std::string& message);
void				printInt(const std::string& str, const std::vector<int>& vec);
std::vector<int>	mergeInsertionSort(std::vector<int> vec);

# endif  // PMERGEME_HPP
