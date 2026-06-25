#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include <deque>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(char **args);
		PmergeMe(const PmergeMe&);
		PmergeMe &operator=(const PmergeMe&);
		~PmergeMe();

		std::vector<int> sortVec(void);
		std::deque<int> sortDeque(void);

		size_t getComparisons(void) const;
		const std::vector<int> &getUnsorted(void) const;
		const std::vector<int> &getSortedVec(void) const;
		const std::deque<int> &getSortedDeque(void) const;

	private:
		std::vector<int> _unsortedContainer;
		std::vector<int> _vecContainer;
		std::deque<int> _dequeContainer;
		size_t _comparisons;

		typedef std::pair<int, int> Pair;
		typedef std::vector<int> Vector;
		typedef std::vector<Pair> VecPair;
		typedef std::deque<int> Deque;
		typedef std::deque<Pair> DequePair;
		
		// Vector
		void mergeInsertionSortVec(Vector &vecIndexes);
		void pairVec(const Vector &indexes, Vector &winners, Vector &partners, int &straggler, bool &isOdd);
		void insertVecChain(const Vector &winners, const Vector &partner, Vector &mainChain, bool isOdd, int straggler);
		
		void insertPendingVec(Vector &mainChain, VecPair &pending);
		int insertElementVec(Vector &mainChain, int upperBound, int value);
		int fordLowerBoundVec(const Vector &mainChain, int upperBound, int value);

		Vector initializeVecIndexes(void) const;
		Vector assignVecIndexValues(const Vector &sortedVecIndexes) const;

		// Deque
		void mergeInsertionSortDeque(Deque &dequeIndexes);
		void pairDeque(const Deque &indexes, Deque &winners, Deque &partners, int &straggler, bool &isOdd);
		void insertDequeChain(const Deque &winners, const Deque &partner, Deque &mainChain, bool isOdd, int straggler);
		
		void insertPendingDeque(Deque &mainChain, DequePair &pending);
		int insertElementDeque(Deque &mainChain, int upperBound, int value);
		int fordLowerBoundDeque(const Deque &mainChain, int upperBound, int value);

		Deque initializeDequeIndexes(void) const;
		Deque assignDequeIndexValues(const Deque &sortedDequeIndexes) const;

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


//	|| ----- LIST IMPLEMENTATION ----- ||

// std::list<int> sortList(void);
// const std::list<int> &getSortedList(void) const;

// std::list<int> _listContainer;
// typedef std::list<int> List;


//	List
// void mergeInsertionSortList(List &listIndexes);
// void pairList(const List &indexes, List &winners, Vector &partners, int &straggler, bool &isOdd);
// void insertListChain(const List &winners, const Vector &partner, List &mainChain, bool isOdd, int straggler);

// void insertPendingList(List &mainChain, VecPair &pending);
// int insertElementList(List &mainChain, int upperBound, int value);
// int fordLowerBoundList(List &mainChain, int upperBound, int value, List::iterator &it_offset);

// List initializeListIndexes(void) const;
// List assignListIndexValues(const List &sortedListIndexes) const;
