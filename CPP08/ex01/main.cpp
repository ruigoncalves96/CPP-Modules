# include "Span.hpp"
# include <iostream>

int main(void)
{
	Span sp = Span(50);
	try {
		// sp.addNumber(6);
		// sp.addNumber(3);
		// sp.addNumber(17);
		// sp.addNumber(9);
		// sp.addNumber(11);
		sp.addRandomNumbers();
		sp.printSpan();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e) { std::cout << e.what() << std::endl; }

	return 0;;
}