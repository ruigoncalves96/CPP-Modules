# include "ClapTrap.hpp"

/*	--- Public ---  */

//	--- Constructors and Destructors ---  //
ClapTrap::ClapTrap()
	: _health(10), _energy(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called (no name inserted)." << std::endl;
}

ClapTrap::ClapTrap(std::string &name)
	: _name(name), _health(10), _energy(10), _attackDamage(0)
{
	std::cout << "ClapTrap \"" << name << "\" was created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap \"" << copy._name << "\" was cloned." << std::endl;
	*this = copy;
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
	if(this->_energy == 0) 
	{
		std::cout << "ClapTrap " << this->_name << "can't attack due to lack of energy!"
				<< std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
			<< this->_attackDamage << " points of damage!\n";
	std::cout << "Current energy: " << this->_energy << std::endl;
	this->_energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_health -= amount; 
	if (this->_health < -1)
		this->_health = 0;
	std::cout << "ClapTrap " << this->_name << " took " << amount << "amount of damage!\n";
	std::cout << "Current health: " << this->_health << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy == 0)
	{
		std::cout << "ClapTrap " << this->_name << "can't repair due to lack of energy!"
				<< std::endl;
		return ;
	}
	this->_health += amount;
	if (this->_health > 10)
		this->_health = 10;
	this->_energy--;
	std::cout << "ClapTrap " << this->_name << " repaired " << amount << "amount of health!\n";
	std::cout << "Current health: " << this->_health << "\n";
	std::cout << "Current energy: " << this->_energy << std::endl;
}
//	------  //

/*	--- Private ---  */

//	EMPTY
