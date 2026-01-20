# include "ScalarConverter.hpp"
# include <cstdlib>
# include <climits>
# include <cfloat>

ScalarConverter::ScalarConverter()
{
	//	Class cant be instatiable
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	//	Class cant be instatiable
	(void)obj;
}

ScalarConverter::~ScalarConverter()
{
	//	Class cant be instatiable
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &obj)
{
	//	Class cant be instatiable
	(void)obj;
	return (*this);
}

void ScalarConverter::convert(std::string str)
{
	t_type_flag type = parse_type(str);
	switch (type)
	{
		case INVALID:
			std::cerr << "Error: Invalid input" << std::endl;
			break ;
		case CHAR:
			convert_char(str);
			break ;
		case INT:
			convert_int(str);
			break ;
		case FLOAT:
			convert_float_double(str);
			break ;
		case DOUBLE:
			convert_float_double(str);
			break ;
		case PSEUDO:
			convert_pseudo(str);
			break ;
	}
}
