# include "Point.hpp"

// Cross product
// For two vectors u = (ux, uy) and v = (vx, vy), the 2D cross product is:
// 		u * v = ux * vy − uy * vx
//
// If result > 0 → v is on one side of u
// If result < 0 → v is on the other side of u
// If result = 0 → v is exactly on the line (edge)
//
static Fixed cross(const Point& a, const Point& b, const Point& point)
{
    return (b.getXpoint() - a.getXpoint()) * (point.getYpoint() - a.getYpoint())
         - (b.getYpoint() - a.getYpoint()) * (point.getXpoint() - a.getXpoint());
}

bool bsp(const Point a, const Point b, const Point c, const Point p)
{
    Fixed c1 = cross(a, b, p);
    Fixed c2 = cross(b, c, p);
    Fixed c3 = cross(c, a, p);

    bool neg = (c1 < 0 && c2 < 0 && c3 < 0);
    bool pos = (c1 > 0 && c2 > 0 && c3 > 0);

    return (neg || pos);
}
