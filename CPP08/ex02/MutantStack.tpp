#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

template <typename T, class Container> 
MutantStack<T, Container>::MutantStack(void) : std::stack<T, Container>() {}

template <typename T, class Container> 
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container> &obj) : std::stack<T, Container>(obj) {}

template <typename T, class Container> 
MutantStack<T, Container>::~MutantStack(void) {}

template <typename T, class Container> 
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack<T, Container> &obj)
{
	if (this != &obj)
		std::stack<T, Container>::operator=(obj);
	return (*this);
}

template <typename T, class Container> 
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin(void)
{
	return (this->c.begin());
}

template <typename T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end(void)
{
	return (this->c.end());
}

template <typename T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin(void) const
{
	return (this->c.begin());
}

template <typename T, class Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T,Container>::end(void) const
{
	return (this->c.end());
}

template <typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin(void)
{
	return (this->c.rbegin());
}

template <typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend(void)
{
	return (this->c.rend());
}

template <typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin(void) const
{
	return (this->c.rbegin());
}

template <typename T, class Container>
typename  MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend(void) const
{
	return (this->c.rend());
}

#endif