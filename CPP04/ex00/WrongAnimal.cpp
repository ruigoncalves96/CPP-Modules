# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Gambuzino")
{
	std::cout << "WrongAnimal class constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : type(copy.type)
{
	std::cout << "WrongAnimal class copied" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal class destructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
		std::cout << "WrongAnimal class copied using operator assignment" << std::endl;
	}
	return (*this);
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "* ??? *" << std::endl;
}
