#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <list>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(char **args);
		PmergeMe(const PmergeMe&);
		PmergeMe &operator=(const PmergeMe&);
		~PmergeMe();

		std::vector<int> sortVec(void);
		std::list<int> sortList(void);

		size_t getComparisons(void) const;
		const std::vector<int> &getUnsorted(void) const;
		const std::vector<int> &getSortedVec(void) const;
		const std::list<int> &getSortedList(void) const;

	private:
		std::vector<int> _unsortedContainer;
		std::vector<int> _vecContainer;
		std::list<int> _listContainer;
		size_t _comparisons;

		typedef std::vector<int> Vector;
		typedef std::list<int> List;
		typedef std::pair<int, int> Pair;
		typedef std::vector<Pair> VecPair;
		
		// Vector
		void mergeInsertionSortVec(Vector &vecIndexes);
		void pairVec(const Vector &indexes, Vector &winners, Vector &partners, int &straggler, bool &isOdd);
		void insertVecChain(const Vector &winners, const Vector &partner, Vector &mainChain);
		
		void insertPendingVec(Vector &mainChain, VecPair &pending);
		int insertElementVec(Vector &mainChain, int upperBound, int value);
		int fordLowerBoundVec(const Vector &mainChain, int upperBound, int value);

		Vector initializeVecIndexes(void) const;
		Vector assignVecIndexValues(const Vector &sortedVecIndexes) const;

		//	std::list<int>
		void mergeInsertionSortList(List &listIndexes);
		void pairList(const List &indexes, List &winners, Vector &partners, int &straggler, bool &isOdd);
		void insertListChain(const List &winners, const Vector &partner, List &mainChain);

		void insertPendingList(List &mainChain, VecPair &pending);
		int insertElementList(List &mainChain, int upperBound, int value);
		int fordLowerBoundList(List &mainChain, int upperBound, int value, List::iterator &it_offset);

		List initializeListIndexes(void) const;
		List assignListIndexValues(const List &sortedListIndexes) const;

		//	Insertion Sequence / Jacobsthal
		static Vector generateInsertionSequence(int pendingSize);
		static Vector generateJacobsthal(int limit);

		Vector parseInput(char **args);
		bool valueLess(int idxA, int idxB);
};

template <typename T>
T stringToNumber(const std::string &str)
{
	std::stringstream ss(str);	
	T out_number;

	ss >> out_number;
	if (ss.fail() || !ss.eof())
		throw std::runtime_error("Invalid Number convertion");
	
	return (out_number);
}

template <typename T>
std::string varToString(const T var)
{
	std::stringstream ss;	
	ss << var;
	if (ss.fail())
		throw std::runtime_error("Invalid Variable conversion");
	
	return (ss.str());
}

#endif
