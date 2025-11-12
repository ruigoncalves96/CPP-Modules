# include "Zombie.hpp"

# define HORDE_SIZE 10

Zombie* zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie *zombie = zombieHorde(HORDE_SIZE, "Alfredo");

	for (int i = 0; i < HORDE_SIZE; i++)
		zombie[i].announce();
	delete[] zombie;
	return (0);
}
