# include "ScalarConverter.hpp"
# include "TypeUtils.hpp"
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
	t_type_flag type = TypeUtils::parse(str);
	switch (type)
	{
		case INVALID:
			std::cerr << "Error: Invalid input" << std::endl; break ;
		case CHAR:
			TypeUtils::convert_char(str); break ;
		case INT:
			TypeUtils::convert_int(str); break ;
		case FLOAT:
			TypeUtils::convert_float_double(str); break ;
		case DOUBLE:
			TypeUtils::convert_float_double(str); break ;
		case PSEUDO:
			TypeUtils::convert_pseudo(str); break ;
	}
}
