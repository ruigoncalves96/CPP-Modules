# include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Error: Wrong number of arguments.\nFormat -> ./Converter [arg]" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
}
