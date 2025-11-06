#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <sys/stat.h>

class Sed
{
	public:
		Sed(const std::string &file);
		~Sed(){};

		bool sedReplace(const std::string replaceStr, const std::string newStr);

	private:
		std::string _fileOriginal;
		std::string _fileReplace;
};

#endif
