# include "Sed.hpp"

static bool isDirectory(const std::string &path)
{
	struct stat pathStat;

	if (stat(path.c_str(), &pathStat) != 0)
		return (false);

	return (S_ISDIR(pathStat.st_mode));
}

static std::string createOutputFile(const std::string &inputPath)
{
	std::string baseStr = inputPath;
	std::string::size_type find = baseStr.find("/");
	if (find != std::string::npos)
		baseStr = inputPath.substr(find + 1);

	find = baseStr.find_last_of(".");
	if (find != std::string::npos)
		baseStr.erase(find);
	baseStr += ".replace";

	return (baseStr);
}

static bool	openFiles(std::ifstream &in, std::ofstream &out,
					const std::string &_inputPath, const std::string &_outputFile)
{
	if (isDirectory(_inputPath))
	{
		std::cerr << "Error: '" << _inputPath << "' is a directory.\n";
		return (false);
	}
	in.open(_inputPath.c_str());
	if (!in.is_open())
	{
		std::cerr << "Error opening file - '" << _inputPath << "'.\n";
		return (false);
	}
	out.open(_outputFile.c_str());
	if (!out.is_open())
	{
		std::cerr << "Error creating file - '" << _outputFile << "'.\n";
		in.close();
		return (false);
	}
	return (true);
}

bool Sed::replace(const std::string &inputPath, const std::string &replaceStr, const std::string &newStr)
{
	if (replaceStr.empty() || newStr.empty())
	{
		std::cerr << "Empty string to sedReplace\n";
		return (false);
	}

	const std::string outputFile = createOutputFile(inputPath);
	std::ifstream in;
	std::ofstream out;
	if (!openFiles(in, out, inputPath, outputFile))
		return (false);

	std::string newLine;
	if (replaceStr == newStr)
	{
		while (std::getline(in, newLine))
			out << newLine << '\n';
		return (true);
	}
	std::string::size_type replaceStr_size = replaceStr.length();
	while (std::getline(in, newLine))
	{
		std::string::size_type strPosition = 0;
		while ((strPosition = newLine.find(replaceStr, strPosition)) != std::string::npos)
		{
			newLine.erase(strPosition, replaceStr_size);
			newLine.insert(strPosition, newStr);
			strPosition += replaceStr_size;
		}
		out << newLine << '\n';
	}
	return (true);
}
