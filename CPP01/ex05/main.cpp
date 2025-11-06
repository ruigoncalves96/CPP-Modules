# include "Harl.hpp"

int	main(void)
{
	Harl annoyingHarl;

	annoyingHarl.complain("DEBUG");
	std::cout << std::endl;
	annoyingHarl.complain("INFO");
	std::cout << std::endl;
	annoyingHarl.complain("WARNING");
	std::cout << std::endl;
	annoyingHarl.complain("ERROR");
	std::cout << std::endl;
	annoyingHarl.complain("Es lindo");
	std::cout << std::endl;

	return (0);
}
