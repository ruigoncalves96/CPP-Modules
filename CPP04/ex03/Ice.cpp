# include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &copy) : AMateria(copy.getType()) {}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice &copy)
{
	(void)copy;
	return (*this);
}

AMateria* Ice::clone() const
{
	Ice *clone = new Ice();
	return (clone);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; 
}

