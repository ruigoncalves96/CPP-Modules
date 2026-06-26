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
		_unsortedContainer = obj._unsortedContainer;
		_vecContainer = obj._vecContainer;
		_dequeContainer = obj._dequeContainer;
		_comparisons = obj._comparisons;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

const std::vector<int>& PmergeMe::getUnsorted(void) const {return (_unsortedContainer);}

const std::vector<int>& PmergeMe::getSortedVec(void) const {return (_vecContainer);}

const std::deque<int>& PmergeMe::getSortedDeque(void) const {return (_dequeContainer);}

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
	insertVecChain(winners, winnerPartner, mainChain, isOdd, straggler);
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
void PmergeMe::insertVecChain(const Vector &winners, const Vector &partner, Vector &mainChain, bool isOdd, int straggler)
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
	if (isOdd)
		pending.push_back(std::make_pair(straggler, static_cast<int>(mainChain.size())));

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


//*	|| ------ std::deque ------ ||
// Main sortDeque
PmergeMe::Deque PmergeMe::sortDeque(void)
{
	_comparisons = 0;
	if (_unsortedContainer.size() == 1)
	{
		_dequeContainer.push_back(_unsortedContainer.front());
		return (_dequeContainer);
	}

	Deque DequeIndexes = initializeDequeIndexes();
	mergeInsertionSortDeque(DequeIndexes);

	_dequeContainer = assignDequeIndexValues(DequeIndexes);
	return (_dequeContainer);
}

// Recursive core — merge-insert (Ford-Johnson)
void PmergeMe::mergeInsertionSortDeque(Deque &DequeIndexes)
{
	if (DequeIndexes.size() <= 1)
		return ;

	int  straggler = -1;
	bool isOdd= false;

	// Merge section
	Deque winners;
	Deque winnerPartner(_unsortedContainer.size(), -1);
	pairDeque(DequeIndexes, winners, winnerPartner, straggler, isOdd);
	// ----

	mergeInsertionSortDeque(winners);

	// Insertion section
	Deque mainChain;
	insertDequeChain(winners, winnerPartner, mainChain, isOdd, straggler);
	// ----

	DequeIndexes = mainChain;
}

// Phase 1: Pairing
void PmergeMe::pairDeque(const Deque &indexes, Deque &winners, Deque &partners, int &straggler, bool &isOdd)
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
void PmergeMe::insertDequeChain(const Deque &winners, const Deque &partner, Deque &mainChain, bool isOdd, int straggler)
{
	DequePair pending;

	mainChain.push_back(partner[winners[0]]);
	mainChain.push_back(winners[0]);

	for (size_t i = 1; i < winners.size(); ++i)
	{
		mainChain.push_back(winners[i]);
		int bound = static_cast<int>(mainChain.size()) - 1;
		pending.push_back(std::make_pair(partner[winners[i]], bound));
	}
	if (isOdd)
		pending.push_back(std::make_pair(straggler, static_cast<int>(mainChain.size())));

	insertPendingDeque(mainChain, pending);
}

// Phase 3: Jacobsthal insertion order
void PmergeMe::insertPendingDeque(Deque &mainChain, DequePair &pending)
{
	Vector order = generateInsertionSequence(static_cast<int>(pending.size()));

	for (size_t i = 0; i < order.size(); ++i)
	{
		int idx = order[i];
		int offset = insertElementDeque(mainChain, pending[idx].second, pending[idx].first);

		for (size_t j = 0; j < pending.size(); ++j)
			if (pending[j].second >= offset)
				pending[j].second++;
	}
}

int PmergeMe::insertElementDeque(Deque &mainChain, int upperBound, int value)
{
	int offset = fordLowerBoundDeque(mainChain, upperBound, value);
	mainChain.insert(mainChain.begin() + offset, value);
	return (offset);
}

// Bounded binary search 
int PmergeMe::fordLowerBoundDeque(const Deque &mainChain, int upperBound, int toFit)
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

PmergeMe::Deque PmergeMe::initializeDequeIndexes(void) const
{
	Deque indexes(_unsortedContainer.size());
	for (size_t i = 0; i < indexes.size(); ++i)
		indexes[i] = static_cast<int>(i);
	return (indexes);
}

PmergeMe::Deque PmergeMe::assignDequeIndexValues(const Deque &sortedDequeIndexes) const
{
	Deque sortedDeque(sortedDequeIndexes.size());
	for (size_t i = 0; i < sortedDequeIndexes.size(); ++i)
		sortedDeque[i] = _unsortedContainer[sortedDequeIndexes[i]];
	return (sortedDeque);
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
		if (s_number.find_first_not_of("0123456789+-") != std::string::npos)
			throw std::runtime_error("invalid argument format '" + varToString(s_number) + "'");

		int i_number = stringToNumber<int>(s_number);
		if (i_number == 0)
			throw std::runtime_error("can't have '0' as argument.");
		else if (i_number < 0)
			throw std::runtime_error("negative number.");
		if (std::find(container.begin(), container.end(), i_number) != container.end())
			throw std::runtime_error("duplicate argument.");
		container.push_back(i_number);
	}
	return (container);
}

