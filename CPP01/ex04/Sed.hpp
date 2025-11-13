#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <sys/stat.h>

class Sed
{
	public:
		static bool replace(const std::string &inputPath,
							const std::string &replaceStr,
							const std::string &newStr);

	private:
		Sed(){};
		Sed(const Sed &){};
		~Sed(){};
};

#endif
