# include <iostream>
# include <cctype>
# include <string>

void	log(const std::string &message)
{
	std::cout << message;
}

bool	has_message(int argc, char **argv)
{
	if (argc == 1)
		return (false);
	for (int i = 1; i != argc; i++)
	{
		if (argv[i][0] != '\0')
			return (true);
	}
	return (false);
}

const std::string to_upper_message(const std::string &arg)
{
	std::string message = arg;

	for (std::string::size_type i = 0; i < message.size(); i++)
		message[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(arg[i])));
	return (message);
}

int main(int argc, char **argv)
{
	if (!has_message(argc, argv))
	{
		log("* LOUD AND UNBEARABLE FEEDBACK NOISE *\n");
		return 0;
	}
	for (int i = 1; argv[i]; i++)
		log(to_upper_message(argv[i]));
	log("\n");
	return (0);
}
