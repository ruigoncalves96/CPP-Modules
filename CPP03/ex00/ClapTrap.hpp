#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string &name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();

		ClapTrap& operator=(const ClapTrap&copy);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string		_name;
		unsigned int	_health;
		unsigned int	_energy;
		unsigned int	_attackDamage;
};

#endif