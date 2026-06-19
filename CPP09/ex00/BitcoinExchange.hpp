#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <exception>
#include <map>

#define DATA_FILE_PATH "data.csv"

typedef struct s_data
{
	s_data() : date(), value(0) {};

	std::string date;
	float		value;
}	t_data;

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();

		void printConversion(const std::string &filePath);

	private:
		BitcoinExchange(const BitcoinExchange &);
		BitcoinExchange& operator=(const BitcoinExchange &);

		//	Data File methods
		void importDataBase(void);
		t_data extractDataLine(const std::string &buffer) const;

		//	Input File methods
		t_data extractInputLine(const std::string &buffer) const;
		float exchangeBitcoin(const std::string &date, const float value);
		
		//	Parsing helpers
		static void parseSeparator(const std::string &buffer, const std::string &separator, size_t formatMinLen, size_t pos);
		static std::string parseDate(const std::string &date);
		static float parseValue(const std::string &value, float maxRange);

		//	Utilities
		static bool isLeapYear(int year);
		static bool isNotDuplicated(const std::string &str, const char c);
		static bool isFileEmpty(std::ifstream &file, std::string &buffer);
		static void hasInvalidChar(const std::string &str, const std::string &chars);

		std::map<std::string, float>	_data;
};

template <typename T>
T stringToNumber(const std::string &str)
{
	std::stringstream ss(str);	
	T out_number;

	ss >> out_number;
	if (ss.fail() || !ss.eof())
		throw std::runtime_error("Invalid Number convertion");
	
	return (out_number);
}

template <typename T>
std::string varToString(const T var)
{
	std::stringstream ss;	
	ss << var;
	if (ss.fail())
		throw std::runtime_error("Invalid Variable conversion");
	
	return (ss.str());
}

#endif
