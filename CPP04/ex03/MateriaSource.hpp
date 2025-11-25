#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		~MateriaSource();

		MateriaSource& operator=(const MateriaSource &copy);

		void learnMateria(AMateria*); // virtual
		AMateria* createMateria(std::string const & type); // virtual

	private:
		AMateria *materias[4];
};

#endif
