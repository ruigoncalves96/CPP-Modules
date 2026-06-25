#include "RPN.hpp"
#include <string>
#include <exception>

RPN::RPN() {}

RPN::RPN(const RPN&obj) {(void)obj;}

RPN& RPN::operator=(const RPN&obj) {(void)obj; return(*this);}

RPN::~RPN() {}

int RPN::calculate(const std::string &expression)
{
	std::stack<int> valueStack;

	std::stringstream ss(expression);
	t_token token;
	while (ss >> token.str)
	{
		if (token.str.length() != 1)
			throw std::runtime_error("invalid input '" + token.str + "'");
		token.type = parseToken(token.str[0]);
		if (token.type == NUMBER)
			valueStack.push(stringToNumber<int>(token.str));
		else if (token.type == OPERATOR)
		{
			if (valueStack.size() < 2)
				throw std::runtime_error("not enough numbers for operator.");
			calcOperation(valueStack, token.str[0]);
		}
	}
	if (valueStack.empty())
		throw std::runtime_error("invalid input - empty expression.");
	if (valueStack.size() != 1)
		throw std::runtime_error("not enough operators for RPN.");
	return (valueStack.top());
}

t_tokenType RPN::parseToken(const char token)
{
	if (token >= '0' && token <= '9')
		return (NUMBER);
	if (token == '+' || token == '-' || token == '/' || token == '*')
		return (OPERATOR);
	throw std::runtime_error("invalid input '" + varToString(token) + "'");
}

void RPN::calcOperation(std::stack<int> &valueStack, const char op)
{
	int value2 = valueStack.top(); 
	valueStack.pop();
	int value1 = valueStack.top();
	valueStack.pop();

	if (op == '/' && value2 == 0)
		throw std::runtime_error("can't divide a value by 0.");

	switch (op)
	{
		case '+': valueStack.push(value1 + value2); break;
		case '-': valueStack.push(value1 - value2); break;
		case '/': valueStack.push(value1 / value2); break;
		case '*': valueStack.push(value1 * value2); break;
	
		default: break;
	}
}
