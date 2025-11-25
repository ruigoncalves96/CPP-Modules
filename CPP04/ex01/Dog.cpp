# include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain)
{
	this->type = "Dog";
	std::cout << "Dog class constructed" << std::endl;
}

Dog::Dog(const Dog &copy)
	: Animal(copy), _brain(new Brain(*copy._brain))
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
		Animal::operator=(copy);
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

void Dog::setIdea(int idx, const std::string &idea)
{
	std::cout << "Dog will add an idea - ";
	return (_brain->setIdea(idx, idea));
}

const std::string Dog::getIdea(int idx) const
{
	return (_brain->getIdea(idx));
}


