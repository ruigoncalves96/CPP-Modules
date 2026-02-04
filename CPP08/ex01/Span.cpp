# include "Span.hpp"
# include <iostream>
# include <algorithm>
# include <iterator>
# include <ctime>
# include <cstdlib>

Span::Span(void) {}

Span::Span(unsigned int size) : _size(size) {}

Span::Span(const Span &obj) : _cont(obj.cont()), _size(obj.size()) {}

Span::~Span(void) {}

Span &Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		this->_size = obj.size();
		this->_cont = obj.cont();
	}
	return (*this);
}

unsigned int Span::size(void) const
{
	return (this->_size);
}

std::multiset<int> Span::cont(void) const
{
	return (this->_cont);
}

void Span::addNumber(int value)
{
	if (this->_cont.size() == _size)
		throw(std::out_of_range("Span is already full"));
	this->_cont.insert(value);
}

int randomNumber () { return (std::rand() % 100); }

void Span::addRandomNumbers(void)
{
	std::srand(unsigned(std::time(0)));
	for (unsigned int i = 0; i < this->_size; i++)
		this->_cont.insert(randomNumber());
}

unsigned long Span::shortestSpan(void) const
{
	if (this->_cont.size() <= 1)
		throw (std::invalid_argument("Not enough values to search for"));

	std::multiset<int>::const_iterator current = this->_cont.begin();
	std::multiset<int>::const_iterator next = current;
	++next;

	unsigned long min_span = *next - *current;
	while (next != this->_cont.end())
	{
		unsigned long span = *next - *current;
		if (span < min_span)
			min_span = span;
		++current;
		++next;
	}
	return (min_span);
}

unsigned long Span::longestSpan(void) const
{
	if (this->_cont.size() <= 1)
		throw (std::invalid_argument("Not enough values to search for"));
	return (*(--_cont.end()) - *(_cont.begin()));
}

void Span::printSpan(void) const
{
	std::multiset<int>::const_iterator it = _cont.begin();
	while (it != _cont.end())
		std::cout << *it++ << " ";
	std::cout << std::endl;
}

