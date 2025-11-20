# include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "\n";
	std::cout << "a is " << a << "\n";
	std::cout << "b is " << b << "\n";
	std::cout << "c is " << c << "\n";
	std::cout << "d is " << d << "\n\n";

	std::cout << "a is " << a.toInt() << " as integer" << "\n";
	std::cout << "b is " << b.toInt() << " as integer" << "\n";
	std::cout << "c is " << c.toInt() << " as integer" << "\n";
	std::cout << "d is " << d.toInt() << " as integer" << "\n\n";

	std::cout << "a is " << a.toFloat() << " as float" << "\n";
	std::cout << "b is " << b.toFloat() << " as float" << "\n";
	std::cout << "c is " << c.toFloat() << " as float" << "\n";
	std::cout << "d is " << d.toFloat() << " as float" << "\n\n";

	return 0;	
}
