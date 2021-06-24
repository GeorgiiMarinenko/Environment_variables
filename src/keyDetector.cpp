#include "../include/keyDetector.h"

keyDetector::keyDetector()
{
	textPath = "/Users/georgijmarinenko/Desktop/Git/Environment_variables/text.txt";
}

keyDetector::~keyDetector()
{}

int		keyDetector::keysCounterFromFile()
{
	fstream	outFile(textPath);
	char	symb;
	bool	dollarSymb = false;
	bool	firstBracket = false;
	bool	insideKey = false; //внутри самой переменной
	bool	firstEntry = true;
	int		keyCounter = 0;

	if (!outFile.is_open())
	{
		cout << ">Reading error" << endl;
		return (0);
	}
	else
	{
		while (1)
		{
			symb = outFile.get();
			if (outFile.eof())
			{
				break;
			}
			else
			{
				if (symb == '$')
					dollarSymb = true;
				else if ((dollarSymb) && (symb == '('))
					firstBracket = true;
				else if ((dollarSymb) && (firstBracket) && symb != ')')
					insideKey = true;
				else if ((dollarSymb) && (firstBracket) && (insideKey) && (firstEntry))
					firstEntry = false;
				if ((dollarSymb) && (firstBracket) && (symb == ')'))
				{
					firstEntry = true;
					dollarSymb = false;
					firstBracket = false;
					insideKey = false;
					keyCounter++;
				}
			}
		}
	}
	keyCounter++; //Для дополнительной строки окончания массива
	cout << "Counter: " << keyCounter <<  endl;
	return (keyCounter);
}

string *changeStr(int index, int keyCounter, string *str)
{
	for (int i = index; i < keyCounter; i++)
	{
		str[i] = str[i+1];
	}
	return (str);
}

string	*keyDetector::findKeyFromText()
{
	string	*dictKeyStr = new string[keyDetector::keysCounterFromFile()];
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
	cout << "1KC: " << keyCounter << "\n";
	for (int i = 0; i < (keyCounter - 1); i++)
	{
		cout << " deb: " << dictKeyStr[i] << endl;
		for (int j = i + 1; j < keyCounter; j++)
		{
			if (dictKeyStr[i] == dictKeyStr[j])
			{
				dictKeyStr = changeStr(j, keyCounter, dictKeyStr);
				keyCounter--;
				cout << "KC: " << keyCounter << "\n";
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
