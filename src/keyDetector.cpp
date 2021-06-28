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

string *changeStr(int index, int keyCounter, string *str) //смещение части массива влево
{
	for (int i = index; i < keyCounter; i++)
		str[i] = str[i+1];
	return (str);
}

string keyDetector::findValueFromText(string str) //Используемая функция для выделения из строки ключа $(...)
{
	string	resStr;
	bool	dollarSymb = false;
	bool	firstBracket = false;
	int		i = 0;

	resStr.clear();
	str.c_str();
	while (str[i] != 0)
	{
		if (str[i] == '$')
			dollarSymb = true;
		else if ((dollarSymb) && (str[i] == '('))
			firstBracket = true;
		else if ((dollarSymb) && (firstBracket) && (str[i] != '(') && (str[i] != ')'))
			resStr.push_back(str[i]);
		if ((dollarSymb) && (firstBracket) && (str[i] == ')'))
		{
			dollarSymb = false;
			firstBracket = false;
			break;
		}
		i++;
	}
	resStr[i] = '\n';
	return (resStr);
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
				dictKeyStr[keyCounter] += symb;
			if ((dollarSymb) && (firstBracket) && (symb == ')'))
			{
				dollarSymb = false;
				firstBracket = false;
				keyCounter++;
			}
		}
	}
	for (int i = 0; i < (keyCounter - 1); i++)
	{
		// cout << " deb: " << dictKeyStr[i] << endl;
		for (int j = i + 1; j < keyCounter; j++)
		{
			if (dictKeyStr[i] == dictKeyStr[j])
			{
				dictKeyStr = changeStr(j, keyCounter, dictKeyStr);
				keyCounter--;
			}
		}
	}
	int i = 0;
	while (dictKeyStr[i] != "NULL")//Исправить массив строк на конец массива
	{
		cout << "str: " << dictKeyStr[i] << endl;
		i++;
	}
	return (dictKeyStr);
}
