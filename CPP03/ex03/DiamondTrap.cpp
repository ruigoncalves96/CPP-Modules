# include "DiamondTrap.hpp"

/*	--- Public ---  */

//	--- Constructors and Destructors ---  //
DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	this->_health 		= FragTrap::kDefHealth;
	this->_energy 		= ScavTrap::kDefEnergy;
	this->_attackDamage = FragTrap::kDefAttackDamage;
	std::cout << "DIAMONDTRAP default constructor called (no name inserted)." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name)
		: ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	this->_health 		= FragTrap::kDefHealth;
	this->_energy 		= ScavTrap::kDefEnergy;
	this->_attackDamage = FragTrap::kDefAttackDamage;
	std::cout << "DIAMONDTRAP \"" << name << "\" was created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap&copy)
		: ClapTrap(copy), ScavTrap(copy), FragTrap(copy), _name(copy._name)
{
	std::cout << "DIAMONDTRAP \"" << copy._name << "\" was cloned." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DIAMONDTRAP \"" << this->_name << "\" was destroyed." << std::endl;
}
//	------	//

//	--- Copy Assignment Operator ---  //
DiamondTrap& DiamondTrap::operator=(const DiamondTrap&copy)
{
	std::cout << "DIAMONDTRAP copy assignment called." << std::endl;
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
		this->_name = copy._name;
	}
	return (*this);
}
//	------	//

//	---	Member Functions --- //

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->_name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
//	------  //

/*	--- Private ---  */

void DiamondTrap::printStatus()
{
	this->whoAmI();
	std::cout << "health: " << _health << "\n";
	std::cout << "energy: " << _energy << "\n";
	std::cout << "attack: " << _attackDamage << "\n";
}

std::string DiamondTrap::getTrapType() const
{
	return ("DIAMONDTRAP");
}
//	------  //

