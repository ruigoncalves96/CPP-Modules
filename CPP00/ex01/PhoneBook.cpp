# include "PhoneBook.hpp"
# include <sstream>

bool PhoneBook::add_contact(void)
{
	Contact new_contact;

	if (!new_contact.get_contact_info())
		return (false);
	new_contact.index = this->_next_index_to_fill;
	this->_contacts[_next_index_to_fill] = new_contact;
	this->_next_index_to_fill++;
	if (this->_next_index_to_fill == 8)
		this->_next_index_to_fill = 0;
	if (this->_nbr_of_contacts < 8)
		this->_nbr_of_contacts++;
	return (true);
}

// ------ //

static std::string trunc_string(const std::string &string)
{
	if (string.length() > 10)
		return (string.substr(0, 9) + ".");
	return (string);
}

void PhoneBook::print_yellowbook(void)
{
	std::cout << "\n	    ** YELLOW BOOK CONTACTS **\n";
	std::cout << std::setw(10) << std::right << "Index";
	std::cout << " | ";
	std::cout << std::setw(10) << std::right << "First Name";
	std::cout << " | ";
	std::cout << std::setw(10) << std::right << "Last Name";
	std::cout << " | ";
	std::cout << std::setw(10) << std::right << "Nickname" << std::endl;

	for (int i = 0; i < this->_nbr_of_contacts; i++)
	{
		std::cout << std::setw(10) << std::right << this->_contacts[i].index + 1 << " | ";
		std::cout << std::setw(10) << std::right << trunc_string(this->_contacts[i].get_first_name()) << " | ";
		std::cout << std::setw(10) << std::right << trunc_string(this->_contacts[i].get_last_name()) << " | ";
		std::cout << std::setw(10) << std::right << trunc_string(this->_contacts[i].get_nickname()) << std::endl;
	}
	std::cout << "	  // ------------------------ \\\\ \n";
	std::cout << "** Choose a index to print the Contact information **\n"; 
	std::cout << "	   ** Or '0' to exit search **" << std::endl;
}

// ----- //

static bool parse_index_input(std::string &input)
{
	if (input.empty() || input.length() > 1
			|| input.find_last_not_of("0123456789") != std::string::npos)
		return (false);
	return (true);
}

static int ft_stoi(const std::string &string)
{
	int value = 0;
	std::stringstream ss(string);
	if (!(ss >> value))
	{
		std::cerr << "\n## Error converting the number. ##" << std::endl;
		return (-1);
	}
	return (value);
}

bool PhoneBook::choose_contact(void)
{
	while (1)
	{
		std::cout << "\nIndex to print Contact: ";
		std::string input;
		if (!ft_getline(std::cin, input))
			return (false);
		if (!parse_index_input(input))
			std::cout << "\n## Invalid Input. Please enter a valid number (min 1 & max 8). ##" << std::endl;
		else
		{
			int index = ft_stoi(input);
			if (index < 0 || index > this->_nbr_of_contacts)
				std::cout << "\n## No contact in index: " << index << ". Please enter a valid number. ##" << std::endl;
			else
			{
				if (index == 0)
				{
					std::cout << "** exited from SEARCH **" << std::endl;
					return (true);
				}
				this->_contacts[index - 1].print_contact_info();
				return (true);
			}
		}
	}
}
