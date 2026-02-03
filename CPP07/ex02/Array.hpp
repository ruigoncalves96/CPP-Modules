#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array&);
		~Array(void);

		Array &operator=(const Array&);
		T &operator[](unsigned int idx);
		const T &operator[](unsigned int idx) const;

		unsigned int len(void) const;

	private:
		T *_array;
		unsigned int _array_len;
};

# include "Array.tpp"

#endif