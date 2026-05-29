# include "TypeUtils.hpp"
# include <cstdlib>
# include <climits>
# include <cfloat>
# include <iomanip>
# include <cerrno>
# include <cctype>

TypeUtils::TypeUtils()
{
	//	Class cant be instatiable
}

TypeUtils::TypeUtils(const TypeUtils &obj)
{
	//	Class cant be instatiable
	(void)obj;
}

TypeUtils::~TypeUtils()
{
	//	Class cant be instatiable
}

TypeUtils& TypeUtils::operator=(const TypeUtils &obj)
{
	//	Class cant be instatiable
	(void)obj;
	return (*this);
}


//	|| ----- PARSING ----- ||

t_type_flag TypeUtils::parse(std::string &str)
{
	if (str.empty())
		return (INVALID);
	if (parse_char(str))	
		return (CHAR);
	if (parse_pseudo(str))	
		return (PSEUDO);
	if (parse_numeric(str))
	{
		if (parse_int(str))	return (INT);
		if (str.find('.') != std::string::npos)
		{
			if (str.find('f') != std::string::npos) return (FLOAT);
			else return (DOUBLE);
		}
	}
	return (INVALID);
}

bool TypeUtils::parse_char(std::string &str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (true);
	return (false);
}

bool TypeUtils::parse_numeric(std::string &str)
{
	if (str.find_first_not_of("-0123456789.f") == std::string::npos)
	{
		if (str.find('-') != std::string::npos)
		{
			if (!parse_dup_char(str, '-')) return (false);
			if (str.find('-') != 0) return (false);
		}
		if (str.find('.') != std::string::npos)
		{
			if (!parse_dup_char(str, '.')) return (false);
			if (!parse_decimal_point(str, str.find('.'))) return (false);
		}
		if (str.find('f') != std::string::npos)
		{
			if (!parse_dup_char(str, 'f')) return (false);
			if (str.find('f') != str.length() - 1) return (false);
		}
		return (true);
	}
	return (false);
}

bool TypeUtils::parse_int(std::string &str)
{
	if (str.find_first_not_of("-0123456789") == std::string::npos)
		return (true);
	return (false);
}

bool TypeUtils::parse_pseudo(std::string &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf"
		|| str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	return (false);
}
//	|| ----- ----- ||

//	|| ----- CONVERTING ----- ||

void TypeUtils::convert_char(std::string &str)
{
	char c = str[0];
	//	CHAR CONVERT
	std::cout << "char: '" << static_cast <char> (c) << "\'" << std::endl;
	//	INT CONVERT
	std::cout << "int: " << static_cast <int> (c) << std::endl;
	//	FLOAT CONVERT
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast <float> (c) << 'f' << std::endl;
	//	DOUBLE CONVERT
	std::cout << "double: " << static_cast <double> (c) << std::endl;
}

void TypeUtils::convert_int(std::string &str)
{
	char *end;
	errno = 0;
	long to_long = strtol(str.c_str(), &end, 10);
	if (errno == ERANGE)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	//	CHAR CONVERT
	if (to_long < 0 || to_long > 255)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast <int> (to_long)))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast <char> (to_long) << "\'" << std::endl;

	//	INT CONVERT
	if (to_long > INT_MAX || to_long < INT_MIN)	
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast <int> (to_long) << std::endl;
		
	//	FORMAT DECIMAL POINT
	std::cout << std::fixed << std::setprecision(1);

	// FLOAT CONVERT
	if (to_long > FLT_MAX || to_long < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast <float> (to_long) << 'f' << std::endl;

	// DOUBLE CONVERT
	std::cout << "double: " << static_cast <double> (to_long) << std::endl;
}

void TypeUtils::convert_float_double(std::string &str)
{
	char *end;
	errno = 0;
	double to_double = strtod(str.c_str(), &end);
	if (errno == ERANGE)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	//	CHAR CONVERT
	if (to_double < 0 || to_double > 255)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast <int> (to_double)))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast <char> (to_double) << "\'" << std::endl;

	//	INT CONVERT
	if (to_double > INT_MAX || to_double < INT_MIN)	
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast <int> (to_double) << std::endl;
	
	std::cout << std::fixed << std::setprecision(1);

	// FLOAT CONVERT
	if (to_double > FLT_MAX || to_double < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast <float> (to_double) << 'f' << std::endl;

	// DOUBLE CONVERT
	std::cout << "double: " << to_double << std::endl;
}

void TypeUtils::convert_pseudo(std::string &str)
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

// || ----- Utilities ----- ||

bool TypeUtils::parse_dup_char(std::string &str, char c)
{
	return (str.find_first_of(c) == str.find_last_of(c));
}

bool TypeUtils::parse_decimal_point(std::string &str, size_t pos)
{
	if (pos == 0 || str[pos + 1] == '\0') 
		return (false);
	if (!std::isdigit(str[pos - 1]) || !std::isdigit(str[pos + 1]))
		return (false);
	return (true);
}
