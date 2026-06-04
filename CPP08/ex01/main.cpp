# include "Span.hpp"
# include <iostream>
# include <list>
# include <ctime>
# include <cstdlib>

#define S_RANDOM_NUMBER 100

//	Helper function
int randomNumber()
{
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}
	return (std::rand() % S_RANDOM_NUMBER);
}

void randomListFill(std::list<int> &list, size_t amount)
{
	for (size_t i = 0; i < amount; ++i)
		list.push_back(randomNumber());
}

void randomVectorFill(std::vector<int> &vec, size_t amount)
{
	for (size_t i = 0; i < amount; ++i)
		vec.push_back(randomNumber());
}

int main(void)
{
	std::cout << "|| Single adding, no errors ||\n";
	{
		Span sp = Span(5);
		try {
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp;
			std::cout << "* Shortest Span = " << sp.shortestSpan() << std::endl;
			std::cout << "* Longest Span = " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e) { std::cout << e.what() << std::endl; }
	}
	std::cout << "\n|| Single adding, with errors - no more space ||\n";
	{
		Span sp = Span(5);
		try {
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.addNumber(42);
			std::cout << sp;
			std::cout << "* Shortest Span = " << sp.shortestSpan() << std::endl;
			std::cout << "* Longest Span = " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e) { std::cout << e.what() << std::endl; }
	}
	std::cout << "\n|| Single adding, with errors - no span check available ||\n";
	{
		Span sp = Span(5);
		try {
			sp.addNumber(6);
			std::cout << sp;
			std::cout << "* Shortest Span = " << sp.shortestSpan() << std::endl;
			std::cout << "* Longest Span = " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e) { std::cout << e.what() << std::endl; }
	}
	std::cout << "\n|| Multiple adding, no errors ||\n";
	{
		Span sp = Span(10000);
		std::vector<int> inputVec;
		randomVectorFill(inputVec, 5000);
		std::list<int> inputList;
		randomListFill(inputList, 5000);
		try {
			sp.addMultipleNumbers(inputVec.begin(), inputVec.end());
			sp.addMultipleNumbers(inputList.begin(), inputList.end());
			std::cout << sp;
			std::cout << "* Shortest Span = " << sp.shortestSpan() << std::endl;
			std::cout << "* Longest Span = " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e) { std::cout << e.what() << std::endl; }
	}
	std::cout << "\n|| Multiple adding, with errors - not enough space ||\n";
	{
		Span sp = Span(50);
		std::vector<int> inputVec;
		randomVectorFill(inputVec, 25);
		std::list<int> inputList;
		randomListFill(inputList, 26);
		try {
			sp.addMultipleNumbers(inputVec.begin(), inputVec.end());
			sp.addMultipleNumbers(inputList.begin(), inputList.end());
			std::cout << sp;
			std::cout << "* Shortest Span = " << sp.shortestSpan() << std::endl;
			std::cout << "* Longest Span = " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e) { std::cout << e.what() << std::endl; }
	}

	return 0;;
}