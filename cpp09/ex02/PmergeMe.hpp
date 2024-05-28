#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <list>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

template <typename INTCONT, typename PAIRCONT>
class PmergeMe {
 private:
	 INTCONT	before_;
	 INTCONT	after_;
	 size_t		compareCount_;
	 double		msTime_;

	 // CONSTRUCTOR func
	 int								convertStringToInt(const std::string& str);
	 bool								isDuplicate(int num);
	 void								createContainer(int argc, char** argv);
	 // PmergeMe<INTCONT>::mergeInsertionSort() func
	 PAIRCONT							createPairs(INTCONT container);
	 INTCONT							getLarges(const PAIRCONT& pairs);
	 INTCONT							getSmalls(const PAIRCONT& pairs, const INTCONT& sorted);
	 typename INTCONT::const_iterator	getBackIterator(typename INTCONT::const_iterator end);
	 typename INTCONT::const_iterator	getMiddleIterator(typename INTCONT::const_iterator left, typename INTCONT::const_iterator right);
	 size_t								getDistance(typename INTCONT::const_iterator begin, typename INTCONT::const_iterator end);
	 size_t								getJacobsthalNumber(size_t* n);
	 typename INTCONT::const_iterator	selectInsertionRange(size_t* n, const INTCONT& smalls, typename INTCONT::const_iterator begin);
	 typename INTCONT::const_iterator	getRightIterator(const PAIRCONT& pairs, const INTCONT& sorted, int target);
	 typename INTCONT::const_iterator	getSortPosition(const PAIRCONT& pairs, const INTCONT& sorted, int target);
	 INTCONT	mergeInsertionSort(INTCONT container);
	 // DEBUG func
	 void	printContainer(const std::string& subject, const INTCONT& container) const;
	 void	printRange(const std::string& subject, typename INTCONT::const_iterator begin, typename INTCONT::const_iterator end) const;
	 void	printPairs(const std::string& str, const PAIRCONT& pairs) const;

 public:
	 // CONSTRUCTOR & DESTRUCTOR
	 explicit PmergeMe(int argc = 0, char **argv = NULL);
	 ~PmergeMe();
	 // GETTER & SETTER
	 const INTCONT&	getBefore() const;
	 const INTCONT&	getAfter() const;
	 size_t				getCompareCount() const;
	 double				getMsTime() const;
	 void				resetCompareCount();

	 void				sort();
	 // DEBUG
	 void				printResult() const;
	 void				printMsTime(const std::string& type) const;
};

void	fatalError(const std::string& subject, const std::string& message);

// #include "PmergeMe.tpp"

# endif  // PMERGEME_HPP
