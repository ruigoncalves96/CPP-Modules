#include "PmergeMe.hpp"
#include <string>
#include <utility>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **args)
{
	_vecContainer = parseInput< std::vector<int> >(args);
	_listContainer = parseInput< std::list<int> >(args);

	_unsortedContainer = _vecContainer;
}

PmergeMe::PmergeMe(const PmergeMe &obj) { *this = obj; }

PmergeMe& PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
	{
		_vecContainer = obj._vecContainer;
		_listContainer = obj._listContainer;
		_unsortedContainer = obj._unsortedContainer;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

const std::vector<int>& PmergeMe::getUnsorted(void) const {return (_unsortedContainer);}

const std::vector<int>& PmergeMe::getSortedVec(void) const {return (_vecContainer);}

const std::list<int>& PmergeMe::getSortedList(void) const {return (_listContainer);}


//* || ----- Main sort ----- ||

std::vector<int> PmergeMe::sortVec(void)
{
	VecPair pairedVec = pairVecPairs();
	mergeInsertVecPair(pairedVec);
	assembleVecPair(pairedVec);

	return (this->_vecContainer);
}

std::list<int> PmergeMe::sortList(void)
{
	return (_listContainer);
}

//* || ----- Vector {std::vector<int>} functions ----- ||

void PmergeMe::mergeInsertVecPair(VecPair &mainContainer)
{
	if (mainContainer.size() < 2)
		return ;

	VecPair mainChain;
	VecPair pendChain;
	push_to_chains(mainContainer, mainChain, pendChain);

	mergeInsertVecPair(mainChain);

	insertVecPairPedants(mainChain, pendChain);
	mainContainer = mainChain;
}

void PmergeMe::insertVecPairPedants(VecPair &mainChain, VecPair &pendChain)
{
	if (pendChain.empty())
		return ;

	std::vector<int> jacobsthal = jacobsthalSeq(pendChain.size());
	std::vector<int>::iterator jacobsthal_needle = jacobsthal.begin() + 1;
	int pendSize = static_cast<int>(pendChain.size());

	for (; jacobsthal_needle != jacobsthal.end(); ++jacobsthal_needle)
	{
		int pendIndex = *jacobsthal_needle - 1 > pendSize - 1 ? pendSize - 1 : *jacobsthal_needle - 1;
		int stopIndex = *(jacobsthal_needle - 1) == 1 ? 0 : *(jacobsthal_needle - 1);
		for (; pendIndex >= stopIndex; --pendIndex)
		{
			Pair pendToInsert = pendChain[pendIndex];
			VecPair::iterator insertion_it = std::upper_bound(mainChain.begin(), mainChain.end(), pendToInsert);
			mainChain.insert(insertion_it, pendToInsert);
		}
	}
}

void PmergeMe::push_to_chains(const VecPair &mainContainer, VecPair &mainChain, VecPair &pendChain)
{
	bool isOdd = mainContainer.size() % 2;
	size_t containerLimit = isOdd ? mainContainer.size() - 1 : mainContainer.size();

	for (size_t i = 0; i < containerLimit; i += 2)
	{
		if (mainContainer[i].first > mainContainer[i + 1].first)
		{
			mainChain.push_back(mainContainer[i]);
			pendChain.push_back(mainContainer[i + 1]);
		}
		else
		{
			mainChain.push_back(mainContainer[i + 1]);
			pendChain.push_back(mainContainer[i]);
		}
	}
	if (isOdd)
		pendChain.push_back(mainContainer.back());
}

void PmergeMe::assembleVecPair(VecPair &pairedVec)
{
	std::vector<int> mainChain;
	std::vector<int> pendChain;
	for (size_t i = 0; i < pairedVec.size(); ++i)
	{
		mainChain.push_back(pairedVec[i].first);
		pendChain.push_back(pairedVec[i].second);
	}
	if (this->_isOdd)
		pendChain.push_back(this->_straggler);

	mainChain.insert(mainChain.begin(), pendChain.front());

	std::vector<int> jacobsthal = jacobsthalSeq(pendChain.size());
	std::vector<int>::iterator jacobsthal_needle = jacobsthal.begin() + 1;
	int pendSize = static_cast<int>(pendChain.size());

	for (; jacobsthal_needle != jacobsthal.end(); ++jacobsthal_needle)
	{
		int jacobsthal_index = *jacobsthal_needle > pendSize ? pendSize - 1 : *jacobsthal_needle - 1;
		for (; jacobsthal_index >= *(jacobsthal_needle - 1); --jacobsthal_index)
		{
			int pendToInsert = pendChain[jacobsthal_index];
			std::vector<int>::iterator insertion_it = std::upper_bound(mainChain.begin(), mainChain.end(), pendToInsert);
			mainChain.insert(insertion_it, pendToInsert);
		}
	}
	this->_vecContainer = mainChain;
}

std::vector<PmergeMe::Pair> PmergeMe::pairVecPairs(void)
{
	_isOdd = this->_vecContainer.size() % 2;
	if (_isOdd)
	{
		_straggler = this->_vecContainer.back();
		this->_vecContainer.pop_back();
	}

	VecPair mainContainer;
	for (size_t i = 0; i < this->_vecContainer.size(); i += 2)
	{
		Pair temp;
		if (this->_vecContainer[i] > this->_vecContainer[i + 1])
		{
			temp.first = this->_vecContainer[i];
			temp.second = this->_vecContainer[i + 1];
		}
		else
		{
			temp.first = this->_vecContainer[i + 1];
			temp.second = this->_vecContainer[i];
		}
		mainContainer.push_back(temp);
	}
	return (mainContainer);
}

//* || ----- List {std::list<int>} functions ----- ||


//* || ----- Utilities ----- ||

std::vector<int> PmergeMe::jacobsthalSeq(int size)
{
	std::vector<int> sequence;
	sequence.push_back(1);
	sequence.push_back(3);
	for (size_t i = 2; sequence[i - 1] <= size; ++i)
	{
		int jacobsthal_calc = sequence[i - 1] + (sequence[i - 2] * 2);
		sequence.push_back(jacobsthal_calc);
	}
	return (sequence);
}




//!	NOTES:
/*
	TODO:	* check if isOdd and straggler need to reset after finishing one sort or even get into the function;
*/