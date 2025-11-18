# include "Harl.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Invalid input!" << std::endl;
		return (1);
	}

	Harl annoyingHarl;
	annoyingHarl.filterHarl(argv[1]);

	return (0);
}
