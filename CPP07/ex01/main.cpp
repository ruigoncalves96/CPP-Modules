# include "iter.hpp"
# include <iostream>

int main(void)
{
	int i_array[5] = {1,2,3,4,5};

	std::cout << "Before iter:" << "\n";
	::iter(i_array, 5, print);
	std::cout << "\n";
	::iter(i_array, 5, add_one);
	std::cout << "After add_one iter:" << "\n";
	::iter(i_array, 5, print);
	std::cout << "\n\n";

	const int ci_array[5] = {1,2,3,4,5};

	std::cout << "Iter Print const:" << "\n";
	::iter(ci_array, 5, print);
	std::cout << "\n\n";

	char c_array[5] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << "Before iter:" << "\n";
	::iter(c_array, 5, print);
	std::cout << "\n";
	::iter(c_array, 5, add_one);
	std::cout << "After add_one iter:" << "\n";
	::iter(c_array, 5, print);
	std::cout << std::endl;

	return (0);
}
