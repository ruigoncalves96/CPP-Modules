# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>

int random_int()
{
	static bool seeded = false;

	if (!seeded)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}
	return std::rand();
}

Base* generate(void)
{
	int random = random_int() % 3;
	Base *new_class = NULL;
	if (random == 0)
		new_class = new A;
	else if (random == 1)
		new_class = new B;
	else if (random == 2)
		new_class = new C;
	return (new_class);
}

void identify(Base* p)
{
	if (!p)
	{
		std::cerr << "Error: Base = NULL" << std::endl;
		return ;
	}
	if (dynamic_cast<A*>(p))
		std::cout << "Generated Class A*" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Generated Class B*" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Generated Class C*" << std::endl;
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Generated Class A&" << std::endl;
		return ;
	}
	catch (std::bad_cast &) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Generated Class B&" << std::endl;
		return ;
	}
	catch (std::bad_cast &) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Generated Class C&" << std::endl;
		return ;
	}
	catch (std::bad_cast &) {}
}

int main(void)
{
	Base *new_class = generate();
	if (!new_class)
	{
		std::cerr << "Error: Failed to generate a Class" << std::endl;
		return (1);
	}

	identify(new_class);
	identify(*new_class);

	delete new_class;
	return (0);
}