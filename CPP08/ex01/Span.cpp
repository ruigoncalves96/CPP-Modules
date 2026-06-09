# include "Span.hpp"
# include <iostream>
# include <algorithm>
# include <limits>

Span::Span(void) {}

Span::Span(unsigned int size) : _size(size) {}

Span::Span(const Span &obj) : _spanContainer(obj.getSpan()), _size(obj.getSize()) {}

Span::~Span(void) {}

Span &Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		this->_size = obj.getSize();
		this->_spanContainer = obj.getSpan();
	}
	return (*this);
}

unsigned int Span::getSize(void) const
{
	return (this->_size);
}

const std::vector<int> &Span::getSpan(void) const
{
	return (this->_spanContainer);
}

void Span::addNumber(int value)
{
	if (this->_spanContainer.size() == _size)
		throw(std::out_of_range("Span is already full"));
	this->_spanContainer.push_back(value);
}

unsigned long Span::shortestSpan(void) const
{
	if (this->_spanContainer.size() <= 1)
		throw (std::invalid_argument("Not enough values to search for"));

	std::vector<int> copy = this->_spanContainer;
	std::sort(copy.begin(), copy.end());

	std::vector<int>::const_iterator current = copy.begin() + 1;

	long shortest_spanContainer = std::numeric_limits<int>::max();
	while (current != copy.end())
	{
		long span = *current - *(current - 1);
		if (span < shortest_spanContainer)
			shortest_spanContainer = span;
		++current;
	}
	return (shortest_spanContainer);
}

unsigned long Span::longestSpan(void) const
{
	if (this->_spanContainer.size() <= 1)
		throw (std::invalid_argument("Not enough values to search for"));
	return (*std::max_element(this->_spanContainer.begin(), this->_spanContainer.end()) -
			*std::min_element(this->_spanContainer.begin(), this->_spanContainer.end()));
}

std::ostream &operator<<(std::ostream &os, const Span &obj)
{
	const std::vector<int> &objSpanVec = obj.getSpan();
	std::vector<int>::const_iterator it;
	size_t i = 0;

	if (objSpanVec.empty())
		os << "Span: * is empty *\n";
	else 
	{
		os << "Span: \n";
		for (it = objSpanVec.begin(); it != objSpanVec.end(); ++it)
		{
			os << "	[" << i << "] = " << *it << "\n";
			++i;
		}
	}
	return (os);
}
