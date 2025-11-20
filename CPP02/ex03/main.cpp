# include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	const Point a(2, 2);
	const Point b(3, 4);
	const Point c(5, 3);

	const Point p1(3.7f, 2.6f); // INSIDE point *true*
	const Point p2(3, 3); // INSIDE point *true*
	const Point p3(3.3f, 2.43f); // OUTSIDE point *false*
    const Point p4(3.5f, 2.5f); // ON EDGE point *false* 

	std::cout << "Triangle -> " << "A_" << a << " B_" << b << " C_" << c << "\n"; 
	std::cout << "Point -> " << p1 << "\n";
	if (bsp(a, b , c, p1))
		std::cout << "P1 is INSIDE of the triangle!\n";
	else
		std::cout << "P1 is OUTSIDE of the triangle!\n";

	std::cout << "\n\n";
	std::cout << "Triangle -> " << "A_ " << a << " B_" << b << " C_" << c << "\n"; 
	std::cout << "Point -> " << p2 << "\n";
	if (bsp(a, b , c, p2))
		std::cout << "P2 is INSIDE of the triangle!\n";
	else
		std::cout << "P2 is OUTSIDE of the triangle!\n";

	std::cout << "\n\n";
	std::cout << "Triangle -> " << "A_ " << a << " B_" << b << " C_" << c << "\n"; 
	std::cout << "Point -> " << p3 << "\n";
	if (bsp(a, b , c, p3))
		std::cout << "P3 is INSIDE of the triangle!" << std::endl;
	else
		std::cout << "P3 is OUTSIDE of the triangle!" << std::endl;

	std::cout << "\n\n";
	std::cout << "Triangle -> " << "A_ " << a << " B_" << b << " C_" << c << "\n"; 
	std::cout << "Point -> " << p4 << "\n";
	if (bsp(a, b , c, p4))
		std::cout << "P4 is INSIDE of the triangle!" << std::endl;
	else
		std::cout << "P4 is OUTSIDE of the triangle!" << std::endl;

	return (0);
}
