#include "PmergeMe.hpp"
#include <string>
#include <iterator>
#include <utility>

PmergeMe::PmergeMe() : _comparisons(0) {}

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

size_t PmergeMe::getComparisons(void) const
{
	return _comparisons;
}

bool PmergeMe::valueLess(int idxA, int idxB)
{
	_comparisons++;
	return _unsortedContainer[idxA] < _unsortedContainer[idxB];
}

// ==========================================
// Phase 1: Pairing
// ==========================================
void PmergeMe::splitPairs(const std::vector<int> &indices, VecPair &pairs, int &straggler, bool &hasStraggler)
{
	size_t n = indices.size();
	hasStraggler = (n % 2 != 0);
	size_t pairCount = hasStraggler ? n - 1 : n;

	for (size_t i = 0; i < pairCount; i += 2)
	{
		int a = indices[i];
		int b = indices[i + 1];
		if (valueLess(a, b))
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b)); // (winner, loser)
	}
	if (hasStraggler)
		straggler = indices[n - 1];
}

// ==========================================
// Phase 2: Chain construction
// ==========================================
void PmergeMe::buildInitialChain(const std::vector<int> &sortedWinners, const std::vector<int> &partner, std::vector<int> &mainChain, VecPair &pending)
{
	mainChain.push_back(partner[sortedWinners[0]]);
	mainChain.push_back(sortedWinners[0]);

	for (size_t i = 1; i < sortedWinners.size(); ++i)
	{
		mainChain.push_back(sortedWinners[i]);
		int bound = static_cast<int>(mainChain.size()) - 1;
		pending.push_back(std::make_pair(partner[sortedWinners[i]], bound));
	}
}

// ==========================================
// Phase 3: Jacobsthal insertion order
// ==========================================
std::vector<int> PmergeMe::generateInsertionSequence(int pendingSize) const
{
	std::vector<int> sequence;
	if (pendingSize == 0)
		return sequence;

	std::vector<int> jacob;
	jacob.push_back(1);
	jacob.push_back(3);
	while (jacob.back() < pendingSize + 1)
		jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);

	int lastJacob = 1;
	for (size_t i = 1; i < jacob.size(); ++i)
	{
		int start = std::min(jacob[i], pendingSize + 1);
		for (int j = start; j > lastJacob; --j)
			sequence.push_back(j - 2);
		lastJacob = jacob[i];
		if (lastJacob >= pendingSize + 1)
			break;
	}
	return (sequence);
}

// ==========================================
// Bounded binary search / insertion (shared by pending + straggler)
// ==========================================
int PmergeMe::countedLowerBound(const std::vector<int> &mainChain, int rangeEnd, int target)
{
	int lo = 0;
	int hi = rangeEnd;

	while (lo < hi)
	{
		int mid = lo + (hi - lo) / 2;
		if (valueLess(mainChain[mid], target))
			lo = mid + 1;
		else
			hi = mid;
	}
	return (lo);
}

int PmergeMe::insertElementBounded(std::vector<int> &mainChain, int value, int upperBound)
{
	int offset = countedLowerBound(mainChain, upperBound, value);
	mainChain.insert(mainChain.begin() + offset, value);
	return (offset);
}

void PmergeMe::insertPending(std::vector<int> &mainChain, VecPair &pending)
{
	std::vector<int> order = generateInsertionSequence(static_cast<int>(pending.size()));

	for (size_t i = 0; i < order.size(); ++i)
	{
		int idx = order[i];
		int offset = insertElementBounded(mainChain, pending[idx].first, pending[idx].second);

		for (size_t k = 0; k < pending.size(); ++k)
			if (pending[k].second >= offset)
				pending[k].second++;
	}
}

// ==========================================
// Recursive core — this IS Ford-Johnson, not a stand-in merge sort
// ==========================================
std::vector<int> PmergeMe::mergeInsertionSort(std::vector<int> indices)
{
	if (indices.size() <= 1)
		return indices;

	VecPair pairs;
	int  straggler = 0;
	bool hasStraggler = false;
	splitPairs(indices, pairs, straggler, hasStraggler);

	std::vector<int> winners;
	std::vector<int> partner(_unsortedContainer.size(), -1);
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		winners.push_back(pairs[i].first);
		partner[pairs[i].first] = pairs[i].second;
	}

	std::vector<int> sortedWinners = mergeInsertionSort(winners);

	std::vector<int> mainChain;
	VecPair pending;
	buildInitialChain(sortedWinners, partner, mainChain, pending);
	insertPending(mainChain, pending);

	if (hasStraggler)
		insertElementBounded(mainChain, straggler, static_cast<int>(mainChain.size()));

	return (mainChain);
}

// ==========================================
// Entry point
// ==========================================
std::vector<int> PmergeMe::sortVec(void)
{
	_comparisons = 0;

	std::vector<int> indices(_unsortedContainer.size());
	for (size_t i = 0; i < indices.size(); ++i)
		indices[i] = static_cast<int>(i);

	std::vector<int> sortedIndices = mergeInsertionSort(indices);

	std::vector<int> result(sortedIndices.size());
	for (size_t i = 0; i < sortedIndices.size(); ++i)
		result[i] = _unsortedContainer[sortedIndices[i]];

	_vecContainer = result;
	return (_vecContainer);
}

