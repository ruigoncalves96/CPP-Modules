#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (std::cerr << "Error: could not open file." << std::endl, 1);
	try { 
		BitcoinExchange BitcoinData;
		BitcoinData.printConversion(argv[1]);
	}
	catch (const std::exception &e) { std::cerr << "Error: " << e.what() << std::endl; return (1); }
	return (0);
}

