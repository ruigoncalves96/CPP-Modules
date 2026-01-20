#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

typedef enum e_type_flag
{
	INVALID,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO
} 			t_type_flag;

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

// Helper function declarations
t_type_flag parse_type(std::string &str);
void convert_char(std::string &str);
void convert_int(std::string &str);
void convert_float_double(std::string &str);
void convert_pseudo(std::string &str);

#endif