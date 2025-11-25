# include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
	std::cout << "Materia Source created." << std::endl;
	for (int i = 0; i < 4; i++)
		this->materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
		this->materias[i] = (copy.materias[i]) ? copy.materias[i]->clone() : NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << "Materia Source deleted." << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->materias[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->materias[i];
			this->materias[i] = (copy.materias[i]) ? copy.materias[i]->clone() : NULL;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
		return ;
    for (int i = 0; i < 4; i++)
    {
        if (!this->materias[i])
        {
			std::cout << "Materia \'" << materia->getType()
					<< "\' learned and stored Materia Source - slot " << i << "." << std::endl;
            this->materias[i] = materia;
            return;
        }
    }
	std::cout << "Materia \'" << materia->getType()
			<< "\' couldnt be learned. Materia Source slots are full." << std::endl;
	delete materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i] && this->materias[i]->getType() == type)
		{
			std::cout << "Materia \'" << type << "\' found in Materia Source. \'" << type << "\' created!" << std::endl;
			return (this->materias[i]->clone());
		}
	}
	std::cout << "No materia \'" << type << "\' found in Materia Source." << std::endl;
	return (NULL);
}
