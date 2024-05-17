#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
// #include <deque>
#include <vector>
// #include <list>
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


// class PmergeMe {
//  private:
// 	 std::vector<int>	before_;
// 	 std::vector<int>	after_;
// 	 int				cntPairComp_;
// 	 int				cntRecvComp_;
// 	 int				cntBinaryInsertComp_;
// 	 time_t				time1_;
// 	 time_t				time2_;
// 
// 	 std::vector<int>			mergeInsertionSort(const std::vector<int>& vec);
// 	 void						printBefore() const;
// 	 void						printAfter() const;
// 	 void						printTime1() const;
// 	 void						printTime2() const;
// 	 void						printCntPair() const;
// 	 void						printCntRecv() const;
// 	 void						printCntBinaryInsert() const;
// 
//  public:
// 	 PmergeMe();
// 	 ~PmergeMe();
// 	 void						setBefore(int argc, char** argv);
// 	 void						setAfter();
// 	 const std::vector<int>&	getBefore() const;
// 	 const std::vector<int>&	getAfter() const;
// 
// 	 // DEBUG
// 	 void						print() const;
// 	 void						printCnt() const;
// }

# endif  // PMERGEME_HPP
