# include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat class constructed" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat class copied" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat class destructor" << std::endl;
}

Cat& Cat::operator=(const Cat &copy)
{
	if (this != &copy)
	{
		Animal::operator=(copy);
		std::cout << "Cat class copied using operator assignment" << std::endl;
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "* meeeew *" << std::endl;
}

