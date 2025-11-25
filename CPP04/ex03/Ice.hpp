#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &copy);
		~Ice();

		Ice& operator=(const Ice &copy);

		AMateria* clone() const; // virtual
		void use(ICharacter& target); // virtual
};

#endif
