# include "Harl.hpp"

//	Public member funcitons

Harl::Harl(void)
{
	this->_levels[0] = "DEBUG";
	this->_levels[1] = "INFO";
	this->_levels[2] = "WARNING";
	this->_levels[3] = "ERROR";
}

void Harl::complain(std::string level)
{
	void (Harl::*comments[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	for (int i = 0; i < 4; i++)
	{
		if (level == this->_levels[i])
		{
			(this->*comments[i])();
			return ;
		}
	}
	std::cout << "\n[ Probably complaining about insignificant problems ]\n";
}

int Harl::getLevel(const std::string &level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == this->_levels[i])
			return (i + 1);
	}
	return (0);
}

//	Private member functions 

void Harl::debug(void)
{
	std::cout << "\n[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
				<< "I really do!\n";
}

void Harl::info(void)
{
	std::cout << "\n[ INFO ]\n";
	std::cout <<  "I cannot believe adding extra bacon costs more money.\n"
				<< "You didn’t put enough bacon in my burger!\n"
				<< "If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void)
{
	std::cout << "\n[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\n"
				<< "I’ve been coming for years, whereas you started working here just last month.\n";
}

void Harl::error(void)
{
	std::cout << "\n[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
