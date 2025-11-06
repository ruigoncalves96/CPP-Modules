# include <iostream>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Adresses:\n";
	std::cout << "- string address -> " << &string << "\n";
	std::cout << "- string pointer -> " << stringPTR << "\n";
	std::cout << "- string reference -> " << &stringREF << "\n";

	std::cout << "Values:\n";
	std::cout << "- string value -> " << string << "\n";
	std::cout << "- string pointer value -> " << *stringPTR << "\n";
	std::cout << "- string reference value -> " << string << "\n";
	
}
