#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <iterator>

class Span
{
	public:
		Span(unsigned int);
		Span(const Span&);
		~Span(void);

		Span &operator=(const Span&);

		unsigned int getSize(void) const;
		const std::vector<int> &getSpan(void) const;

		void addNumber(int);

		template <typename Iterator>
		void addMultipleNumbers(Iterator begin, Iterator end);

		unsigned long shortestSpan(void) const;
		unsigned long longestSpan(void) const;


	private:
		Span(void);

		std::vector<int> _spanContainer;
		unsigned int _size;
};

template<typename Iterator>
void Span::addMultipleNumbers(Iterator begin, Iterator end)
{
	std::vector<int> temp;
	for (Iterator it = begin; it != end; ++it)
		temp.push_back(*it);

	if (temp.size() > _size - _spanContainer.size())
		throw(std::out_of_range("Not enough space in Span to add size of iterators")); 

	this->_spanContainer.insert(this->_spanContainer.end(), temp.begin(), temp.end());
}

std::ostream &operator<<(std::ostream &os, const Span &obj);

#endif