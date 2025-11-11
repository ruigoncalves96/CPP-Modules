#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string name);
		FragTrap(const FragTrap &copy);
		~FragTrap();

		FragTrap& operator=(const FragTrap&copy);

		void highFivesGuys(void);

	protected:
		enum { kDefHealth = 100, kDefEnergy = 100, kDefAttackDamage = 30 };

	private :
		std::string getTrapType() const;

};

#endif