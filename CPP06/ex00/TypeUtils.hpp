#ifndef TYPEUTILS_HPP
# define TYPEUTILS_HPP

# include <iostream>

# include "TypeFlag.hpp"

class TypeUtils
{
	public:
		static t_type_flag parse(std::string &str);

		//	Converting
		static void convert_char(std::string &str);
		static void convert_int(std::string &str);
		static void convert_float_double(std::string &str);
		static void convert_pseudo(std::string &str);

	private:
		TypeUtils();
		TypeUtils(const TypeUtils&);
		~TypeUtils();

		TypeUtils& operator=(const TypeUtils&);

		//	Parsing
		static bool parse_char(std::string &str);
		static bool parse_int(std::string &str);
		static bool parse_pseudo(std::string &str);
		static bool parse_numeric(std::string &str);

		//	Utilities
		static bool parse_dup_char(std::string &str, char c);
		static bool parse_decimal_point(std::string &str, size_t pos);
};

#endif