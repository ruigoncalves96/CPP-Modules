# include "yellowpages.hpp"

bool ft_getline(std::istream &in, std::string &buffer)
{
	if (!std::getline(in, buffer))
	{
		if (in.eof())
		{
			std::cout << "\n\n## EXITED ##" << std::endl;
			return (false);
		}
	}
	return (true);
}
