# include "FragTrap.hpp"

/*	--- Public ---  */

//	--- Constructors and Destructors ---  //
FragTrap::FragTrap() : ClapTrap()
{
	this->_health 		= this->kDefHealth;
	this->_energy 		= this->kDefEnergy;
	this->_attackDamage = this->kDefAttackDamage;
	std::cout << "FragTrap default constructor called (no name inserted)." << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	this->_health 		= this->kDefHealth;
	this->_energy 		= this->kDefEnergy;
	this->_attackDamage = this->kDefAttackDamage;
	std::cout << "FragTrap \"" << name << "\" was created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
			: ClapTrap(copy)
{
	std::cout << "FragTrap \"" << copy._name << "\" was cloned." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap \"" << this->_name << "\" was destroyed." << std::endl;
}
//	------	//

//	--- Copy Assignment Operator ---  //
FragTrap& FragTrap::operator=(const FragTrap&copy)
{
	std::cout << "FragTrap copy assignment called." << std::endl;
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
	std::cout << "FragTrap \"" << this->_name << "\" is asking for High Fives!!" << std::endl;
}
//	------  //

/*	--- Private ---  */

std::string FragTrap::getTrapType() const
{
	return ("FragTrap");
}
//	------  //

