# include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat class constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat class copied" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat class destructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &copy)
{
	if (this != &copy)
	{
		WrongAnimal::operator=(copy);
		std::cout << "WrongCat class copied using operator assignment" << std::endl;
	}
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "* MEEEW *" << std::endl;
}

