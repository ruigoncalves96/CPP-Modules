#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
		os << vec[i] << " ";
	return (os);
}

std::ostream &operator<<(std::ostream &os, const std::deque<int> &vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
		os << vec[i] << " ";
	return (os);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
		return (std::cerr << "Error: no arguments." << std::endl, 1);

	try {
		PmergeMe sorter(&argv[1]);

		std::clock_t startVec = std::clock();
		sorter.sortVec();
		std::clock_t endVec= std::clock();
		size_t vecComparisons = sorter.getComparisons();

		std::clock_t startDeque = std::clock();
		sorter.sortDeque();
		std::clock_t endDeque= std::clock();
		size_t dequeComparisons = sorter.getComparisons();

		double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;
		double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000.0;

		std::cout << std::fixed << std::setprecision(5);
		std::cout << "Before: " << sorter.getUnsorted() << "\n";
		std::cout << "After: " << sorter.getSortedVec() << "\n";
		std::cout << "Time to process a range of " << sorter.getSortedVec().size() << " elements with std::vector<int> : " << timeVec << " us" << std::endl;
		std::cout << "Time to process a range of " << sorter.getSortedDeque().size() << " elements with std::deque<int> : " << timeDeque << " us" << std::endl;
		std::cout << "Vector Comparisons = " << vecComparisons << "\n";
		std::cout << "Deque Comparisons = " << dequeComparisons << "\n";
	}
	catch (const std::exception &e) { std::cerr << "Error: " << e.what() << std::endl; return (1);}

	return (0);
}

