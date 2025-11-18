#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	public:
		Harl();
		~Harl(){};

		void filterHarl(const std::string &level);

	private:
		static const std::string _levels[4];
		void (Harl::*_comments[4])(void);

		int	getLevel(const std::string &level);

		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif
