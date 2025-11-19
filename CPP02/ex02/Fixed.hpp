#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath> //roundf

class Fixed
{
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float fValue);
		Fixed(const Fixed &copy);
		~Fixed();

		//	Copy Assignment Operator
		Fixed& operator=(const Fixed &copy);

		//	Comparison Operators
		bool operator>(const Fixed &obj) const;
		bool operator<(const Fixed &obj) const;
		bool operator>=(const Fixed &obj) const;
		bool operator<=(const Fixed &obj) const;
		bool operator==(const Fixed &obj) const;
		bool operator!=(const Fixed &obj) const;

		//	Arithmetic Operators
		Fixed operator+(const Fixed &obj) const;
		Fixed operator-(const Fixed &obj) const;
		Fixed operator*(const Fixed &obj) const;
		Fixed operator/(const Fixed &obj) const;

		//	Increment/Decriment Operators
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		//	Overloaded Static Member Functions
		static 			Fixed& min(Fixed &a, Fixed &b);
		static const	Fixed& min(const Fixed &a, const Fixed &b);
		static 			Fixed& max(Fixed &a, Fixed &b);
		static const 	Fixed& max(const Fixed &a, const Fixed &b);

		int 	getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;


	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
};

#endif