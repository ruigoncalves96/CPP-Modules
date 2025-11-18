# include "Harl.hpp"

const std::string Harl::_levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

//	Public member funcitons

Harl::Harl()
{
	_comments[0] = &Harl::debug;
	_comments[1] = &Harl::info;
	_comments[2] = &Harl::warning;
	_comments[3] = &Harl::error;
}

void Harl::filterHarl(const std::string &level)
{
	int levelCase = this->getLevel(level);
	switch (levelCase) {
		case 1: // DEBUG
			this->debug();
			/* fall through */
		case 2: // INFO
			this->info();
			/* fall through */
		case 3: // WARNING
			this->warning();
			/* fall through */
		case 4: // ERROR
			this->error();
			break ; 
		default:
			std::cout << "\n[ Probably complaining about insignificant problems ]\n";
	}
	std::cout << std::endl;
}

//	Private member functions 

int Harl::getLevel(const std::string &level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == this->_levels[i])
			return (i + 1);
	}
	return (0);
}

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
