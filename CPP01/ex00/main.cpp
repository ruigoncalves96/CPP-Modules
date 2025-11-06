# include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int	main(void)
{
	Zombie *zombie = newZombie("Jack");
	zombie->announce();
	randomChump("Mike");
	delete(zombie);
	return (0);
}
