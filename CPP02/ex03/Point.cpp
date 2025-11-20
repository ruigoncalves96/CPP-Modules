# include "Point.hpp"

/*	--- OCF	--- */

// Default Constructor
Point::Point() : x(0), y(0) {}

Point::Point(const float &x, const float &y) : x(x), y(y) {}

// Copy Constructor
Point::Point(const Point &copy) : x(copy.x), y(copy.y) {}

// Default Destructor
Point::~Point() {}

/*	--- Public	--- */

Fixed Point::getXpoint(void) const
{
	return (this->x);
}

Fixed Point::getYpoint(void) const
{
	return (this->y);
}

/*	--- Stream	--- */

std::ostream& operator<<(std::ostream &os, const Point &obj)
{
	os << "x:";
	os << obj.getXpoint();
	os << " y:";
	os << obj.getYpoint();
	return (os);
}

/*	--- Private	--- */