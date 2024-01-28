#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &obj)
{
	*this = obj;
}

RPN &RPN::operator=(const RPN &obj)
{
	if (this == &obj)
		return *this;
	std::stack<int> tmpStack = obj.mystack;
	this->mystack.swap(tmpStack);
	return *this;
}

RPN::~RPN(){}

int	RPN::checkOperator(int first, int second, char oper)
{
	if (oper == '+')
		return (first + second);
	else if (oper == '*')
		return (first * second);
	else if (oper == '/')
	{
		if (second == 0)
			throw "ERROR";
		return (first / second);
	}
	return (first - second);
}



void RPN::CalculateRpnOperation(std::string str)
{
	int i = 0;
	int num1;

	while (str[i])
	{
		if (isdigit(str[i]) || (str[i] == '-' && isdigit(str[i + 1])))
		{
			if (str[i] == '-')
				i++;
			if (str[i + 1] == ' ')
			{
				str[i - 1] == '-' ? mystack.push(atoi(&str[i]) * -1) : mystack.push(atoi(&str[i]));
				i += 2;
				continue;
			}
			else if (strchr("+-*/", str[i + 1]))
				str[i - 1] == '-' ? mystack.push(atoi(&str[i]) * -1) : mystack.push(atoi(&str[i]));
			else
				throw "ERROR";
		}
		else if (strchr("+-*/", str[i]) && mystack.size() > 1)
		{
			num1 = mystack.top();
			mystack.pop();
			int result = this->checkOperator(mystack.top(), num1, str[i]);
			mystack.pop();
			mystack.push(result);
		}
		else if (str[i] == ' ')
		{
			i++;
			continue;
		}
		else
			throw "ERROR";
		i++;
	}
	if (mystack.size() == 1)
		std::cout << mystack.top() << "\n";
	else
		throw "ERROR";
}
