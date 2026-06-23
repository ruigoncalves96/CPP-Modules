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

std::ostream &operator<<(std::ostream &os, const std::list<int> &list)
{
	for (std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it)
		os << *it << " ";
	return (os);
}

int main(int argc, char *argv[])
{
	(void)argv;
	if (argc < 3)
		return (std::cerr << "Error: need minimun 2 numbers." << std::endl, 1);

	try {
		PmergeMe sorter(&argv[1]);

		std::clock_t startVec = std::clock();
		sorter.sortVec();
		std::clock_t endVec= std::clock();

		// std::clock_t startList = std::clock();
		// std::list<int> listSorted = sorter.sortList();
		// std::clock_t endList= std::clock();

		double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;
		// double timeList = static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000000.0;

		std::cout << std::fixed << std::setprecision(5);
		std::cout << "Before: " << sorter.getUnsorted() << "\n";
		std::cout << "After: " << sorter.getSortedVec() << "\n";
		std::cout << "Time to process a range of " << sorter.getSortedVec().size() << " elements with std::vector<int> : " << timeVec << " us" << std::endl;
		// std::cout << "Time to process a range of " << sorter.getSortedList().size() << " elements with std::list<int> : " << timeList << " us" << std::endl;

//!		----- REMOVE IS SORTED -----
		std::cout << "\nVEC is sorted = " << std::is_sorted(sorter.getSortedVec().begin(), sorter.getSortedVec().end()) << "\n";
		// std::cout << "LIST is sorted = " << std::is_sorted(sorter.getSortedList().begin(), sorter.getSortedList().end()) << "\n";
	}
	catch (const std::exception &e) { std::cerr << "Error: " << e.what() << std::endl; return (1);}

	return (0);
}
