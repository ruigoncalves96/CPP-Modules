#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point
{
	public:
		Point();
		Point(const float &x, const float &y);
		Point(const Point &copy);
		~Point();

		Fixed getXpoint(void) const;
		Fixed getYpoint(void) const;

	private:
		const Fixed x;
		const Fixed y;

		//	Copy Assignment Operator * Not available *
		Point& operator=(const Point &copy);
};

std::ostream& operator<<(std::ostream &os, const Point &obj);

#endif