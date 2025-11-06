# include "Harl.hpp"

void filterHarl(Harl &annoyingHarl, const std::string level)
{
	int levelCase = annoyingHarl.getLevel(level);
	switch (levelCase) {
		case 1:
			annoyingHarl.complain("DEBUG");
			/* fall through */
		case 2:
			annoyingHarl.complain("INFO");
			/* fall through */
		case 3:
			annoyingHarl.complain("WARNING");
			/* fall through */
		case 4:
			annoyingHarl.complain("ERROR");
			break ; 
		default:
			annoyingHarl.complain("Es lindo");
	}
	std::cout << std::endl;
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Invalid input!" << std::endl;
		return (1);
	}

	Harl annoyingHarl;
	filterHarl(annoyingHarl, argv[1]);

	return (0);
}
