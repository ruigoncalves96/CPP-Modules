# include "Dog.hpp"

Dog::Dog() : AAnimal(), _brain(new Brain)
{
	this->type = "Dog";
	std::cout << "Dog class constructed" << std::endl;
}

Dog::Dog(const Dog &copy)
	: AAnimal(copy), _brain(new Brain(*copy._brain))
{
	std::cout << "Dog class copied" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog class destructor" << std::endl;
}

Dog& Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		AAnimal::operator=(copy);
		delete _brain;
		_brain = new Brain(*copy._brain);
		std::cout << "Dog class copied using operator assignment" << std::endl;
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "* WOOOF *" << std::endl;
}

Brain& Dog::getBrain(void)
{
	return (*this->_brain);
}

const Brain& Dog::getBrain(void) const
{
	return (*this->_brain);
}
