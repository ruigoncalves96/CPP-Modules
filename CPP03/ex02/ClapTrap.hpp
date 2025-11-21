#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &copy);
		virtual ~ClapTrap();

		ClapTrap& operator=(const ClapTrap&copy);

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		std::string	_name;
		int			_health;
		int			_energy;
		int			_attackDamage;
	
		bool canPerformAction(const std::string &action);
		virtual std::string getTrapType() const;
	
};

#endif