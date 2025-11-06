# include "Fixed.hpp"

/*	--- OCF	--- */

// Default Constructor
Fixed::Fixed() : _rawBits(0)
{
	// std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value) : _rawBits(0)
{
	// std::cout << "Int constructor called\n";
	this->_rawBits = value << this->_fractionalBits;	
}

Fixed::Fixed(const float value) : _rawBits(0)
{
	// std::cout << "Float constructor called\n";
	this->_rawBits = (int)roundf(value * (1 << this->_fractionalBits));
}

// Copy Constructor
Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Copy constructor called\n";
	*this = copy;
}

// Default Destructor
Fixed::~Fixed()
{
	// std::cout << "Destructor called\n";
}

//	--- Copy Assignment Operator ---	//

Fixed& Fixed::operator=(const Fixed &copy)
{
	// std::cout << "Copy assignment operator called\n";
	if (this != &copy)
		this->_rawBits = copy.getRawBits();
	return *this;
}

//	---	Comparison Operators ---  //
bool Fixed::operator>(const Fixed &obj) const
{
	return (this->getRawBits() > obj.getRawBits());
}

bool Fixed::operator<(const Fixed &obj) const
{
	return (this->getRawBits() < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return (this->getRawBits() >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return (this->getRawBits() <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const
{
	return (this->getRawBits() == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return (this->getRawBits() != obj.getRawBits());
}
//	-------  //

//	--- Arithmetic Operators ---  //
Fixed Fixed::operator+(const Fixed &obj) const
{
	return (this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	return (this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	return (this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	return (this->toFloat() / obj.toFloat());
}
//	-------  //

//	--- Increment/Decriment Operators ---  //
Fixed& Fixed::operator++()
{
	this->_rawBits += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_rawBits += 1;
	return (temp);
}

Fixed& Fixed::operator--()
{
	this->_rawBits -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_rawBits -= 1;
	return (temp);
}
//	-------  //

//	--- Overloaded Static Member Functions ---  //
Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);	
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);	
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a < b ? b : a);	
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a < b ? b : a);	
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
	return ((float)this->getRawBits() / (1 << _fractionalBits));
}
