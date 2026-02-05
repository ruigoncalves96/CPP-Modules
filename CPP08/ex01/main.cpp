# include "Span.hpp"
# include <iostream>

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
			// sp.printSpan();
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
			sp.addNumber(11);
			// sp.printSpan();
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
			// sp.printSpan();
			std::cout << "* Shortest Span = " << sp.shortestSpan() << std::endl;
			std::cout << "* Longest Span = " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e) { std::cout << e.what() << std::endl; }
	}
	std::cout << "\n|| Multiple adding, no errors ||\n";
	{
		Span sp = Span(10000);
		try {
			sp.addRandomNumbers(10000);
			// sp.printSpan();
			std::cout << "* Shortest Span = " << sp.shortestSpan() << std::endl;
			std::cout << "* Longest Span = " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e) { std::cout << e.what() << std::endl; }
	}
	std::cout << "\n|| Multiple adding, with errors - not enough space ||\n";
	{
		Span sp = Span(50);
		try {
			sp.addRandomNumbers(20);
			sp.addRandomNumbers(10);
			sp.addRandomNumbers(5);
			sp.addRandomNumbers(5);
			sp.addRandomNumbers(30);
			// sp.printSpan();
			std::cout << "* Shortest Span = " << sp.shortestSpan() << std::endl;
			std::cout << "* Longest Span = " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e) { std::cout << e.what() << std::endl; }
	}

	return 0;;
}