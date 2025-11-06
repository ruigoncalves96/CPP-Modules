#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	public:
		Harl();
		~Harl(){};

		void complain(std::string level);
		int getLevel(const std::string &level);

	private:
		std::string _levels[4];

		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif
