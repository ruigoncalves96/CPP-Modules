# include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	a.setRawBits(42);
	c = b;

	std::cout << a.getRawBits() << " <- a" << std::endl;
	std::cout << b.getRawBits() << " <- b" << std::endl;
	std::cout << c.getRawBits() << " <- c" << std::endl;

	return (0);
}
