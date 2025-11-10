#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &copy);
		~ScavTrap();

		ScavTrap& operator=(const ScavTrap&copy);

		void attack(const std::string& target);
		void guardGate(void);

	private :
		std::string getTrapType() const;

};

#endif