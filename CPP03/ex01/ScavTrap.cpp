# include "ScavTrap.hpp"

/*	--- Public ---  */

//	--- Constructors and Destructors ---  //
ScavTrap::ScavTrap() : ClapTrap()
{
	this->_health = 100;
	this->_energy = 50;
	this->_attackDamage = 20;
	std::cout << "SCAVTRAP default constructor called (no name inserted)." << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	this->_health = 100;
	this->_energy = 50;
	this->_attackDamage = 20;
	std::cout << "SCAVTRAP \"" << name << "\" was created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
			: ClapTrap(copy)
{
	std::cout << "SCAVTRAP \"" << copy._name << "\" was cloned." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "SCAVTRAP \"" << this->_name << "\" was destroyed." << std::endl;
}
//	------	//

//	--- Copy Assignment Operator ---  //
ScavTrap& ScavTrap::operator=(const ScavTrap&copy)
{
	std::cout << "SCAVTRAP copy assignment called." << std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy);
	return (*this);
}
//	------	//

//	---	Member Functions --- //

void ScavTrap::attack(const std::string& target)
{
	if (!this->canPerformAction("attack"))
		return ;
	this->_energy--;
	std::cout << "SCAVTRAP \"" << this->_name << "\" attacks " << target << ", causing "
			<< this->_attackDamage << " points of damage!\n";
	std::cout << "Current energy: " << this->_energy << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (!this->canPerformAction("keeper"))
		return ;
	std::cout << "SCAVTRAP \"" << this->_name << "\" is now in Gate keeper Mode!" << std::endl;
}
//	------  //

/*	--- Private ---  */

std::string ScavTrap::getTrapType() const
{
	return ("SCAVTRAP");
}
//	------  //

