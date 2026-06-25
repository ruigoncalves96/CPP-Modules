#include "PmergeMe.hpp"
#include <string>
#include <iterator>
#include <algorithm>
#include <utility>

PmergeMe::PmergeMe() : _comparisons(0) {}

PmergeMe::PmergeMe(char **args) { _unsortedContainer = parseInput(args); }

PmergeMe::PmergeMe(const PmergeMe &obj) { *this = obj; }

PmergeMe& PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
	{
		_vecContainer = obj._vecContainer;
		_listContainer = obj._listContainer;
		_unsortedContainer = obj._unsortedContainer;
		_comparisons = obj._comparisons;
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
	if (_unsortedContainer.size() == 1)
	{
		_vecContainer.push_back(_unsortedContainer.front());
		return (_vecContainer);
	}

	Vector vecIndexes = initializeVecIndexes();
	mergeInsertionSortVec(vecIndexes);

	_vecContainer = assignVecIndexValues(vecIndexes);
	return (_vecContainer);
}

// Recursive core — merge-insert (Ford-Johnson)
void PmergeMe::mergeInsertionSortVec(Vector &vecIndexes)
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

	mergeInsertionSortVec(winners);

	// Insertion section
	Vector mainChain;
	insertVecChain(winners, winnerPartner, mainChain);
	if (isOdd)
		insertElementVec(mainChain, static_cast<int>(mainChain.size()), straggler);
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
void PmergeMe::insertVecChain(const Vector &winners, const Vector &partner, Vector &mainChain)
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
	insertPendingVec(mainChain, pending);
}

// Phase 3: Jacobsthal insertion order
void PmergeMe::insertPendingVec(Vector &mainChain, VecPair &pending)
{
	Vector order = generateInsertionSequence(static_cast<int>(pending.size()));

	for (size_t i = 0; i < order.size(); ++i)
	{
		int idx = order[i];
		int offset = insertElementVec(mainChain, pending[idx].second, pending[idx].first);

		for (size_t j = 0; j < pending.size(); ++j)
			if (pending[j].second >= offset)
				pending[j].second++;
	}
}

int PmergeMe::insertElementVec(Vector &mainChain, int upperBound, int value)
{
	int offset = fordLowerBoundVec(mainChain, upperBound, value);
	mainChain.insert(mainChain.begin() + offset, value);
	return (offset);
}

// Bounded binary search 
int PmergeMe::fordLowerBoundVec(const Vector &mainChain, int upperBound, int toFit)
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

PmergeMe::Vector PmergeMe::initializeVecIndexes(void) const
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



//*	|| ------ std::list------ ||
// Main listVec
PmergeMe::List PmergeMe::sortList(void)
{
	_comparisons = 0;
	if (_unsortedContainer.size() == 1)
	{
		_listContainer.push_back(_unsortedContainer.front());
		return (_listContainer);
	}

	List listIndexes = initializeListIndexes();
	mergeInsertionSortList(listIndexes);

	_listContainer = assignListIndexValues(listIndexes);
	return (_listContainer);
}

// Recursive core — merge-insert (Ford-Johnson)
void PmergeMe::mergeInsertionSortList(List &listIndexes)
{
	if (listIndexes.size() <= 1)
		return ;

	int  straggler = -1;
	bool isOdd= false;

	// Merge section
	List winners;
	Vector winnerPartner(_unsortedContainer.size(), -1);
	pairList(listIndexes, winners, winnerPartner, straggler, isOdd);
	// ----

	mergeInsertionSortList(winners);

	// Insertion section
	List mainChain;
	insertListChain(winners, winnerPartner, mainChain);
	if (isOdd)
		insertElementList(mainChain, static_cast<int>(mainChain.size()), straggler);
	// ----

	listIndexes = mainChain;
}

// Phase 1: Pairing
void PmergeMe::pairList(const List &indexes, List &winners, Vector &partners, int &straggler, bool &isOdd)
{
	size_t indexesSize = indexes.size();
	isOdd = indexesSize % 2 != 0;
	List::const_iterator end = indexes.end();
	if (isOdd)
		--end;

	List::const_iterator current = indexes.begin();
	while (current != end)
	{
		List::const_iterator next = current; 
		++next;

		int a = *current;
		int b = *next;
		if (valueLess(a, b))
			std::swap(a, b);
		winners.push_back(a);
		partners[a] = b;
		std::advance(current, 2);
	}
	if (isOdd)
		straggler = indexes.back();
}

// Phase 2: Chain construction
void PmergeMe::insertListChain(const List &winners, const Vector &partner, List &mainChain)
{
	VecPair pending;

	mainChain.push_back(partner[winners.front()]);
	mainChain.push_back(winners.front());

	int bound = 1;
	List::const_iterator it = winners.begin();
	++it;
	while (it != winners.end())
	{
		mainChain.push_back(*it);
		++bound;
		pending.push_back(std::make_pair(partner[*it], bound));
		++it;
	}
	insertPendingList(mainChain, pending);
}

// Phase 3: Jacobsthal insertion order
void PmergeMe::insertPendingList(List &mainChain, VecPair &pending)
{
	Vector order = generateInsertionSequence(static_cast<int>(pending.size()));

	for (size_t i = 0; i < order.size(); ++i)
	{
		int idx = order[i];
		int offset = insertElementList(mainChain, pending[idx].second, pending[idx].first);

		for (size_t j = 0; j < pending.size(); ++j)
			if (pending[j].second >= offset)
				pending[j].second++;
	}
}

int PmergeMe::insertElementList(List &mainChain, int upperBound, int value)
{
	List::iterator it_offset = mainChain.begin();
	int offset = fordLowerBoundList(mainChain, upperBound, value, it_offset);
	mainChain.insert(it_offset, value);
	return (offset);
}

// Bounded binary search 
int PmergeMe::fordLowerBoundList(List &mainChain, int upperBound, int toFit, List::iterator &it_offset)
{
	int lowerBound = 0;
	int midCursor = 0;
	List::iterator it_midCursor = mainChain.begin();
	while (lowerBound < upperBound)
	{
		int mid = lowerBound + (upperBound - lowerBound) / 2;
		std::advance(it_midCursor, mid - midCursor);
		midCursor = mid;
		if (valueLess(*it_midCursor, toFit))
		{
			lowerBound = mid + 1;
			it_offset = it_midCursor;
			++it_offset;
		}
		else
			upperBound = mid;
	}
	return (lowerBound);
}

PmergeMe::List PmergeMe::initializeListIndexes(void) const
{
	List indexes;
	for (size_t i = 0; i != this->_unsortedContainer.size(); ++i)
		indexes.push_back(i);
	return (indexes);
}

PmergeMe::List PmergeMe::assignListIndexValues(const List &sortedListIndexes) const
{
	List sortedList;
	for (List::const_iterator it = sortedListIndexes.begin(); it != sortedListIndexes.end(); ++it)
		sortedList.push_back(_unsortedContainer[*it]);
	return (sortedList);
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

PmergeMe::Vector PmergeMe::parseInput(char **args)
{
	if (!args || !*args)
		throw std::runtime_error("no arguments.");
	PmergeMe::Vector container;
	for (size_t i = 0; args[i]; ++i)
	{
		std::string s_number = args[i];
		if (s_number.empty())
			throw std::runtime_error("empty argument.");
		if (s_number.find_first_not_of("0123456789") != std::string::npos)
			throw std::runtime_error("invalid argument format '" + varToString(s_number) + "'");

		int i_number = stringToNumber<int>(s_number);
		if (i_number == 0)
			throw std::runtime_error("'0' is an invalid number.");
		if (std::find(container.begin(), container.end(), i_number) != container.end())
			throw std::runtime_error("duplicate argument.");
		container.push_back(i_number);
	}
	return (container);
}