# include "ScalarConverter.hpp"
# include <cstdlib>
# include <climits>
# include <cfloat>

// || ----- Convertion to type ----- ||

void convert_char(std::string &str)
{
	char c = str[0];
	//	CHAR CONVERT
	std::cout << "char: '" << static_cast <char> (c) << "\'" << std::endl;
	//	INT CONVERT
	std::cout << "int: " << static_cast <int> (c) << std::endl;
	//	FLOAT CONVERT
	std::cout << "float: " << static_cast <float> (c) << 'f' << std::endl;
	//	DOUBLE CONVERT
	std::cout << "double: " << static_cast <double> (c) << std::endl;
}

void convert_int(std::string &str)
{
	char *end;
	long to_long = strtol(str.c_str(), &end, 10);

	//	CHAR CONVERT
	if (to_long < 0 || to_long > 255)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast <int> (to_long)))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast <char> (to_long) << "\'" << std::endl;

	//	INT CONVERT
	if (to_long > INT_MAX || to_long < INT_MIN)	
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast <int> (to_long) << std::endl;
	
	// FLOAT CONVERT
	if (to_long > FLT_MAX || to_long < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast <float> (to_long) << 'f' << std::endl;

	// DOUBLE CONVERT
	if (to_long > DBL_MAX || to_long < -DBL_MAX)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << static_cast <double> (to_long) << std::endl;
}

void convert_float_double(std::string &str)
{
	char *end;
	double to_double = strtod(str.c_str(), &end);

	//	CHAR CONVERT
	if (to_double < 0 || to_double > 255)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast <int> (to_double)))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast <char> (to_double) << "\'" << std::endl;

	//	INT CONVERT
	if (to_double > INT_MAX || to_double < INT_MIN)	
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast <int> (to_double) << std::endl;
	
	// FLOAT CONVERT
	if (to_double > FLT_MAX || to_double < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast <float> (to_double) << 'f' << std::endl;

	// DOUBLE CONVERT
	if (to_double > DBL_MAX || to_double < -DBL_MAX)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << to_double << std::endl;
}

void convert_pseudo(std::string &str)
{
	//	CHAR CONVERT
	std::cout << "char: impossible" << std::endl;
	//	INT CONVERT
	std::cout << "int: impossible" << std::endl;
	//	FLOAT CONVERT
	if (str == "-inff" || str == "+inff" || str == "nanf")
		std::cout << "float: " << str << std::endl;
	else
		std::cout << "float: " << str << 'f' << std::endl;
	//	DOUBLE CONVERT
	if (str == "-inf" || str == "+inf" || str == "nan")
		std::cout << "double: " << str << std::endl;
	else
		std::cout << "double: " << str.erase(str.length() - 1) << std::endl;
}

//	|| ----- ----- ||
