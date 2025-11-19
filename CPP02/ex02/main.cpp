# include "Fixed.hpp"

std::ostream& operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) + Fixed( 2 ) );
	Fixed const c( Fixed( 5.05f ) - Fixed( 2 ) );
	Fixed const d( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const e( Fixed( 5.05f ) / Fixed( 2 ) );
	Fixed x(42);

	std::cout << "Increment/Decriment Operators\n";
	std::cout << "-----\n";
	std::cout << "a = " << a << "\n";
	std::cout << "++a = " << ++a << "\n";
	std::cout << "a = " << a << "\n";
	std::cout << "a++ = " << a++ << "\n";
	std::cout << "a = " << a << "\n";

	std::cout << "\nArithmetic Operators\n";
	std::cout << "-----\n";
	std::cout << "b -> 5.05 + 2 = " << b << "\n";
	std::cout << "c -> 5.05 - 2 = " << c << "\n";
	std::cout << "d -> 5.05 * 2 = " << d << "\n";
	std::cout << "e -> 5.05 / 2 = " << e << "\n";

	std::cout << "\nComparison Operators\n";
	std::cout << "-----\n";
	std::cout << "a > b = " << (a > b) << "\n";
	std::cout << "b > c = " << (b > c) << "\n";
	std::cout << "-----\n";
	std::cout << "a < b = " << (a < b) << "\n";
	std::cout << "b < a = " << (b < a) << "\n";
	std::cout << "-----\n";
	std::cout << "a >= b = " << (a >= b) << "\n";
	std::cout << "b >= a = " << (b >= a) << "\n";
	std::cout << "-----\n";
	std::cout << "a <= b = " << (a <= b) << "\n";
	std::cout << "b <= a = " << (b <= a) << "\n";
	std::cout << "-----\n";
	std::cout << "a == b = " << (a == b) << "\n";
	std::cout << "a == a = " << (a == a) << "\n";
	std::cout << "-----\n";
	std::cout << "a != b = " << (a != b) << "\n";
	std::cout << "a != a = " << (a != a) << "\n";

	std::cout << "\nMax & Min\n";
	std::cout << "-----\n";
	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";
	std::cout << "c = " << c << "\n";
	std::cout << "x = " << x << "\n";
	std::cout << "-----\n";
	std::cout << "Smallest(a, x) = " << Fixed::min( a, x ) << "\n";
	std::cout << "Biggest(a, x) = " << Fixed::max( a, x ) << "\n";
	std::cout << "-----\n";
	std::cout << "Smallest(const b, const c) = " << Fixed::min( b, c ) << "\n";
	std::cout << "Biggest(const b, const c) = " << Fixed::max( b, c ) << "\n";
	std::cout << "-----\n";
	std::cout << "Smallest(a, const b) = " << Fixed::min( a, b ) << "\n";
	std::cout << "Biggest(a, const b) = " << Fixed::max( a, b ) << "\n";
	std::cout << std::endl;

	return 0;	
}
