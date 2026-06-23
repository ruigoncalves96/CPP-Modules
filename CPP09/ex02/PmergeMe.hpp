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
		std::list<int> sortList(void);

		size_t getComparisons(void) const;
		const std::vector<int> &getUnsorted(void) const;
		const std::vector<int> &getSortedVec(void) const;
		const std::list<int> &getSortedList(void) const;

	private:
		std::vector<int> _unsortedContainer;
	
		size_t _comparisons;
		std::vector<int> _vecContainer;
		std::list<int> _listContainer;

		typedef std::pair<int, int> Pair;
		typedef std::vector<Pair> VecPair;
		typedef std::list<Pair> ListPair;
		
		// std::vector<int>
		void splitPairs(const std::vector<int> &indices, VecPair &pairs, int &straggler, bool &hasStraggler);
		void buildInitialChain(const std::vector<int> &sortedWinners, const std::vector<int> &partner, std::vector<int> &mainChain, VecPair &pending);
		std::vector<int> generateInsertionSequence(int pendingSize) const;
		int countedLowerBound(const std::vector<int> &mainChain, int rangeEnd, int target);
		int insertElementBounded(std::vector<int> &mainChain, int value, int upperBound);
		void insertPending(std::vector<int> &mainChain, VecPair &pending);
		std::vector<int> mergeInsertionSort(std::vector<int> indices);

		// std::list<int>


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

/*
	size_t           getComparisons(void) const;

private:
	size_t           _comparisons;

	bool valueLess(int idxA, int idxB);

	void splitPairs(const std::vector<int> &indices,
					std::vector<int> &winners,
					std::vector<int> &partner,
					int &straggler, bool &hasStraggler);

	void buildInitialChain(const std::vector<int> &sortedWinners,
						   const std::vector<int> &partner,
						   std::vector<int> &mainChain,
						   std::vector<int> &pending,
						   std::vector<int> &boundPositions);

	std::vector<int> generateInsertionSequence(int pendingSize) const;

	int countedLowerBound(const std::vector<int> &mainChain, int rangeEnd, int target);
	int insertElementBounded(std::vector<int> &mainChain, int value, int upperBound);

	void insertPending(std::vector<int> &mainChain,
					   const std::vector<int> &pending,
					   std::vector<int> &boundPositions);

	std::vector<int> mergeInsertionSort(std::vector<int> indices);
};

#endif
*/