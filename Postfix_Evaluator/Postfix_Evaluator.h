#ifndef POSTFIX_EVALUATOR_H
#define POSTFIX_EVALUATOR_H

#include <iostream>
#include <exception>
#include <string>
#include <stack>

using namespace std;

// Postfix_Evaluator Operators
// what if there is a negative integer input? -1 0 4 3 + +
// ~	Unary Operator
// !	Factorial Operator
// +	Addition Operator
// -	Subtraction Operator
// *	Multiplication Operator
// /	Division Operator

void unaryOp(stack<float> &s)
{
	if (s.empty())
		throw logic_error("Not enough operands");

	float temp = s.top() * static_cast<float>(-1);
	s.pop();
	s.push(temp);
}

void factorialOp(stack<float> &s)
{
	if (s.empty())
		throw logic_error("Not enough operands");

	float result = 1;
	float temp = s.top();
	s.pop();
	if (temp <= 0) {}
	else
		while (temp > 0)
		{
			result *= temp;
			temp--;
		}
	s.push(result);
}

void additionOp(stack<float>& s)
{
	if (s.size() < 2)
		throw logic_error("Not enough operands");

	float v2 = s.top();
	s.pop();
	float v1 = s.top();
	s.pop();
	s.push(v1 + v2);
}

void subtractionOp(stack<float>& s)
{
	if (s.size() < 2)
		throw logic_error("Not enough operands");

	float v2 = s.top();
	s.pop();
	float v1 = s.top();
	s.pop();
	s.push(v1 - v2);
}

void multiplicationOp(stack<float>& s)
{
	if (s.size() < 2)
		throw logic_error("Not enough operands");

	float v2 = s.top();
	s.pop();
	float v1 = s.top();
	s.pop();
	s.push(v1 * v2);
}

void divisionOp(stack<float>& s)
{
	if (s.size() < 2)
		throw logic_error("Not enough operands");

	float v2 = s.top();
	s.pop();
	if (v2 == 0)
		throw logic_error("Can not divide by zero");
	float v1 = s.top();
	s.pop();
	s.push(v1 / v2);
}

float postfix_Evaluator(string uInput)
{
	stack<float> s;

	for (unsigned int i = 0; i < uInput.size(); ++i)
	{
		if (uInput[i] == ' ') {}
		else if (uInput[i] >= '0' && uInput[i] <= '9')
		{
			s.push(uInput[i] - '0');
		}
		else if (uInput[i] == '-')
		{
			if (uInput[i + 1] >= '0' && uInput[i + 1] <= '9')
			{
				s.push(static_cast<float>(-1) * (uInput[i + 1] - '0'));
				++i; //bad practice but used to push index past numeric value
			}
			else
				subtractionOp(s);
		}
		else if (uInput[i] == '+')
		{
			if (uInput[i + 1] >= '0' && uInput[i + 1] <= '9')
			{
				s.push(uInput[i + 1] - '0');
				++i; 
			}
			else
				additionOp(s);
		}
		else if (uInput[i] == '~')	unaryOp(s);
		else if (uInput[i] == '!')	factorialOp(s);
		else if (uInput[i] == '*')	multiplicationOp(s);
		else if (uInput[i] == '/')	divisionOp(s);
		else
			throw logic_error("Unsupported operator");
	}

	if (s.size() != 1)
		throw logic_error("Malformed expression");

	return s.top();
}

#endif

