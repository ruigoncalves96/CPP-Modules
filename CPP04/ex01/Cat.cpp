# include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain)
{
	this->type = "Cat";
	std::cout << "Cat class constructed" << std::endl;
}

Cat::Cat(const Cat &copy)
	: Animal(copy), _brain(new Brain(*copy._brain))
{
	std::cout << "Cat class copied" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat class destructor" << std::endl;
}

Cat& Cat::operator=(const Cat &copy)
{
	if (this != &copy)
	{
		Animal::operator=(copy);
		delete _brain;
		this->_brain = new Brain(*copy._brain);
		std::cout << "Cat class copied using operator assignment" << std::endl;
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "* meeeew *" << std::endl;
}

Brain& Cat::getBrain(void)
{
	return (*this->_brain);
}

const Brain& Cat::getBrain(void) const
{
	return (*this->_brain);
}
