#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <exception>
#include <algorithm>
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
		// std::list<int> sortList(void);

		size_t getComparisons(void) const;
		const std::vector<int> &getUnsorted(void) const;
		const std::vector<int> &getSortedVec(void) const;
		const std::list<int> &getSortedList(void) const;

	private:
		std::vector<int> _unsortedContainer;
	
		size_t _comparisons;
		std::vector<int> _vecContainer;
		std::list<int> _listContainer;

		typedef std::vector<int> Vector;
		typedef std::pair<int, int> Pair;
		typedef std::vector<Pair> VecPair;
		typedef std::list<Pair> ListPair;
		
		// Vector
		void mergeInsertionSort(Vector &vecIndexes);
		void pairVec(const Vector &indexes, Vector &winners, Vector &partners, int &straggler, bool &isOdd);
		void insertChain(const Vector &winners, const Vector &partner, Vector &mainChain);
		
		void insertPending(Vector &mainChain, VecPair &pending);
		int insertElement(Vector &mainChain, int upperBound, int value);
		int fordLowerBound(const Vector &mainChain, int upperBound, int value);

		Vector initializeIndexes(void) const;
		Vector assignVecIndexValues(const Vector &sortedVecIndexes) const;

		//	std::list<int>

		//	Insertion Sequence / Jacobsthal
		static Vector generateInsertionSequence(int pendingSize);
		static Vector generateJacobsthal(int limit);

		bool valueLess(int idxA, int idxB);

		template <typename Container>
		Container parseInput(char **args);
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

template <typename Container>
Container PmergeMe::parseInput(char **args)
{
	Container container;
	for (size_t i = 0; args[i]; ++i)
	{
		std::string s_number = args[i];
		if (s_number.empty())
			throw std::runtime_error("empty argument.");
		if (s_number.find_first_not_of("0123456789") != std::string::npos)
			throw std::runtime_error("invalid argument format '" + varToString(s_number) + "'");

		int i_number = stringToNumber<int>(s_number);
		if (std::find(container.begin(), container.end(), i_number) != container.end())
			throw std::runtime_error("duplicate argument.");
		container.push_back(i_number);
	}
	return (container);
}

#endif
