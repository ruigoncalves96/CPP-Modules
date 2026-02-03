#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *array, const size_t array_len, void (*func)(T &value))
{
	for (size_t i = 0; i < array_len; i++)
		func(array[i]);
}

template <typename T>
void add_one(T &value)
{
	value++;
}

template <typename T>
void print(T value)
{
	std::cout << value << " ";
}

#endif