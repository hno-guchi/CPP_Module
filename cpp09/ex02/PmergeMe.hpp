#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <list>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

class PmergeMe {
 private:
	 std::vector<int>	vecBefore_;
	 std::vector<int>	vecAfter_;
	 std::list<int>		lstBefore_;
	 std::list<int>		lstAfter_;
	 size_t				vecCompareCount_;
	 size_t				lstCompareCount_;
	 double				vecMsTime_;
	 double				lstMsTime_;

	 // CONSTRUCTOR func
	 int								convertStringToInt(const std::string& str);
	 bool								isDuplicate(int num);
	 void								createContainer(int argc, char** argv);
	 // PmergeMe::mergeInsertionSort() func
	 std::vector<std::pair<int, int> >	createPairs(std::vector<int> container);
	 std::list<std::pair<int, int> >	createPairs(std::list<int> container);
	 std::vector<int>					getLarges(const std::vector<std::pair<int, int> >& pairs);
	 std::list<int>						getLarges(const std::list<std::pair<int, int> >& pairs);
	 std::vector<int>					getSmalls(const std::vector<std::pair<int, int> >& pairs, const std::vector<int>& sorted);
	 std::list<int>						getSmalls(const std::list<std::pair<int, int> >& pairs, const std::list<int>& sorted);
	 std::vector<int>::const_iterator	getMiddleIterator(std::vector<int>::const_iterator left, std::vector<int>::const_iterator right);
	 std::list<int>::const_iterator		getMiddleIterator(std::list<int>::const_iterator left, std::list<int>::const_iterator right);
	 size_t								getJacobsthalNumber(size_t n);
	 std::vector<int>::const_iterator	selectInsertionRange(size_t n, const std::vector<int>& smalls, std::vector<int>::const_iterator begin);
	 std::list<int>::const_iterator		selectInsertionRange(size_t n, const std::list<int>& smalls, std::list<int>::const_iterator begin);
	 std::vector<int>::const_iterator	getRightIterator(const std::vector<std::pair<int, int> >& pairs, const std::vector<int>& sorted, int target);
	 std::list<int>::const_iterator		getRightIterator(const std::list<std::pair<int, int> >& pairs, const std::list<int>& sorted, int target);
	 std::vector<int>::const_iterator	getSortPosition(const std::vector<std::pair<int, int> >& pairs, const std::vector<int>& sorted, int target);
	 std::list<int>::const_iterator		getSortPosition(const std::list<std::pair<int, int> >& pairs, const std::list<int>& sorted, int target);
	 std::vector<int>					mergeInsertionSort(std::vector<int> container);
	 std::list<int>						mergeInsertionSort(std::list<int> container);
	 // DEBUG func
	 void	printContainer(const std::string& subject, const std::vector<int>& container) const;
	 void	printContainer(const std::string& subject, const std::list<int>& container) const;
	 void	printRange(const std::string& subject, std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) const;
	 void	printRange(const std::string& subject, std::list<int>::const_iterator begin, std::list<int>::const_iterator end) const;
	 void	printPairs(const std::string& str, const std::vector<std::pair<int, int> >& pairs) const;
	 void	printPairs(const std::string& str, const std::list<std::pair<int, int> >& pairs) const;
	 // CONSTRUCTOR & DESTRUCTOR
	 explicit PmergeMe(const PmergeMe& rhs);
	 PmergeMe& operator=(const PmergeMe& rhs);

 public:
	 // CONSTRUCTOR & DESTRUCTOR
	 explicit PmergeMe(int argc = 0, char **argv = NULL);
	 ~PmergeMe();
	 // GETTER & SETTER
	 const std::vector<int>&	getVecBefore() const;
	 const std::list<int>&		getLstBefore() const;
	 const std::vector<int>&	getVecAfter() const;
	 const std::list<int>&		getLstAfter() const;
	 size_t						getVecCompareCount() const;
	 size_t						getLstCompareCount() const;
	 double						getVecMsTime() const;
	 double						getLstMsTime() const;
	 void						resetCompareCount();

	 void						sort();
	 // DEBUG
	 void						printResult() const;
	 void						printMsTime() const;
};

# endif  // PMERGEME_HPP
