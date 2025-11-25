# include "Cat.hpp"

Cat::Cat() : AAnimal(), _brain(new Brain)
{
	this->type = "Cat";
	std::cout << "Cat class constructed" << std::endl;
}

Cat::Cat(const Cat &copy)
	: AAnimal(copy), _brain(new Brain(*copy._brain))
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
		AAnimal::operator=(copy);
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

void Cat::setIdea(int idx, const std::string &idea)
{
	std::cout << "Cat will add an idea - ";
	return (_brain->setIdea(idx, idea));
}

const std::string Cat::getIdea(int idx) const
{
	return (_brain->getIdea(idx));
}

