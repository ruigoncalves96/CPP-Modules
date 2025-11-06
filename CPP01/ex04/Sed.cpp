# include "Sed.hpp"

Sed::Sed(const std::string &file)
{
	this->_fileOriginal = file;
	std::string::size_type find = file.find("/");
	if (find != std::string::npos)
		this->_fileReplace = file.substr(find + 1);
	else
		this->_fileReplace = file;
	find = this->_fileReplace.find_last_of(".");
	if (find != std::string::npos)
		this->_fileReplace.erase(find);
	this->_fileReplace += ".replace";
}

//	------	//

static bool isDirectory(const std::string &path)
{
	struct stat pathStat;

	if (stat(path.c_str(), &pathStat) != 0)
		return (false);

	return (S_ISDIR(pathStat.st_mode));
}

static bool	openFiles(std::ifstream &fileOriginal, std::ofstream &fileReplace,
					const std::string &_fileOriginal, const std::string &_fileReplace)
{
	fileOriginal.open(_fileOriginal.c_str());
	if (!fileOriginal.is_open() || isDirectory(_fileOriginal))
	{
		std::cerr << "Error opening file - '" << _fileOriginal << "'.\n";
		return (false);
	}
	fileReplace.open(_fileReplace.c_str());
	if (!fileReplace.is_open())
	{
		std::cerr << "Error creating file - '" << _fileReplace << "'.\n";
		fileOriginal.close();
		return (false);
	}
	return (true);
}

bool Sed::sedReplace(const std::string replaceStr, const std::string newStr)
{
	if (replaceStr.empty() || newStr.empty())
	{
		std::cerr << "Empty string to sedReplace\n";
		return (false);
	}
	std::ifstream fileOriginal;
	std::ofstream fileReplace;
	if (!openFiles(fileOriginal, fileReplace, this->_fileOriginal, this->_fileReplace))
		return (false);
	std::string newLine;
	std::string::size_type replaceStr_size = replaceStr.length();
	while (std::getline(fileOriginal, newLine))
	{
		std::string::size_type strPosition = 0;
		while ((strPosition = newLine.find(replaceStr, strPosition)) != std::string::npos)
		{
			newLine.erase(strPosition, replaceStr_size);
			newLine.insert(strPosition, newStr);
			strPosition += replaceStr_size;
		}
		fileReplace << newLine << std::endl;
	}
	return (true);
}
