# include "PhoneBook.hpp"

void	print_options(void)
{
	std::cout << "Choose one of this options:\n";
	std::cout << "	- \"ADD\"		-> To add new contact\n";
	std::cout << "	- \"SEARCH\"	-> To get one of the contact's information\n";
	std::cout << "	- \"EXIT\"	-> To exit from the program\n";
	std::cout << "** dont forget to write in CAPS LOCK and no extra characters **" << std::endl;
	std::cout << "\nyellow_pages -> ";
}

bool	apply_options(PhoneBook &yellowpages, std::string &input)
{
	if (input == "EXIT")
		return (0);
	else if (input == "ADD")
	{
		std::cout << "\n** Adding a contact **\n";
		if (!yellowpages.add_contact())
			return (false);
		std::cout << "\n** Contact added to the yellow book **" << std::endl;
	}
	else if (input == "SEARCH")
	{
		yellowpages.print_yellowbook();
		if (!yellowpages.choose_contact())
			return (false);
	}
	else
		std::cout << "## Invalid Command ##\n";
	std::cout << std::endl;
	return (true);
}

int	main(void)
{
	PhoneBook 	yellowpages;	
	std::string	input;

	std::cout << "** YELLOW PAGES **\n" << std::endl;
	while (1)
	{
		print_options();
		if (!ft_getline(std::cin, input))	
			return (1);
		if (!apply_options(yellowpages, input))
			return (1);
	}
	return (0);
}
