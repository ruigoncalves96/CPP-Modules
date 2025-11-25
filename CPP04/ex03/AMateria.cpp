# include "AMateria.hpp"

AMateria::AMateria() : _type("<default>") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria &copy) : _type(copy.getType()) {}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria &copy)
{
	(void)copy;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}