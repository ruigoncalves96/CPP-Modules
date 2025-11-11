# include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog class constructed" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog class copied" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog class destructor" << std::endl;
}

Dog& Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		Animal::operator=(copy);
		std::cout << "Dog class copied using operator assignment" << std::endl;
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "* WOOOF *" << std::endl;
}
