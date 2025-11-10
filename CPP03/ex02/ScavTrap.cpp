# include "ScavTrap.hpp"

/*	--- Public ---  */

//	--- Constructors and Destructors ---  //
ScavTrap::ScavTrap() : ClapTrap()
{
	this->_health = 100;
	this->_energy = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called (no name inserted)." << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	this->_health = 100;
	this->_energy = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap \"" << name << "\" was created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
			: ClapTrap(copy)
{
	std::cout << "ScavTrap \"" << copy._name << "\" was cloned." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap \"" << this->_name << "\" was destroyed." << std::endl;
}
//	------	//

//	--- Copy Assignment Operator ---  //
ScavTrap& ScavTrap::operator=(const ScavTrap&copy)
{
	std::cout << "ScavTrap copy assignment called." << std::endl;
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
	std::cout << "ScavTrap \"" << this->_name << "\" attacks " << target << ", causing "
			<< this->_attackDamage << " points of damage!\n";
	std::cout << "Current energy: " << this->_energy << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (!this->canPerformAction("keeper"))
		return ;
	std::cout << "ScavTrap \"" << this->_name << "\" is now in Gate keeper Mode!" << std::endl;
}
//	------  //

/*	--- Private ---  */

std::string ScavTrap::getTrapType() const
{
	return ("ScavTrap");
}
//	------  //

