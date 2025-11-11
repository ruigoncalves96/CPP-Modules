# include "AAnimal.hpp"

AAnimal::AAnimal() : type("Gambuzino")
{
	std::cout << "AAnimal class constructed" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) : type(copy.type)
{
	std::cout << "AAnimal class copied" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal class destructor" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
		std::cout << "AAnimal class copied using operator assignment" << std::endl;
	}
	return (*this);
}

std::string AAnimal::getType(void) const
{
	return (this->type);
}
