#include "Expression_Evaluation.h"

#include <fstream>
#include <exception>

void expression_Evaluation_Test()
{
	ifstream txt;
	string input;

	txt.open("expression.txt");
	if (txt.is_open())
	{
		while (getline(txt, input))
		{
			cout << input << " = ";
			try
			{
				cout << expression_Evaluation(input) << endl;
			}
			catch (exception& ex)
			{
				cout << ex.what() << endl;
			}
		}
		txt.close();
	}
	else
		cout << "text file failed to open.";
}

int main()
{
	expression_Evaluation_Test();
}
