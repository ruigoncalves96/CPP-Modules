# include "easyfind.hpp"
# include <iostream>
# include <vector>

int main(void)
{
	std::vector<int> array;
	for (int i = 0; i < 10; i++)
		array.push_back(i * 2);

	std::cout << "Vector <int> :\n";
	for (std::vector<int>::iterator it = array.begin(); it != array.end(); it++)
		std::cout << ". " << *it << "\n";
	std::cout << "|| ---- ---- ||\n\n";

	try{
		int to_find = 2;
		std::cout << "Value to find: " << to_find << "\n";
		std::vector<int>::const_iterator it = easyfind(array, to_find);
		std::cout << "Value found: " << *it << "\n";
		std::cout << "\n|| ---- ---- ||\n\n";
		to_find = 100;
		std::cout << "Value to find: " << to_find << "\n";
		it = easyfind(array, to_find);
		std::cout << "Value found: " << *it << "\n";
		std::cout << "|| ---- ---- ||\n";
	}
	catch (const std::exception &e) { std::cout << "Error: " << e.what() << std::endl; }

	return (0);
}