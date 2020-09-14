#include "Expression_Evaluation.h"

//Assume a paranthesis around entire expression: (ex(press(ion)))
//Assume expression has spacing between operators and values: (123 * (5 * -6))

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

	while (input[index] >= '0' && input[index] <= '9')
		value = value * 10 + (input[index++] - '0');

	return value * sign;
}

float expression_Evaluation(string input)
{
	int i = 0; //string index
	stack<float> value;
	stack<char> ops;

	while (input[i] != '\0')
	{
		if (input[i] == ')')
		{
			if (value.size() < 2 || ops.size() == 0)
				throw logic_error("Malformed expression");

			float val2 = value.top();
			value.pop();
			float val1 = value.top();
			value.pop();
			float result = 0;

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
			}
			ops.pop();
			value.push(result);
		}
		else
		{
			if ((input[i] == '-' && (input[i+1] >= '0' && input[i+1] <= '9'))
				|| (input[i] >= '0' && input[i] <= '9'))
				value.push(value_Helper(input, i));
			else if (input[i] == '+')	ops.push(input[i]);
			else if (input[i] == '-')	ops.push(input[i]);
			else if (input[i] == '*')	ops.push(input[i]);
			else if (input[i] == '/')	ops.push(input[i]);
		}

		i++;
	}

}