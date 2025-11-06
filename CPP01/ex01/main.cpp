# include "Zombie.hpp"

# define HORDE_SIZE 10

Zombie* zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie *zombie = zombieHorde(HORDE_SIZE, "Alfredo");
	if (!zombie)
		return (1);
	delete[] zombie;
	return (0);
}
