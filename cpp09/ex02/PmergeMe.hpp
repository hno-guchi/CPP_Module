#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <string>

extern int	CntPairCompare;
extern int	CntRecvCompare;
extern int	CntBinaryInsertCompare;

void	fatalError(const std::string& prefix, const std::string& message);
void	printInt(const std::string& str, const std::vector<int>& vec);
void	printPair(const std::string& str, const std::vector<std::pair<int, int> >& vec);
int		jacobsthalNumber(int n);

template <typename CONTAINER>
CONTAINER	mergeInsertionSort(CONTAINER container);

class PmergeMe {
 private:
	 static size_t		compareCount_;
	 double				msTime_;

	 template <typename CONTAINER>
	 CONTAINER	mergeInsertionSort(CONTAINER container);

	 // void				printAfter() const;
	 // void				printTime() const;
	 // void				printCompareCount() const;

 public:
	 PmergeMe();
	 ~PmergeMe();

	 template <typename CONTAINER>
	 CONTAINER	sort(CONTAINER container);
	 // DEBUG
	 // static void		resetCompareCount();
	 // void			printResult() const;
};

#include "./PmergeMe.tpp"

# endif  // PMERGEME_HPP
