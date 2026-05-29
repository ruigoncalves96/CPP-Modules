#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	public:
		static void convert(std::string arg);
	
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		~ScalarConverter();

		ScalarConverter& operator=(const ScalarConverter&);
};

#endif