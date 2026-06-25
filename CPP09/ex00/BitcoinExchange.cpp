#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <limits>

BitcoinExchange::BitcoinExchange() { importDataBase(); }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) { *this = obj; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
		this->_data = obj._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::printConversion(const std::string &filePath)
{
	std::ifstream inputFile;
	inputFile.open(filePath.c_str());
	if (!inputFile.is_open())
		throw std::runtime_error("Unable to open file: '" + filePath + "'");

	std::string buffer;
	if (isFileEmpty(inputFile, buffer))
		throw std::runtime_error("Empty input file.");
	if (buffer != "date | value")
		throw std::runtime_error("Wrong Format. Expecting first line as 'date | value'");

	for (size_t currentLine = 2; getline(inputFile, buffer); ++currentLine)
	{
		try {
			t_data fileLineData = extractInputLine(buffer);
			float exchangeValue = exchangeBitcoin(fileLineData.date, fileLineData.value);
			std::cout << fileLineData.date << " => " << fileLineData.value << " = " << exchangeValue << std::endl;
		}
		catch(const std::exception &e) { std::cerr << "{l." << currentLine << "}Error: " << e.what() << std::endl; }
	}
	inputFile.close();
}


//*		||---- PRIVATE METHODS ----||

void BitcoinExchange::importDataBase(void)
{
	std::ifstream data;
	data.open(DATA_FILE_PATH);
	if (!data.is_open())
		throw std::runtime_error("Unable to open data base file.");

	std::string buffer;
	if (isFileEmpty(data, buffer))
		throw std::runtime_error("Data Base - empty file.");
	if (buffer != "date,exchange_rate")
		throw std::runtime_error("Data base - invalid format. Expecting first line as 'date,exchange_rate'");

	for (size_t currentLine = 2; std::getline(data, buffer); ++currentLine)
	{
		try {
			t_data fileLineData = extractDataLine(buffer);
			_data[fileLineData.date] = fileLineData.value;
		}
		catch(const std::exception &e) { throw std::runtime_error("{l." + varToString(currentLine) + "}Data Base - " + e.what()); }
	}
	data.close();
}

t_data BitcoinExchange::extractDataLine(const std::string &buffer) const
{
	t_data data;
	if (buffer.empty())
		throw std::runtime_error("Empty line.");
	
	parseSeparator(buffer, ",", 12, 10);
	data.date = parseDate(buffer.substr(0, buffer.find(",")));
	data.value = parseValue(buffer.substr(buffer.find(",") + 1), std::numeric_limits<float>::max());
	return (data);
}

t_data BitcoinExchange::extractInputLine(const std::string &buffer) const
{
	t_data input;
	if (buffer.empty())
		throw std::runtime_error("Empty line.");

	parseSeparator(buffer, " | ", 14, 10);
	input.date = parseDate(buffer.substr(0, buffer.find("|") - 1));
	input.value = parseValue(buffer.substr(buffer.find("|") + 2), 1000);
	return (input);
}

float BitcoinExchange::exchangeBitcoin(const std::string &date, const float value)
{
	std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
	if (it == _data.end() || it->first != date)
	{
		if (it == _data.begin() && it->first != date)
			throw std::runtime_error("input value too low.");
		--it;
	}
	return (it->second * value);
}

//*		||---- PARSING HELPERS ----||

void BitcoinExchange::parseSeparator(const std::string &buffer, const std::string &separator, size_t formatMinLen, size_t pos)
{
	if (buffer.length() < formatMinLen || buffer.compare(pos, separator.length(), separator) != 0)
		throw std::runtime_error("Bad format.");
}

std::string BitcoinExchange::parseDate(const std::string &date)
{
	try { hasInvalidChar(date, "0123456789-"); }
	catch(const std::exception &e) {throw std::runtime_error("Invalid date - " + varToString(e.what()));}

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		throw std::runtime_error("Invalid date.");

	int year = stringToNumber<int>(date.substr(0, 4));
	int month = stringToNumber<int>(date.substr(5, 2));
	int day = stringToNumber<int>(date.substr(8, 2));

	if ((year < 2009) || (month < 1 || month > 12) || (day < 1 || day > 31))
		throw std::runtime_error("Invalid date.");
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw std::runtime_error("Invalid date.");
	else if (month == 2)
	{
		if (isLeapYear(year) ? day > 29 : day > 28)
			throw std::runtime_error("Invalid date.");
	}
	return (date);
}

float BitcoinExchange::parseValue(const std::string &value, float maxRange)
{
	float newValue = 0.0;
	try {
		hasInvalidChar(value, "0123456789.-");
		newValue = stringToNumber<float>(value);
	}
	catch(const std::exception &e) {throw std::runtime_error("Invalid value - " + varToString(e.what()));}

	if (newValue < 0)
		throw std::out_of_range("Invalid value - not a positive number.");
	if (newValue > maxRange)
		throw std::out_of_range("Invalid value - too large a number.");
	return (newValue);
}


//*		||---- UTILITIES ----||

bool BitcoinExchange::isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isNotDuplicated(const std::string &str, const char c)
{
	if (str.find(c) != str.rfind(c))
		return (false);
	return (true);
}

bool BitcoinExchange::isFileEmpty(std::ifstream &file, std::string &buffer)
{
	if (!std::getline(file, buffer))
		return (true);
	return (false);
}

void BitcoinExchange::hasInvalidChar(const std::string &str, const std::string &chars)
{
	size_t invalidChar = str.find_first_not_of(chars);
	if (invalidChar != std::string::npos)
		throw std::runtime_error("Invalid character {'" + varToString(str[invalidChar]) + "'}");
}
