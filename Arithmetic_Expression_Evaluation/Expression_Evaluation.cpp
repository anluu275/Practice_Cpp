#include "Expression_Evaluation.h"

//Assume a paranthesis around entire expression: (ex(press(ion)))
//Assume expression has spacing between operators and values: (-123.456 * (7 * -8))

// TO-DO LIST
//Handle overflow or underflow of float value

static float value_Helper(string input, int& index)
{
	float sign = 1;
	float value = 0;

	if (input[index] == '-') 
	{
		sign = -1;
		index++;
	}

	while (input[index] >= '0' && input[index] <= '9' || input[index] == '.')
	{
		if (input[index] == '.')
		{
			index++;
			float decimal = 10;

			while (input[index] >= '0' && input[index] <= '9')
			{
				value = value + ((input[index++] - '0') / decimal);
				decimal *= 10;
			}
		}
		else
			value = value * 10 + (input[index++] - '0');
	}

	return value * sign;
}

static void ops_Helper(stack<float> &value, stack<char> &ops)
{
	if (value.size() < 2 || ops.size() == 0)
		throw logic_error("Malformed expression");

	float val2 = value.top();
	value.pop();
	float val1 = value.top();
	value.pop();
	float result = 0; //used for switch case 

	switch (ops.top())
	{
	case '*':
		result = val1 * val2;
		break;
	case '+':
		result = val1 + val2;
		break;
	case '-':
		result = val1 - val2;
		break;
	case '/':
		if (val2 == 0)
			throw logic_error("Can not divide by zero");
		result = val1 / val2;
		break;
	default:
		throw logic_error("Invalid Operator");
	}
	ops.pop();
	value.push(result);
}

float expression_Evaluation(string input)
{
	int i = 0; //string index
	stack<float> value;
	stack<char> ops;

	while (input[i] != '\0')
	{
		if (input[i] == ')')
			ops_Helper(value, ops);
		else
		{
			if ((input[i] == '-' && (input[i+1] >= '0' && input[i+1] <= '9'))
				|| (input[i] >= '0' && input[i] <= '9'))
				value.push(value_Helper(input, i));
			else if (input[i] != ' ' && input[i] != '(')
				ops.push(input[i]);
		}
		i++;
	}

	while (!ops.empty())
		ops_Helper(value, ops);

	if (value.size() != 1)
		throw logic_error("Malformed Expression");

	return (value.top());
}