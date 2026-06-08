# include "iter.hpp"
# include <iostream>

int main(void)
{
	std::cout << "|| INT ARRAY ||\n";
	int i_array[5] = {1,2,3,4,5};

	std::cout << "Before iter:" << "\n";
	::iter(i_array, 5, print<int>);
	std::cout << "\n";
	::iter(i_array, 5, add_one<int>);
	std::cout << "After add_one iter:" << "\n";
	::iter(i_array, 5, print<int>);
	std::cout << "\n\n";

	std::cout << "|| CONST INT ARRAY ||\n";
	const int ci_array[5] = {1,2,3,4,5};

	std::cout << "Iter Print const:" << "\n";
	::iter(ci_array, 5, print<int>);
	// ::iter(ci_array, 5, add_one<int>);
	std::cout << "\n\n";

	std::cout << "|| STRING ARRAY ||\n";
	std::string strArray[] = {"hello", "42", "world", "!"};

	std::cout << "Before iter:" << "\n";
	::iter(strArray, 4, print<std::string>);
	std::cout << "\n";
	// ::iter(strArray, 4, add_one<std::string>);
	std::cout << std::endl;

	return (0);
}
