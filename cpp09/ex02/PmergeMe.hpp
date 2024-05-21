#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <utility>
#include <vector>
#include <string>

template <typename CONTAINER>
class PmergeMe {
 private:
	 CONTAINER	before_;
	 CONTAINER	after_;
	 size_t		compareCount_;
	 double		msTime_;

	 // CONSTRUCTOR func
	 int								convertStringToInt(const std::string& str);
	 bool								isDuplicate(int num);
	 void								createContainer(int argc, char** argv);
	 // PmergeMe<CONTAINER>::mergeInsertionSort() func
	 std::vector<std::pair<int, int> >	createPairs(CONTAINER container);
	 CONTAINER							getLarges(const std::vector<std::pair<int, int> >& pairs);
	 CONTAINER							getSmalls(const std::vector<std::pair<int, int> >& pairs, const CONTAINER& sorted);
	 typename CONTAINER::const_iterator	getBackIterator(typename CONTAINER::const_iterator end);
	 typename CONTAINER::const_iterator	getMiddleIterator(typename CONTAINER::const_iterator left, typename CONTAINER::const_iterator right);
	 size_t								getDistance(typename CONTAINER::const_iterator begin, typename CONTAINER::const_iterator end);
	 size_t								getJacobsthalNumber(size_t* n);
	 typename CONTAINER::const_iterator	selectInsertionRange(size_t* n, const CONTAINER& smalls, typename CONTAINER::const_iterator begin);
	 typename CONTAINER::const_iterator	getRightIterator(const std::vector<std::pair<int, int> >& pairs, const CONTAINER& sorted, int target);
	 typename CONTAINER::const_iterator	getSortPosition(const std::vector<std::pair<int, int> >& pairs, const CONTAINER& sorted, int target);
	 CONTAINER	mergeInsertionSort(CONTAINER container);
	 // DEBUG func
	 void	printContainer(const std::string& subject, const CONTAINER& container) const;
	 void	printRange(const std::string& subject, typename CONTAINER::const_iterator begin, typename CONTAINER::const_iterator end) const;
	 void	printPairs(const std::string& str, const std::vector<std::pair<int, int> >& pairs) const;

 public:
	 // CONSTRUCTOR & DESTRUCTOR
	 explicit PmergeMe(int argc = 0, char **argv = NULL);
	 ~PmergeMe();
	 // GETTER & SETTER
	 const CONTAINER&	getBefore() const;
	 const CONTAINER&	getAfter() const;
	 size_t				getCompareCount() const;
	 double				getMsTime() const;
	 void				resetCompareCount();

	 void				sort();
	 // DEBUG
	 void				printResult() const;
	 void				printMsTime(const std::string& type) const;
};

void	fatalError(const std::string& subject, const std::string& message);

# endif  // PMERGEME_HPP
