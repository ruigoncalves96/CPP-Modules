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

size_t PmergeMe::getComparisons(void) const {return _comparisons;}

bool PmergeMe::valueLess(int idxA, int idxB)
{
	_comparisons++;
	return (_unsortedContainer[idxA] < _unsortedContainer[idxB]);
}

//*	|| ------ std::vector ------ ||
// Main sortVec
PmergeMe::Vector PmergeMe::sortVec(void)
{
	_comparisons = 0;

	Vector vecIndexes = initializeIndexes();
	mergeInsertionSort(vecIndexes);

	_vecContainer = assignVecIndexValues(vecIndexes);
	return (_vecContainer);
}

// Recursive core — merge-insert (Ford-Johnson)
void PmergeMe::mergeInsertionSort(Vector &vecIndexes)
{
	if (vecIndexes.size() <= 1)
		return ;

	int  straggler = -1;
	bool isOdd= false;

	// Merge section
	Vector winners;
	Vector winnerPartner(_unsortedContainer.size(), -1);
	pairVec(vecIndexes, winners, winnerPartner, straggler, isOdd);
	// ----

	mergeInsertionSort(winners);

	// Insertion section
	Vector mainChain;
	insertChain(winners, winnerPartner, mainChain);
	if (isOdd)
		insertElement(mainChain, static_cast<int>(mainChain.size()), straggler);
	// ----

	vecIndexes = mainChain;
}

// Phase 1: Pairing
void PmergeMe::pairVec(const Vector &indexes, Vector &winners, Vector &partners, int &straggler, bool &isOdd)
{
	size_t indexesSize = indexes.size();
	isOdd = indexesSize % 2 != 0;
	size_t pairCount = isOdd ? indexesSize - 1 : indexesSize;

	for (size_t i = 0; i < pairCount; i += 2)
	{
		int a = indexes[i];
		int b = indexes[i + 1];
		if (valueLess(a, b))
			std::swap(a, b);
		winners.push_back(a);
		partners[a] = b;
	}
	if (isOdd)
		straggler = indexes[indexesSize - 1];
}

// Phase 2: Chain construction
void PmergeMe::insertChain(const Vector &winners, const Vector &partner, Vector &mainChain)
{
	VecPair pending;

	mainChain.push_back(partner[winners[0]]);
	mainChain.push_back(winners[0]);

	for (size_t i = 1; i < winners.size(); ++i)
	{
		mainChain.push_back(winners[i]);
		int bound = static_cast<int>(mainChain.size()) - 1;
		pending.push_back(std::make_pair(partner[winners[i]], bound));
	}
	insertPending(mainChain, pending);
}

// Phase 3: Jacobsthal insertion order
void PmergeMe::insertPending(Vector &mainChain, VecPair &pending)
{
	Vector order = generateInsertionSequence(static_cast<int>(pending.size()));

	for (size_t i = 0; i < order.size(); ++i)
	{
		int idx = order[i];
		int offset = insertElement(mainChain, pending[idx].second, pending[idx].first);

		for (size_t j = 0; j < pending.size(); ++j)
			if (pending[j].second >= offset)
				pending[j].second++;
	}
}

int PmergeMe::insertElement(Vector &mainChain, int upperBound, int value)
{
	int offset = fordLowerBound(mainChain, upperBound, value);
	mainChain.insert(mainChain.begin() + offset, value);
	return (offset);
}

// Bounded binary search 
int PmergeMe::fordLowerBound(const Vector &mainChain, int upperBound, int toFit)
{
	int lowerBound = 0;
	while (lowerBound < upperBound)
	{
		int mid = lowerBound + (upperBound - lowerBound) / 2;
		if (valueLess(mainChain[mid], toFit))
			lowerBound = mid + 1;
		else
			upperBound = mid;
	}
	return (lowerBound);
}

PmergeMe::Vector PmergeMe::initializeIndexes(void) const
{
	Vector indexes(_unsortedContainer.size());
	for (size_t i = 0; i < indexes.size(); ++i)
		indexes[i] = static_cast<int>(i);
	return (indexes);
}

PmergeMe::Vector PmergeMe::assignVecIndexValues(const Vector &sortedVecIndexes) const
{
	Vector sortedVec(sortedVecIndexes.size());
	for (size_t i = 0; i < sortedVecIndexes.size(); ++i)
		sortedVec[i] = _unsortedContainer[sortedVecIndexes[i]];
	return (sortedVec);
}

//*	|| ------ insertion sequence ------ ||
PmergeMe::Vector PmergeMe::generateInsertionSequence(int pendingSize)
{
	Vector sequence;
	if (pendingSize == 0)
		return (sequence);

	Vector jacob = generateJacobsthal(pendingSize);

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

//*	|| ------ Jacobsthal ------ ||
std::vector<int> PmergeMe::generateJacobsthal(int limit)
{
	std::vector<int> sequence;
	sequence.push_back(1);
	sequence.push_back(3);
	while (sequence.back() < limit + 1)
		sequence.push_back(sequence[sequence.size() - 1] + 2 * sequence[sequence.size() - 2]);
	return (sequence);
}



//*	|| ------ std::list------ ||
// // ==========================================
// // Phase 1 (list): Pairing — pure sequential traversal, no indexes needed
// // ==========================================
// void PmergeMe::splitPairsList(const std::list<int> &ids, VecPair &pairs,
// 							   std::list<int> &winners, int &straggler, bool &hasStraggler)
// {
// 	size_t n = ids.size();
// 	hasStraggler = (n % 2 != 0);

// 	std::list<int>::const_iterator it = ids.begin();
// 	size_t processed = 0;
// 	size_t pairCount = hasStraggler ? n - 1 : n;

// 	while (processed < pairCount)
// 	{
// 		int a = *it; ++it;
// 		int b = *it; ++it;
// 		if (valueLess(a, b))
// 			std::swap(a, b);
// 		pairs.push_back(std::make_pair(a, b)); // (winner, loser)
// 		winners.push_back(a);
// 		processed += 2;
// 	}
// 	if (hasStraggler)
// 		straggler = *it;
// }

// // ==========================================
// // Phase 2 (list): Chain construction
// // ==========================================
// void PmergeMe::buildInitialChainList(const std::list<int> &sortedWinners,
// 									 const std::vector<int> &partner,
// 									 std::list<int> &mainChain,
// 									 std::vector<std::pair<int, ListIt> > &pending)
// {
// 	std::list<int>::const_iterator it = sortedWinners.begin();

// 	mainChain.push_back(partner[*it]); // b1, no bound needed
// 	mainChain.push_back(*it);          // a1
// 	++it;

// 	for (; it != sortedWinners.end(); ++it)
// 	{
// 		mainChain.push_back(*it);
// 		ListIt bound = mainChain.end();
// 		--bound; // iterator pointing exactly at the a_i we just pushed
// 		pending.push_back(std::make_pair(partner[*it], bound));
// 	}
// }

// // ==========================================
// // Bounded binary search over a list — same comparison count as the
// // vector version, but reaching each midpoint costs O(distance) instead
// // of O(1), since list iterators aren't random access.
// // ==========================================
// PmergeMe::ListIt PmergeMe::fordLowerBoundList(std::list<int> &mainChain, int rangeSize, int targetId)
// {
// 	int lo = 0, hi = rangeSize;
// 	ListIt loIt = mainChain.begin(); // tracks the iterator at position 'lo'

// 	while (lo < hi)
// 	{
// 		int mid = lo + (hi - lo) / 2;
// 		ListIt midIt = loIt;
// 		std::advance(midIt, mid - lo);

// 		if (valueLess(*midIt, targetId))
// 		{
// 			loIt = midIt;
// 			++loIt;
// 			lo = mid + 1;
// 		}
// 		else
// 			hi = mid;
// 	}
// 	return loIt;
// }

// PmergeMe::ListIt PmergeMe::insertElementBoundedList(std::list<int> &mainChain, int value, int rangeSize)
// {
// 	ListIt pos = fordLowerBoundList(mainChain, rangeSize, value);
// 	return mainChain.insert(pos, value);
// }

// // ==========================================
// // Phase 3 (list): insert pending elements in Jacobsthal order.
// // No bound-shifting loop needed here — list iterators stay valid
// // through insertions elsewhere in the list.
// // ==========================================
// void PmergeMe::insertPendingList(std::list<int> &mainChain,
// 								 std::vector<std::pair<int, ListIt> > &pending)
// {
// 	std::vector<int> order = generateInsertionSequence(static_cast<int>(pending.size()));

// 	for (size_t i = 0; i < order.size(); ++i)
// 	{
// 		int idx = order[i];
// 		ListIt boundIt = pending[idx].second;
// 		int rangeSize = static_cast<int>(std::distance(mainChain.begin(), boundIt));

// 		insertElementBoundedList(mainChain, pending[idx].first, rangeSize);
// 		// no other pending[k].second needs updating — that's the whole win
// 	}
// }

// // ==========================================
// // Recursive core (list)
// // ==========================================
// std::list<int> PmergeMe::mergeInsertionSortList(std::list<int> ids)
// {
// 	if (ids.size() <= 1)
// 		return ids;

// 	VecPair pairs;
// 	std::list<int> winners;
// 	int  straggler = 0;
// 	bool hasStraggler = false;
// 	splitPairsList(ids, pairs, winners, straggler, hasStraggler);

// 	std::vector<int> partner(_unsortedContainer.size(), -1);
// 	for (size_t i = 0; i < pairs.size(); ++i)
// 		partner[pairs[i].first] = pairs[i].second;

// 	std::list<int> sortedWinners = mergeInsertionSortList(winners); // recursion

// 	std::list<int> mainChain;
// 	std::vector<std::pair<int, ListIt> > pending;
// 	buildInitialChainList(sortedWinners, partner, mainChain, pending);
// 	insertPendingList(mainChain, pending);

// 	if (hasStraggler)
// 		insertElementBoundedList(mainChain, straggler, static_cast<int>(mainChain.size()));

// 	return mainChain;
// }

// // ==========================================
// // Entry point (list)
// // ==========================================
// void PmergeMe::sortList(void)
// {
// 	_comparisons = 0;

// 	std::list<int> ids;
// 	for (size_t i = 0; i < _unsortedContainer.size(); ++i)
// 		ids.push_back(static_cast<int>(i));

// 	std::list<int> sortedIds = mergeInsertionSortList(ids);

// 	std::list<int> result;
// 	for (std::list<int>::iterator it = sortedIds.begin(); it != sortedIds.end(); ++it)
// 		result.push_back(_unsortedContainer[*it]);

// 	_listContainer = result;
// }
