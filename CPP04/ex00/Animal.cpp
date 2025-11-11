# include "Animal.hpp"

Animal::Animal() : type("Gambuzino")
{
	std::cout << "Animal class constructed" << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.type)
{
	std::cout << "Animal class copied" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal class destructor" << std::endl;
}

Animal& Animal::operator=(const Animal &copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
		std::cout << "Animal class copied using operator assignment" << std::endl;
	}
	return (*this);
}

std::string Animal::getType(void) const
{
	return (this->type);
}

void Animal::makeSound(void) const
{
	std::cout << "* ... *" << std::endl;
}
