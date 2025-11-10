# include "FragTrap.hpp"

/*	--- Public ---  */

//	--- Constructors and Destructors ---  //
FragTrap::FragTrap() : ClapTrap()
{
	this->_health = 100;
	this->_energy = 100;
	this->_attackDamage = 30;
	std::cout << "FRAGTRAP default constructor called (no name inserted)." << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	this->_health = 100;
	this->_energy = 100;
	this->_attackDamage = 30;
	std::cout << "FRAGTRAP \"" << name << "\" was created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
			: ClapTrap(copy)
{
	std::cout << "FRAGTRAP \"" << copy._name << "\" was cloned." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FRAGTRAP \"" << this->_name << "\" was destroyed." << std::endl;
}
//	------	//

//	--- Copy Assignment Operator ---  //
FragTrap& FragTrap::operator=(const FragTrap&copy)
{
	std::cout << "FRAGTRAP copy assignment called." << std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy);
	return (*this);
}
//	------	//

//	---	Member Functions --- //

void FragTrap::highFivesGuys(void)
{
	if (!this->canPerformAction("high five"))
		return ;
	std::cout << "FRAGTRAP \"" << this->_name << "\" is asking for High Fives!!" << std::endl;
}
//	------  //

/*	--- Private ---  */

std::string FragTrap::getTrapType() const
{
	return ("FRAGTRAP");
}
//	------  //

