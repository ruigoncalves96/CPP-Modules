# include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &copy) : AMateria(copy.getType()) {}

Cure::~Cure() {}

Cure& Cure::operator=(const Cure &copy)
{
	(void)copy;
	return (*this);
}

AMateria* Cure::clone() const
{
	Cure *clone = new Cure();
	return (clone);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; 
}


