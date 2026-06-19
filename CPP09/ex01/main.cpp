#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (std::cerr << "Error: wrong number of arguments." << std::endl, 1);
	
	try {
		std::cout << RPN::calculate(argv[1]) << std::endl;
	}
	catch (const std::exception &e) { std::cerr << "Error: " << e.what() << std::endl; }

	return (0);
}
