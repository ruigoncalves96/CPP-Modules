#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <set>

class Span
{
	public:
		Span(unsigned int);
		Span(const Span&);
		~Span(void);

		Span &operator=(const Span&);

		unsigned int size(void) const;
		std::multiset<int> cont(void) const;

		void addNumber(int);
		void addRandomNumbers(void);
		unsigned long shortestSpan(void) const;
		unsigned long longestSpan(void) const;

		void printSpan(void) const;

	private:
		Span(void);

		std::multiset<int> _cont;
		unsigned int _size;
};

#endif