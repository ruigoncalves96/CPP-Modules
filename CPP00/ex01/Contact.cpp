# include "Contact.hpp"

static bool parse_info_input(std::string &input)
{
	if (input.empty() || input.find_first_of("\t") != std::string::npos)
		return (false);
	return (true);
}

static bool parse_phone_number(std::string &input)
{
	if (input.empty() || input.find_last_not_of("+0123456789") != std::string::npos)
		return (false);
	return (true);
}

static bool get_info_line(const std::string &param, std::string &input)
{
	bool	is_phone_number = param == "Phone Number: ";
	while (1)
	{
		std::cout << param;
		if (!ft_getline(std::cin, input))
			return (false);
		if (is_phone_number && !parse_phone_number(input))
			std::cout << "\n## Invalid input (only digits and '+' accepted). Try again. ##\n";
		else if (!is_phone_number && !parse_info_input(input))
			std::cout << "\n## Invalid input. Try again. ##" << std::endl;
		else
			return (true);
	}
}

bool Contact::get_contact_info(void)
{
	if (get_info_line("First name: ", this->_first_name)
			&& get_info_line("Last name: ", this->_last_name)
			&& get_info_line("Nickname: ", this->_nickname)
			&& get_info_line("Phone Number: ", this->_phone_number)
			&& get_info_line("Darkest secret: ", this->_darkest_secret))
		return (true);
	return(false);
}

// ----- //

void Contact::print_contact_info(void)
{
	std::cout << std::endl;

	std::cout << "** " << this->_first_name << " " << this->_last_name << " **\n";
	std::cout << "First name -> " << this->_first_name << "\n";
	std::cout << "Last name -> " << this->_last_name << "\n";
	std::cout << "Nickname -> " << this->_nickname << "\n";
	std::cout << "Phone number -> " << this->_phone_number << "\n";
	std::cout << "Darkest secret -> " << this->_darkest_secret << std::endl;
}

// ----- //

const std::string& Contact::get_first_name(void) const
{
	return (this->_first_name);
}

const std::string& Contact::get_last_name(void) const
{
	return (this->_last_name);
}

const std::string& Contact::get_nickname(void) const
{
	return (this->_nickname);
}
