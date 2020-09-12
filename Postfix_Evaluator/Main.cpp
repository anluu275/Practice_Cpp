#include "Postfix_Evaluator.h"

#include <fstream>

void postfix_evaluator_text_file()
{
	ifstream txt;
	string txtInputstr;

	txt.open("inputs.txt");
	if (txt.is_open())
	{
		while (getline(txt, txtInputstr))
		{
			cout << txtInputstr << " = ";
			try
			{
				cout << postfix_Evaluator(txtInputstr) << endl;
			}
			catch (exception& ex)
			{
				cout << ex.what() << endl;
			}
		}
	}
	txt.close();
}

int main()
{
	postfix_evaluator_text_file();
}

