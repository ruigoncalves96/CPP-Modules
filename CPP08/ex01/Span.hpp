#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <set>

# define RANDOM_RANGE 10000

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
		void addRandomNumbers(unsigned int);
		unsigned long shortestSpan(void) const;
		unsigned long longestSpan(void) const;

		void printSpan(void) const;

	private:
		Span(void);

		int randomNumber(void);

		std::multiset<int> _cont;
		unsigned int _size;
};

#endif