# include "Character.hpp"

Character::Character() : ICharacter(), _name("<default>")
{
	std::cout << "Character: \'<default>\' created!" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string const &name) : ICharacter(), _name(name)
{
	std::cout << "Character: \'" << name << "\' created!" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character &copy) : ICharacter(), _name(copy._name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = (copy.inventory[i]) ? copy.inventory[i]->clone() : NULL;
}

Character::~Character()
{
	std::cout << "Character: \'" << this->_name << "\' deleted!" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
}

Character& Character::operator=(const Character &copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		for (int i = 0; i < 4; i++)
		{
			delete this->inventory[i];
			this->inventory[i] = (copy.inventory[i]) ? copy.inventory[i]->clone() : NULL;
		}
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
  	for (int i = 0; i < 4; i++)
    {
        if (!this->inventory[i])
        {
			std::cout << "\'" << this->_name << "\'" 
					<< " equiped " << "\'" << m->getType() << "\'"
					<< " in slot " << i + 1 << std::endl;
            this->inventory[i] = m;
            return;
        }
    }
	std::cout << "\'" << this->_name << "\'" << " has no free slots!" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Wrong slot sent to " << this->_name << ". (Allowed - 0 -> 3)" << std::endl;
		return ;
	}
	std::cout << "\'" << this->_name << "\'" << " unequiped " << "\'"
			<< this->inventory[idx]->getType() << "\'"
			<< " of slot " << idx + 1 << std::endl;
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Wrong slot sent to " << this->_name << ". (Allowed - 0 -> 3)" << std::endl;
		return ;
	}
	if (this->inventory[idx])
	{
		std::cout << "\'" << this->_name << "\'" << " used " << "\'"
				<< this->inventory[idx]->getType() << "\'"
				<< " on " << target.getName() << std::endl;
		this->inventory[idx]->use(target);
		return ;
	}
	std::cout << "\'" << this->_name << "\' tried to use a spell, but has slot " << idx + 1 << " empty" << std::endl;
}

void Character::printSlots(void) const
{
	std::cout << "* " << this->_name << " slots *\n";
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			std::cout << "Slot " << i + 1 << ": " << this->inventory[i]->getType() << "\n"; 
		else
			std::cout << "Slot " << i + 1 << ": --- \n"; 
	}
}
