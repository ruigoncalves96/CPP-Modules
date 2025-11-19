# include "Fixed.hpp"

/*	--- OCF	--- */

// Default Constructor
Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value)
	: _rawBits(value << this->_fractionalBits)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float value)
	: _rawBits(static_cast<int>(roundf(value * (1 << this->_fractionalBits))))
{
	std::cout << "Float constructor called\n";
}

// Copy Constructor
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

// Default Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

// Copy Assignment Operator
Fixed& Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &copy)
		this->_rawBits = copy.getRawBits();
	return *this;
}

/*	--- Public	--- */

int Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

int Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->_fractionalBits);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << _fractionalBits));
}
