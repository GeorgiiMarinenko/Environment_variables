#include "../include/keyDetector.h"

keyDetector::keyDetector()
{
	textPath = "/Users/georgijmarinenko/Desktop/Programming/Vimpel/Task1-Map/text.txt";
}

keyDetector::~keyDetector()
{}

string *keyDetector::findKeyFromText() // Привинтивно расчитывать кол-во переменных окружения в файле
{
	string	*dictKeyStr = new string[1024];
	int		keyCounter = 0;
	fstream	outFile(textPath);
	char	symb;
	bool	dollarSymb = false;
	bool	firstBracket = false;

	if (!outFile.is_open())
	{
		cout << ">Reading error" << endl;
		return (0);
	}
	else
	{
		cout << ">Searching keys..." << endl;
		while (1)
		{
			symb = outFile.get();
			if (outFile.eof())
			{
				dictKeyStr[keyCounter] = "NULL";
				cout << ">end of searching" << endl;
				break;
			}
			else
			{
				if (symb == '$')
					dollarSymb = true;
				else if ((dollarSymb) && (symb == '('))
					firstBracket = true;
				else if ((dollarSymb) && (firstBracket) && (symb != '(') && (symb != ')'))
				{
					//чтение переменной...
					dictKeyStr[keyCounter] += symb;
				}
				if ((dollarSymb) && (firstBracket) && (symb == ')'))
				{
					dollarSymb = false;
					firstBracket = false;
					keyCounter++;
				}
			}
		}
	}
	int i = 0;
	while (dictKeyStr[i] != "NULL")
	{
		cout << "str: " << dictKeyStr[i] << endl;
		i++;
	}
	return (dictKeyStr);
}
