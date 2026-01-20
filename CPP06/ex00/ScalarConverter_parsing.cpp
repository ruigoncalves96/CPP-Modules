# include "ScalarConverter.hpp"
# include <cctype>

//	|| ----- PARSING ----- ||

//	Declarations
static bool parse_dup_char(std::string &str, char c);
static bool parse_decimal_point(std::string &str, size_t pos);

static bool parse_char(std::string &str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (true);
	return (false);
}

static bool parse_int(std::string &str)
{
	if (str.find_first_not_of("-0123456789") == std::string::npos)
		return (true);
	return (false);
}

static bool parse_float(std::string &str)
{
	size_t f_pos = str.find('f');
	if (f_pos == std::string::npos || str[f_pos + 1] != '\0')
		return (false);

	size_t dot_pos = str.find('.');
	if (dot_pos == std::string::npos)
		return (false);
	if (!parse_dup_char(str, '.')) return (false);	
	if (!parse_decimal_point(str, dot_pos)) return (false);
	return (true);
}

static bool parse_double(std::string &str)
{
	size_t dot_pos = str.find('.');
	if (dot_pos == std::string::npos)
		return (false);
	if (!parse_dup_char(str, '.')) return (false);	
	if (!parse_decimal_point(str, dot_pos)) return (false);
	return (true);
}

static bool parse_pseudo(std::string &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf"
		|| str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	return (false);
}

static bool parse_numeric(std::string &str)
{
	if (str.find_first_not_of("-0123456789.f") == std::string::npos)
	{
		if (str.find_first_of("0123456789") == std::string::npos)
			return (false);
		if (str.find('-') != std::string::npos)
		{
			if (str[0] != '-') return (false);
			if (!parse_dup_char(str, '-')) return (false);
		}
		return (true);
	}
	return (false);
}

t_type_flag parse_type(std::string &str)
{
	if (str.empty())
		return (INVALID);
	if (parse_char(str))	
		return (CHAR);
	if (parse_pseudo(str))	
		return (PSEUDO);
	if (parse_numeric(str))
	{
		if (parse_int(str))	
			return (INT);
		if (str.find('f') != std::string::npos)
		{
			if (parse_float(str)) return (FLOAT);
		}
		else
			if (parse_double(str)) return (DOUBLE);
	}
	return (INVALID);
}
//	|| ----- ----- ||

// || ----- Utilities ----- ||

static bool parse_dup_char(std::string &str, char c)
{
	return (str.find_first_of(c) == str.find_last_of(c));
}

static bool parse_decimal_point(std::string &str, size_t pos)
{
	if (pos == 0 || str[pos + 1] == '\0') 
		return (false);
	if (!std::isdigit(str[pos - 1]) || !std::isdigit(str[pos + 1]))
		return (false);
	return (true);
}
//	|| ----- ----- ||
