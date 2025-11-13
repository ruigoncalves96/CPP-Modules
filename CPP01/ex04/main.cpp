# include "Sed.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4 || argv[1][0] == '\0')
	{
		std::cerr << "Invalid input!" << std::endl;		
		return (1);
	}

	if (Sed::replace(argv[1], argv[2], argv[3]))
		return (1);

	return (0);	
}
