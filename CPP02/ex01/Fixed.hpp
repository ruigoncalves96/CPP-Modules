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

		Fixed& operator=(const Fixed &copy);

		int 	getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
};

#endif