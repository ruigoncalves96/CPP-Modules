# include "Array.hpp"
# include <iostream>

int main(void)
{
	std::cout << "|| Default constructor && access len 0 ||\n\n";
	{
		Array<int> i_array;
		std::cout << "Array len = " << i_array.len() << "\n";
		try {
			std::cout << "array[0] = " << i_array[0] << "\n";
		}
		catch (std::exception &e) { std::cerr << e.what() << "\n"; }
	}
	std::cout << "\n|| --- --- --- --- --- ||\n\n";
	std::cout << "|| Size Array constructor && operator[] ||\n\n";
	{
		Array<int> i_array(5);
		i_array[0] = 0;
		i_array[1] = 1;
		i_array[2] = 2;
		i_array[3] = 3;
		i_array[4] = 4;
		for (size_t i = 0; i < i_array.len(); i++)
			std::cout << "array[" << i << "] = " << i_array[i] << " \n";
		std::cout << "\n";
		try {
			std::cout << "Trying to access array out of bounds -> 'i_array[6] = 100'\n";
			i_array[6] = 100;
		}
		catch (std::exception &e) { std::cerr << e.what() << "\n\n"; }
	}
	std::cout << "\n|| --- --- --- --- --- ||\n\n";
	std::cout << "|| Copy constructor && operator= ||\n\n";
	{
		//	Main Array
		Array<int> i_array(5);
		i_array[0] = 0;
		i_array[1] = 1;
		i_array[2] = 2;
		i_array[3] = 3;
		i_array[4] = 4;
		std::cout << "Array len = " << i_array.len() << "\n";
		for (size_t i = 0; i < i_array.len(); i++)
			std::cout << "array[" << i << "] = " << i_array[i] << " \n";
		std::cout << "\n";
		
		//	Copy constructor
		Array<int> i_copy_array(i_array);
		std::cout << "Copy array len = " << i_copy_array.len() << "\n";
		for (size_t i = 0; i < i_copy_array.len(); i++)
			std::cout << "copy_array[" << i << "] = " << i_copy_array[i] << " \n";
		std::cout << "\n";

		//	Changing main array
		i_array[0] = 42;
		std::cout << "Changed -> array[0] = 42\n\n";

		//	Print main array
		for (size_t i = 0; i < i_array.len(); i++)
			std::cout << "array[" << i << "] = " << i_array[i] << " \n";
		std::cout << "\n";

		//	Print copy array
		std::cout << "Copy array len = " << i_copy_array.len() << "\n";
		for (size_t i = 0; i < i_copy_array.len(); i++)
			std::cout << "copy_array[" << i << "] = " << i_copy_array[i] << " \n";
		std::cout << "\n";

		//	Copy assignment 
		i_copy_array = i_array;
		std::cout << "Copy array len = " << i_copy_array.len() << "\n";
		for (size_t i = 0; i < i_copy_array.len(); i++)
			std::cout << "copy_array[" << i << "] = " << i_copy_array[i] << " \n";
		std::cout << "\n";

	}
	std::cout << "\n|| --- --- --- --- --- ||\n\n";
	std::cout << "|| Array of strings ||\n\n";
	{
		Array<std::string> str_array(5);
		str_array[0] = "this";
		str_array[1] = "array";
		str_array[2] = "has";
		str_array[3] = "five";
		str_array[4] = "words";
		for (size_t i = 0; i < str_array.len(); i++)
			std::cout << "str_array[" << i << "] = " << str_array[i] << " \n";
		std::cout << "\n";
	}
	std::cout << "\n|| --- --- --- --- --- ||\n\n";

	return (0);
}