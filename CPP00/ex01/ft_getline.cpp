# include "yellowpages.hpp"

bool ft_getline(std::istream &in, std::string &buffer)
{
	if (!std::getline(in, buffer))
	{
		if (std::cin.eof())
		{
			std::cout << "\n\n## EXITED ##" << std::endl;
			return (false);
		}
	}
	return (true);
}
