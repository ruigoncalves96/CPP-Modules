#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

template <typename T>
typename T::const_iterator easyfind(T &container, int nbr)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), nbr);
	if (*it != nbr)
		throw (std::runtime_error("No value found in container"));
	return (it);
}

#endif