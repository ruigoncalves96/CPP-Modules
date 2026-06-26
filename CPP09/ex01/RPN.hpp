#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

typedef enum e_tokenType
{
	EMPTY,
	NUMBER,
	OPERATOR
}	t_tokenType;

typedef struct s_token
{
	std::string str;
	t_tokenType type;

	s_token() : type(EMPTY) {}
}	t_token;

class RPN
{
	public:
		static int calculate(const std::string &expression);

	private:
		RPN();
		RPN(const RPN&);
		RPN &operator=(const RPN&);
		~RPN();

		static t_tokenType parseToken(const char token);
		static void calcOperation(std::stack<long> &valueStack, const char op);
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
