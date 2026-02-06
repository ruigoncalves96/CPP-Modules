#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack&);
		~MutantStack(void);

		MutantStack &operator=(const MutantStack&);

		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;

		iterator begin(void);
		iterator end(void);
		const_iterator begin(void) const;
		const_iterator end(void) const;

		reverse_iterator rbegin(void);
		reverse_iterator rend(void);
		const_reverse_iterator rbegin(void) const;
		const_reverse_iterator rend(void) const;
};

# include "MutantStack.tpp"

#endif