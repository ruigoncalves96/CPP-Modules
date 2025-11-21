# include "ClapTrap.hpp"

/*	--- Public ---  */

//	--- Constructors and Destructors ---  //
ClapTrap::ClapTrap()
	: _health(10), _energy(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called (no name inserted)." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
	: _name(name), _health(10), _energy(10), _attackDamage(0)
{
	std::cout << "ClapTrap \"" << name << "\" was created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
	: _name(copy._name),
	_health(copy._health),
	_energy(copy._energy),
	_attackDamage(copy._attackDamage)
{
	std::cout << "ClapTrap \"" << copy._name << "\" was cloned." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap \"" << this->_name << "\" was destroyed." << std::endl;
}
//	------	//

//	--- Copy Assignment Operator ---  //
ClapTrap& ClapTrap::operator=(const ClapTrap&copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_health = copy._health;
		this->_energy = copy._energy;
		this->_attackDamage = copy._attackDamage;
	}
	std::cout << "Copy assignment called." << std::endl;
	return (*this);
}
//	------	//

//	---	Member Functions --- //

void ClapTrap::attack(const std::string& target)
{
	if (!canPerformAction("attack"))
		return ;
	this->_energy--;
	std::cout << "ClapTrap \"" << this->_name << "\" attacks " << target << ", causing "
			<< this->_attackDamage << " points of damage!\n";
	std::cout << "Current energy: " << this->_energy << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_health == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead, cant take more damage!\n";
		return ;
	}
	if (amount > this->_health)
		this->_health = 0;
	else
		this->_health -= amount; 
	std::cout << "ClapTrap \"" << this->_name << "\" took " << amount << " points of damage!\n";
	std::cout << "Current health: " << this->_health << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!canPerformAction("repair"))
		return ;
	this->_health += amount;
	this->_energy--;
	std::cout << "ClapTrap \"" << this->_name << "\" repaired " << amount << " points of health!\n";
	std::cout << "Current health: " << this->_health << "\n";
	std::cout << "Current energy: " << this->_energy << std::endl;
}
//	------  //

/*	--- Protected ---  */

bool ClapTrap::canPerformAction(const std::string &action)
{
	if(this->_health == 0) 
	{
		std::cout << this->getTrapType() << " \"" << this->_name << " \" can't "
				<< action << ". He's dead!" << std::endl;
		return (false);
	}
	else if (this->_energy == 0) 
	{
		std::cout << this->getTrapType() << " \"" << this->_name << "\" can't "
				<< action << " due to lack of energy!" << std::endl;
		return (false);
	}
	return (true);
}

std::string ClapTrap::getTrapType() const
{
	return ("ClapTrap");
}
